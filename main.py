a = input()
b = input()
sm = int(input())

valid = 0

for base in range(200):
    try:
        if (int(a, base) + int(b, base)) == sm:
            res = base
            valid += 1
    except:
        pass

if valid == 1:
    print(res)
else:
    print(0)