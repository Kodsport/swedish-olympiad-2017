#!/usr/bin/python

# TODO: kopierad från spotifyconnect, redigera för snöbollskrig

import sys
import random

def main():
    seed = int(sys.argv[1])
    extra_ms = int(sys.argv[2])  # 200 for easy case, 0 for hard
    random.seed(seed)

    n = random.randrange(1, 1000, 1)

    print n
    last_timestamp = 300

    for i in range(n):
        d_timestamp = random.randrange(1, 200, 1) + extra_ms
        d_timestamp += d_timestamp == 100  # 100 is illegal, then use 101
        timestamp = last_timestamp + d_timestamp
        device = random.choice(('mobile', 'laptop'))
        action = random.choice(('play', 'paus'))
        if i == n-1:
          action = 'paus'
        timestamp_str = str(timestamp).rjust(7, '0')
        line = '{0} {1} {2}'.format(timestamp_str, device, action)
        print line
        last_timestamp = timestamp

if __name__ == "__main__":
    main()
