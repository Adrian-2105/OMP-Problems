cases = int(input())
for i in range(cases):
    pos = int(input())
    pos = pos - 1
    for i in range(0, 19):
        for j in range(0, 19):
            if pos%3 == 0:
                print('.', end='')
            elif pos%3 == 1:
                print('W', end='')
            elif pos%3 == 2:
                print('B', end='')
            pos = pos // 3
        print()
    print()
