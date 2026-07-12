import time, random

n= 1000
a=[random.randint(-20, 21) for i in range(n)]

m= -1e9
start= time.time()
dp= [0] * n
dp[0]= a[0]
for i in range(1, n):
    dp[i]= max(dp[i-1]+a[i], a[i])

print(max(dp))
print(time.time()-start)