import math

n = int(input())

balls = [(int(mass), i+1) for i, mass in enumerate(input().split())]
balls.sort(reverse=True)

circles = []
c = int(input())
for i in range(c):
    x, y, r = [int(x) for x in input().split()]
    d = abs(math.sqrt(x**2 + y**2) - r)
    circles.append((d, i+1))

circles.sort()

i = 0
l = len(circles)
ans = []
for ball in balls:
    if i == l:
        break
    
    m, bi = ball
    d, ci = circles[i]
    if d <= math.sqrt(1e6/m):
        ans.append(f"{bi} {ci}")
        i += 1
    
print(len(ans))
for a in ans:
    print(a)