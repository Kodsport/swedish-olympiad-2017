#!/usr/bin/env python3
import statistics
import operator
import heapq

n = int(input())

grade = {}
contestants = []
contests = [[] for x in range(0, 4)]

for i in range(0, n):
    line = input().split()
    name = line[0]
    contestants.append(name)
    grade[name] = int(line[1])
    for j in range(0, 4):
        contests[j].append( (name, int(line[2+j])) )

normalized = {contestant: [] for contestant in contestants}


for contest in contests:
    scores = [x[1] for x in contest]
    highest = max(scores)
    med = statistics.median(scores)
    
    for name, score in contest:
        normalized[name].append(50.0 * score / med if score <= med else 50.0 + 50.0 * (score-med) / (highest-med))

#print('\n'.join(map(str, normalized.items())))

total = {name: normalized[name][0] + sum(heapq.nlargest(2, normalized[name][1:4])) for name in contestants}
#print(total)
final = [x[0] for x in sorted(total.items(), key=operator.itemgetter(1), reverse=True)] # + '_' + str(x[1])
#print(final)

print('{} {} {} {}'.format(*sorted(final[0:4])))
print('{} {}'.format(*sorted([name for name in final[4:] if grade[name] != 3][0:2])))