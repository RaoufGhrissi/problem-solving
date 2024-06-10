from collections import defaultdict

def solve():
    ans = 0
    boxes = defaultdict(dict)

    def compute(part: str):
        res = 0
        for c in part:
            res += ord(c)
            res *= 17
            res %= 256

        return res

    with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day15/a.txt", "r") as file:
        for line in file:
            line = line.strip()
            parts = line.split(',')
            
            for part in parts:
                if '=' in part:
                    text = part.split('=')[0]
                    x = int(part.split('=')[1])
                    id = compute(text)
                    boxes[id][text] = x
                else:
                    text = part.split('-')[0]
                    id = compute(text)
                    if id in boxes and text in boxes[id]:
                        del boxes[id][text]

        for box, slots in boxes.items():
            slot_id = 0
            for x in slots.values():
                slot_id += 1
                ans += (box+1)*slot_id*x

    return ans

if __name__ == "__main__":
    print(solve())
