a = input()
b = input()
sm = input()

valid = 0

for base in range(200):
    try:
        if (int(a, base) + int(b, base)) == int(sm, base):
            res = base
            valid += 1
    except:
        pass

if valid == 1:
    print(res)
else:
    print(0)