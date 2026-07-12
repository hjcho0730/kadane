import time, random

n= 100000
a=[random.randint(-20, 21) for i in range(n)]

print("배열 크기: ", n)

#############################
print("#############################")
print("O(L) 시간복잡도      ##카데인 알고리즘(최적) + 공간 복잡도 최적화##")
m= -1e9
start= time.time()
c= a[0]
for i in range(1, n):
    c= max(c+a[i], a[i])
    m= max(m, c)
print("결과:", m, "||",time.time()-start, "초")
#############################
print("#############################")
print("O(L) 시간복잡도      ##카데인 알고리즘(최적)##")
m= -1e9
start= time.time()

dp= [0] * n
dp[0]= a[0]
for i in range(1, n):
    dp[i]= max(dp[i-1]+a[i], a[i])
m= max(dp)
print("결과:", m, "||",time.time()-start, "초")
#############################
print("#############################")
print("O(L^2) 시간복잡도")
m= -1e9
start= time.time()
for i in range(n):
    s= 0
    for j in range(i, n):
        s+= a[j]
        m= max(s, m)
print("결과:", m, "||",time.time()-start, "초")
#############################
print("#############################")
print("O(L^3) 시간복잡도")
m= -1e9
start= time.time()
for i in range(n):
    for j in range(i, n):
        m= max(sum(a[i:j+1]), m)
print("결과:", m, "||",time.time()-start, "초")
print("#############################")