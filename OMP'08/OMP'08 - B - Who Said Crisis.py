casos = int(input())
for i in range(casos):
    line = input()
    a, b = line.split(" ")[0], line.split(" ")[1]
    print(int(a) - int(b))
