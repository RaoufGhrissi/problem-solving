#https://codeforces.com/group/YTYmnVxV00/contest/104805/problem/G

n = int(input())

lastTime = 23*3600 + 59*60 + 59
l = lastTime + 1
cum = [0] * l

for i in range(n):
    s = input()
    t1, t2 = s.split()
    h, m, s = [int(x) for x in t1.split(":")]
    h1, m1, s1 = [int(x) for x in t2.split(":")]
    sec1 = s + 60*m + 3600*h
    sec2 = s1 + 60*m1 + 3600*h1

    if sec2 < sec1:
        cum[sec1] += 1
        cum[0] += 1
        cum[sec2] -= 1       
    else:
        cum[sec1] += 1
        cum[sec2] -= 1

for i in range(1, l):
    cum[i] += cum[i-1]

print(len([x for x in cum if x == 0]))