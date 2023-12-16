from collections import defaultdict
import numpy 


def solve():
    graph = defaultdict(list)
    graph['btn'] = ['broadcaster']
    type = dict()
    state = dict()
    parentPulse = defaultdict(dict)
    highSignals = defaultdict(lambda: 0)
    
    def bfs():
        press = 0
        parents = parentPulse['zp'].keys()
        cycles_lengths = {}
        while len(cycles_lengths) < len(parents):
            press += 1
            queue = [('btn', 0)]
            while len(queue) > 0:
                parent, signal = queue.pop(0)

                for child in graph[parent]:
                    #stupid test :) i just visualized the input and find a cycle for each parent
                    """
                    3733 ds 0
                    3797 sb 0
                    3797 sb 0
                    3877 hf 0
                    3877 hf 0
                    3877 hf 0
                    3877 hf 0
                    3917 nd 0
                    3917 nd 0
                    3917 nd 0
                    3917 nd 0
                    7466 ds 0
                    7594 sb 0
                    7594 sb 0
                    7754 hf 0
                    7754 hf 0
                    7754 hf 0
                    7754 hf 0
                    7834 nd 0
                    7834 nd 0
                    7834 nd 0
                    7834 nd 0
                    11199 ds 0
                    11391 sb 0
                    11391 sb 0
                    11631 hf 0
                    11631 hf 0
                    11631 hf 0
                    11631 hf 0
                    11751 nd 0
                    11751 nd 0
                    11751 nd 0
                    11751 nd 0
                    14932 ds 0
                    15188 sb 0
                    15188 sb 0
                    15508 hf 0
                    15508 hf 0
                    15508 hf 0
                    15508 hf 0
                    15668 nd 0
                    15668 nd 0
                    15668 nd 0
                    15668 nd 0
                    18665 ds 0
                    18985 sb 0
                    18985 sb 0
                    19385 hf 0
                    19385 hf 0
                    19385 hf 0
                    19385 hf 0
                    19585 nd 0
                    19585 nd 0
                    19585 nd 0
                    19585 nd 0
                    22398 ds 0
                    22782 sb 0
                    22782 sb 0
                    23262 hf 0
                    23262 hf 0
                    23262 hf 0
                    23262 hf 0
                    23502 nd 0
                    23502 nd 0
                    23502 nd 0
                    23502 nd 0
                    26131 ds 0
                    """
                    if child == 'zp':
                        for p, pulse in parentPulse[child].items():
                            if pulse and p not in cycles_lengths:
                                cycles_lengths[p] = press

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

        return numpy.lcm.reduce(list(cycles_lengths.values()))


    with open("/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day20/a.txt", "r") as file:
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