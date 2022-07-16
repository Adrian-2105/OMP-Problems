casos = int(input())

fact = [1]
for i in range(1, 45):
    fact.append(fact[i-1] * i)

for i in range(casos):
    n = int(input())

    sum = 0
    for i in range(0, n+1, 2):
        sum += fact[n] // (fact[i//2] * fact[i//2] * fact[n - i if n - i >= 0 else 0])

    print(int(sum))