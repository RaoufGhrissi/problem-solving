from collections import defaultdict

def solve():
   graph = defaultdict(list)
   graph['btn'] = ['broadcaster']
   type = dict()
   state = dict()
   parentPulse = defaultdict(dict)
   highSignals = defaultdict(lambda: 0)

   def bfs():
        high = 0
        low = 0
        n = 1000
        while n>0:
            queue = [('btn', 0)]
            while len(queue) > 0:
                parent, signal = queue.pop(0)

                for child in graph[parent]:
                    if signal:
                        high += 1
                    else:
                        low += 1

                    if child in type and type[child] == '%':
                        if signal:
                            continue

                        state[child] = not state[child]
                        nextSignal = int(state[child])
                    elif child in type and type[child] == '&':
                        oldSignal = parentPulse[child][parent]
                        parentPulse[child][parent] = signal

                        if not oldSignal and signal:
                            highSignals[child] += 1
                        elif oldSignal and not signal:
                            highSignals[child] -= 1

                        nextSignal = int(highSignals[child] != len(parentPulse[child]))
                    else:
                        nextSignal = signal

                    queue.append((child, nextSignal))
            n -= 1

        return high*low     

   with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day19/a.txt", "r") as file:
        for line in file:
            line = line.strip()
            frm, to= line.split(' -> ')

            if frm.startswith('%'):
                frm = frm[1:]
                type[frm] = '%'
                state[frm] = 0
            elif frm.startswith('&'):
                frm = frm[1:]
                type[frm] = '&'

            for child in to.split(', '):
                graph[frm].append(child)
                parentPulse[child][frm] = 0
                
        return bfs()
   
print(solve())