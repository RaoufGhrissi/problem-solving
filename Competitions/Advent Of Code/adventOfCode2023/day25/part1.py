from collections import defaultdict
import sys
sys.setrecursionlimit(10**9)
import networkx as nx

class BridgesByTarjan:
    def __init__(self):
        self.graph = defaultdict(list)
        self.deleted = []
        self.load()

    def load(self):
        self.time = 0
        self.disc = {}
        self.low = {}
        self.vis = set()
        self.bridges = []
        self.parent = {}

    def add(self, a, b):
        self.graph[a].append(b)
        self.graph[b].append(a)

    def dfs(self, node):
        self.vis.add(node)
        self.disc[node] = self.time
        self.low[node] = self.time
        self.time += 1

        for child in self.graph[node]:
            if (child, node) in self.deleted or (node, child) in self.deleted:
                continue

            if child not in self.vis:
                self.parent[child] = node
                self.dfs(child)
                self.low[node] = min(self.low[node], self.low[child])  # backtracking edge

                if self.low[child] > self.disc[node]:
                    self.bridges.append((child, node))
            elif self.parent.get(node, None) != child:# back edge
                self.low[node] = min(self.low[node], self.disc[child])

    def dfsNormal(self, node):
        self.vis.add(node)
        ans = 1
        for child in self.graph[node]:
            if (child, node) in self.deleted or (node, child) in self.deleted:
                continue

            if child not in self.vis:
                ans += self.dfsNormal(child)
        
        return ans
        
    def size(self):
        ans = 1
        for node in self.graph:
            if node not in self.vis:
                ans *= self.dfsNormal(node)

        return ans

def solve():
    edges = []
    graph = BridgesByTarjan()
    g = nx.Graph()
    with open('/home/odoo/raouf/github/problem-solving/Competitions/Advent Of Code/adventOfCode2023/day25/a.txt', 'r') as file:
        for line in file:
            (frm, tos) = line.split(': ')
            tos = tos.split()

            for to in tos:
                edges.append((frm, to))
                graph.add(frm, to)
                g.add_edge(frm, to, capacity=1.)
                g.add_edge(to, frm, capacity=1.)


    for i in g._node.keys():
        # if len(graph.bridges) > 0:
        #     break

        for j in g._node.keys():
            if i == j:
                continue
            # graph.deleted = [edges[i], edges[j]]
            # graph.load()
            # graph.dfs(edges[j+1][0])

            # if len(graph.bridges) > 0:
            #     graph.deleted.extend(graph.bridges)
            #     break

            # tbh, theorically, i think using tarjan algorithm to find a bridge after deleting 2 edges looks faster
            # but everyone used min cut which is theorically worst than tarjan but maybe nx has a faster implemntation of it
            cut, par = nx.minimum_cut(g, i, j)
            if cut == 3:
                return len(par[0])*len(par[1])
            
    return 0
    # graph.vis = set()
    # return graph.size()

print(solve())
