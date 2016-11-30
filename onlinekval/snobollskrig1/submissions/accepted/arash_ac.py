"""
Arash AC(100) solution to snobollskastning1
"""
import sys
import collections
import heapq


def main():
    stdin_lines = []
    for line in sys.stdin:
        if line.strip() != "":
            stdin_lines.append(line.strip())

    # parse step 1
    n, l, _m = map(int, stdin_lines[0].split())
    # parse step 2
    start_positions = list(map(int, stdin_lines[1:l+1]))
    # parse step 3
    graph = collections.defaultdict(list)
    Edge = collections.namedtuple('Edge', 'dest weight')
    for line in stdin_lines[l+1:]:
        v1, v2, w = map(int, line.split())
        e1 = Edge(v2, w)
        e2 = Edge(v1, w)
        graph[v1].append(e1)
        graph[v2].append(e2)
    # Done parsing, start solving
    answer = solve(start_positions, graph)
    for (a, b) in answer:
        print(a, b)


def solve(start_positions, graph):
    answer = set()
    heap = [(0, node_ix, country_ix) for (country_ix, node_ix) in enumerate(start_positions)]
    heapq.heapify(heap)
    owner_map = {}
    while heap:
        (t0, v0, c0) = heapq.heappop(heap)
        if v0 in owner_map:
            # Not needed as they will have attacked us already
            # answer.append(set((c0, owner_map[v0])))
            continue
        owner_map[v0] = c0
        for edge in graph[v0]:
            if edge.dest in owner_map:
                # It's a conquered node, lets attack unconditionally
                answer.add(frozenset((c0, owner_map[edge.dest])))
            else:
                # It's free to try to reach
                heapq.heappush(heap, (t0 + edge.weight, edge.dest, c0))
    return (sorted(x) for x in answer if len(x) > 1)


if __name__ == '__main__':
    main()
