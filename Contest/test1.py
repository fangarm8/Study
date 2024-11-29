def parse_intervals(s):
    result = []
    parts = s.split(',')
    
    for part in parts:
        if '-' in part:
            start, end = map(int, part.split('-'))
            result.extend(range(start, end + 1))
        else:
            result.append(int(part))

    result.sort()
    
    print(" ".join(map(str, result)))

s = input()
parse_intervals(s)