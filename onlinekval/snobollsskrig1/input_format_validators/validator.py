import re
import sys

def main():
    time_regex = "\d" * 7
    device_regex = "(laptop|mobile)"
    action_regex = "(play|paus)"
    line_regex = "^" + " ".join((time_regex, device_regex, action_regex))  + "$"

    int_regex = "(0|[1-9][0-9]*)"
    line = sys.stdin.readline()
    assert re.match(int_regex, line)
    n = int(line)

    assert 1 <= n < 1000

    last_timestamp = -101
    for _ in range(n):
        line = sys.stdin.readline()
        assert re.match(line_regex, line)
        timestamp = int(line.split()[0])
        assert timestamp > last_timestamp and timestamp - last_timestamp != 100
        last_timestamp = timestamp

    line = sys.stdin.readline()
    assert len(line) == 0

    sys.exit(42)

main()
