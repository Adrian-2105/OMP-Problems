from math import sqrt, floor


num = input()
while num != "0":
    long = len(num)
    if long % 2 == 0:
        res = floor(sqrt(int(num[0:2])))
        long = long - 2
    else:
        res = floor(sqrt(int(num[0])))
        long  = long - 1
    print(res, end='')
    for i  in range(0, int(long/2)):
        print(0, end='')
    print()
    num = input()
