def fibonacci(n, k):
    if(n == 0):
        return 0
    elif (n == 1):
        return 1
    else:
        return fibonacci(n-1, k) + k*fibonacci(n-2, k)

months, litter = map(int, input().split())

total = fibonacci(months, litter)
print(total)