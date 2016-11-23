import sys
import collections

data = []

for line in sys.stdin:
    if line.strip() != "":
        data.append(line.strip())

N, K = map(int, data[0].split())

ok_pos_for_letter = collections.defaultdict(lambda: lambda x: True)
must_be_before = collections.defaultdict(lambda: lambda c: True)

for i in range(1, K+1):
    char = line[0]
    form = line[1]

    if form == '@':
        # exempel: C@01,05,12
        nums_commas = line[2:]
        nums = map(int, nums_commas.split(','))
        nums = map(lambda x: x-1, nums)
        ok_pos_for_letter[char] = lambda x: x in nums
    else:
        # exempel: B:DEF
        assert form == ':'
        chars = line[2:]
        must_be_before[char] = lambda c: c in chars

end_char = chr(ord('A') + N)


def go(char_arr, char):
    if char == end_char:
        print(''.join()
        return 1
    ans = 0
    for i in range(N):
        if not char_arr[i]:
            ok = True
            ok = ok and ok_pos_for_letter[char](i)
            if i+1 < N and char_arr[i+1]:
                other_char = char_arr[i+1]
                ok = ok and must_be_before[char](other_char)
            if i-1 >= 0 and char_arr[i-1]:
                other_char = char_arr[i-1]
                ok = ok and must_be_before[other_char](char)
            if ok:
                char_arr[i] = char
                ans += go(char_arr, chr(ord(char) + 1))
                char_arr[i] = None
    return ans

ans = go([None] * N, 'A')
print(ans)
