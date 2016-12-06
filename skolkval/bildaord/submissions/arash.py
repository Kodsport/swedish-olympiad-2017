import sys

DEBUG = True

data = []

for line in sys.stdin:
    if line.strip() != "":
        data.append(line.strip())

N, K = map(int, data[0].split())

valid_chars = 'ABCDEFGHIJKLMNOPQ'[0:N]
end_char = chr(ord('A') + N)
ok_pos_for_letter = {c0: range(N) for c0 in valid_chars}
must_be_before = {c0: valid_chars + end_char for c0 in valid_chars}

for i in range(1, K+1):
    line = data[i]
    char = line[0]
    form = line[1]

    if form == '@':
        # exempel: C@01,05,12
        nums_commas = line[2:]
        nums = map(int, nums_commas.split(','))
        nums = map(lambda x: x-1, nums)
        ok_pos_for_letter[char] = nums
    else:
        # exempel: B:DEF
        assert form == ':'
        chars = line[2:]
        must_be_before[char] = chars


if DEBUG:
    from pprint import pprint
    pprint(ok_pos_for_letter)
    pprint(must_be_before)


def valid_so_far(char_arr):
    for i in range(N):
        char = char_arr[i]
        if char:
            if i not in ok_pos_for_letter[char]:
                return False
            after_char = char_arr[i+1]
            if after_char:
                if after_char not in must_be_before[char]:
                    return False
    return True


def go_check_all(char_arr, char):
    if char == end_char:
        if valid_so_far(char_arr):
            if DEBUG:
                print(''.join(char_arr[0:-1]))
            return 1
    ans = 0
    for i in range(N):
        if not char_arr[i]:
            char_arr[i] = char
            if valid_so_far(char_arr):
                ans += go_check_all(char_arr, chr(ord(char) + 1))
            char_arr[i] = None
    return ans


# THIS ONE IS WRONG, Tankefel
def go_check_minimally(char_arr, char):
    if char == end_char:
        if DEBUG:
            print(''.join(char_arr[0:-1]))
        return 1
    ans = 0
    for i in range(N):
        if not char_arr[i]:
            ok = True
            ok = ok and i in ok_pos_for_letter[char]
            if i+1 and char_arr[i+1]:
                other_char = char_arr[i+1]
                ok = ok and other_char in must_be_before[char]
            if i-1 >= 0 and char_arr[i-1]:
                other_char = char_arr[i-1]
                ok = ok and char in must_be_before[other_char]
            if ok:
                char_arr[i] = char
                ans += go_check_minimally(char_arr, chr(ord(char) + 1))
                char_arr[i] = None
    return ans

start_arr = ([None] * N) + [end_char]
ans = go_check_minimally(start_arr, 'A')
print(ans)
start_arr = ([None] * N) + [end_char]
ans2 = go_check_all(start_arr, 'A')
if DEBUG:
    print(ans2)
assert ans == ans2
