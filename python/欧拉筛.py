l = int(input())
r = int(input())
vis = [0] * (r + 1)
primes = []
for i in range(2, r): # 枚举 (p1^c1-1 * p2^c2 * ... * pk^ck) 枚举x / 枚举p1 (最小质因子)
    if not vis[i]:
        primes.append(i)
    for prime in primes: # 枚举 p1 (最小质因子)
        if i * prime > r:
            break
        vis[i * prime] = True
        if i % prime == 0:
            break
for prime in primes:
    if prime >= l and prime <= r:
        print(prime)