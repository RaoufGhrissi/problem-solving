from collections import defaultdict

def solve():
    ans = 1e9
    seeds = []
    convert = defaultdict(list)

    with open("a.txt", "r") as file:
        ans = 1
        time = []
        for line in file:
            line = line.strip()
            if line.startswith('Time: '):
                time = line.split(':')[1].split()
                continue

            dist = line.split(':')[1].split()

            n = len(time)
            for i in range(n):
                t = int(time[i])
                d = int(dist[i])
                tot = 0
                for hold in range(t):
                    if hold*(t-hold) > d:
                        tot += 1

                ans *= tot

    return ans

if __name__ == "__main__":
    print(solve())
