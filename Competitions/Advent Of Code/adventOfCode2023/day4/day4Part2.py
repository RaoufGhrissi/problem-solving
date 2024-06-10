def solve():
    ans = 0
    card = 0
    occ = {}

    with open("a.txt", "r") as file:
        for line in file:
            game = line.split(": ")
            card = int(game[0].split()[1])
            occ[card] = occ.get(card, 0) + 1

            game = game[1].split(" | ")
            st = set(int(part) for part in game[0].split() if part.strip())
            
            cnt = sum(1 for part in game[1].split() if part.strip() and int(part) in st)

            for i in range(1, cnt + 1):
                occ[card + i] = occ.get(card + i, 0) + occ[card]

    for a in occ:
        if a <= card:
            ans += occ[a]

    return ans

if __name__ == "__main__":
    print(solve())
