n = int(input())
X = []
Y = []
for _ in range(n):
    xx, yy = map(int, input().split())
    X.append(xx)
    Y.append(yy)

ans = 0
for i in range(n):
    for j in range(i+1, n):
        p = (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j])
        if p > ans:
            ans = p

print(ans**(1/2))
