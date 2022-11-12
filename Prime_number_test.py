def prime(x):
    lst = []
    for i in range(1, x+1):
        if x % i == 0:
            lst.append(i)
    if len(lst) == 2:
        print("prime number~")
    else:
        print("no prime!")