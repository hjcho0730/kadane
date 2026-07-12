import time, random

n= 1000
a=[random.randint(-20, 21) for i in range(n)]

m= -1e9
start= time.time()
for i in range(n):
    for j in range(i, n):
        m= max(sum(a[i:j+1]), m)

print(m)
print(time.time()-start)