from collections import defaultdict, Counter
from functools import cmp_to_key

typePerLength = {
    1: 7,
    2: 5,
    3: 3,
    4: 2,
    5: 1,
}

def getType(s: str):
    occ = Counter(s)
    
    jOcc = 0
    if 'J' in occ:
        jOcc = occ.pop('J')

    if len(occ) == 0:
        return 7
    
    mostOcc = occ.most_common(1)[0]
    most = mostOcc[1] + jOcc
    l = len(occ)
    if l == 2 and most == 4:
        return 6
    elif l == 3 and most == 3:
        return 4
    else:
        return typePerLength[l]

def solve():
    ans = 0
    charsOrder = {key: i for i, key in enumerate(['A', 'K', 'Q', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2', 'J'])}
    
    def compareCamels(a, b):
        n = len(a)
        for i in range(n):
            x = a[i]
            y = b[i]

            if x == y:
                continue
            
            return 1 if charsOrder[x] < charsOrder[y] else -1
            
        return 1

    def compare(x, y):
        if x[1] == y[1]:
            return compareCamels(x[0], y[0])

        return 1 if x[1] > y[1] else -1

    with open("a.txt", "r") as file:
        camelType = {}
        camelBid = {}

        for line in file:
            line = line.strip()
            camel, bid = line.split()
            camelBid[camel] = int(bid)
            camelType[camel] = getType(camel)
    
        camelType = dict(sorted(camelType.items(), key=cmp_to_key(compare)))

        rank = 1
        for camel in camelType:
            ans += camelBid[camel]*rank
            rank += 1

    return ans

if __name__ == "__main__":
    print(solve())
