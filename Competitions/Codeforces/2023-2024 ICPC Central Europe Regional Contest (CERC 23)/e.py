from collections import defaultdict

l1 = defaultdict(int)
l2 = defaultdict(int)

sep = False

while True:
    line = input()
    if line == "======":
        break

    if line == "------":
        sep = True
        continue

    s, e, p = line.split()
    s, e = int(s), int(e)
    if sep:
        l2[p] += e-s
    else:
        l1[p] += e-s

l = list(l2.keys())

for p in l1:
    if p not in l2:
        l.append(p)

l.sort()

sep = False
for p in l:
    if l1[p] != l2[p]:
        diff = l2[p]-l1[p]
        if diff != 0:
            sep = True
            print(f'{p} {"+" if diff > 0 else ""}{diff}')

if not sep:
    print("No differences found.")