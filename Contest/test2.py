def restore_snow_depth(n, a):
    snow_depth = [0] * n
    
    for i in range(n):
        if a[i] != -1:
            snow_depth[i] = a[i]

    last_known_index = -1
    for i in range(n):
        if a[i] != -1:
            if last_known_index == -1:
                if i>=a[i]:
                    print("NO")
                    return
                for j in range(i):
                    snow_depth[j] = 1
                snow_depth[i] = a[i] - i
            else:
                diff = a[i] - a[last_known_index]
                days_between = i - last_known_index
                if diff < days_between:
                    print("NO")
                    return
                increment = diff // days_between
                remainder = diff % days_between
                for j in range(last_known_index + 1, i + 1):
                    snow_depth[j] = increment + (1 if remainder > 0 else 0)
                    remainder -= 1
            last_known_index = i
    
    if last_known_index != n - 1:
        for i in range(last_known_index + 1, n):
            snow_depth[i] = snow_depth[i-1] + 1

    print("YES")
    print(" ".join(map(str, snow_depth)))

n = int(input())
a = list(map(int, input().split()))

restore_snow_depth(n, a)
