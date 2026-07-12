import time, random

n= 1000
a=[random.randint(-20, 21) for i in range(n)]

m= -1e9
start= time.time()
for i in range(n):
    s= 0
    for j in range(i, n):
        s+= a[j]
        m= max(s, m)

print(m)
print(time.time()-start)