import sys

total_score = 0
verdicts = []
for line in sys.stdin.readlines():
    verdict, score = line.split()
    total_score += float(score)
    if verdict != 'AC':
        verdicts.append(verdict)
verdicts.append('AC')
total_score = min(100, total_score)

if total_score > 0:
    verdict = "AC"
else:
    verdict = verdicts[0]
print("%s %f" % (verdict, total_score))
