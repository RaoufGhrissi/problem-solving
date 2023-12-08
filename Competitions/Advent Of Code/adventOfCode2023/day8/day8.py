
from collections import defaultdict
import numpy 

def solve():
    graph = defaultdict(map)
    s: str

    with open("a.txt", "r") as file:
        
        for i, line in enumerate(file):
            line = line.strip()
            if line == '':
                continue

            if (i==0):
                s = line
                n = len(s)
                continue
            
            line = line.split(' = ')
            src = line[0]
            dest = line[1].split(', ')
            l = dest[0][1:]
            r = dest[1][:len(dest[1])-1]

            graph[src] = {
                "L": l,
                "R": r,
            }

    #This solution is assuming that all cycle are of format A..ZA...A..Z
    #but it's not the case and i can't get how it's working. The test case is wrong by made
    #in a way that it should work because there are cycles where Z was in the middle
    #Example: A B Z C
    #Z appears after 2 steps then after 6 steps then after 10 steps so LCM shouldn't work
    parents = [src for src in graph.keys() if src.endswith("A")]
    steps = {}
    for parent in parents:
        steps[parent] = 0
        i = 0
        node = parent
        while(True):
            if node.endswith("Z"):
                print(parent, node)
                break
        
            if i==len(s):
                i=0
            
            steps[parent] += 1
            node = graph[node][s[i]]
            i += 1

    return numpy.lcm.reduce(list(steps.values()))

if __name__ == "__main__":
    print(solve())
