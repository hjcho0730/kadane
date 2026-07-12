import time, random

n= 1000
a=[random.randint(-20, 21) for i in range(n)]

m= -1e9
start= time.time()
c= a[0]
for i in range(1, n):
    c= max(c+a[i], a[i])
    m= max(m, c)

print(m)
print(time.time()-start)