import sys

class graph:
    def __init__(self, nodes, edges):
        self.numNodes = nodes
        self.numEdges = edges
        self.nodes = []
        for i in range(nodes):
            self.nodes.append(node())
        self.edges = []
    
    def addVerts(self, fst, snd):
        self.nodes[fst].addVert(snd)
        self.nodes[snd].addVert(fst)

    def addEdge(self, fst, snd, cap):
        self.edges.append(edge(fst, snd, cap))

    def getMaxPath(self):
        dists = [0] * self.numNodes
        parents = [-1] * self.numNodes
        spanned = [False] * self.numNodes
        dists[0] = sys.maxsize

        for i in range(self.numNodes):
            u = self.maxDist(dists, spanned)
            spanned[u] = True
            for j in range(self.numNodes):
                if (not spanned[j] and self.isEdge(u, j) and self.getEdge(u, j) > dists[j]):
                    dists[j] = self.getEdge(u, j)
                    parents[j] = u

        maxPath = []
        i = self.numNodes - 1
        while (i != -1):
            maxPath.append(i)
            i = parents[i]

        maxPath.reverse()
        return maxPath

    def isEdge(self, n1, n2):
        for n in self.nodes[n1].getVerts():
            if (n == n2):
                return True
        return False

    def getEdge(self, n1, n2):
        for e in self.edges:
            fst = e.getFirst()
            snd = e.getSecond()
            if ((fst == n1 and snd == n2) or (fst == n2 and snd == n1)):
                return e.getCapacity()
        return 0

    def maxDist(self, dists, spanned):
        maxDist, maxI = 0, 0
        for i in range(self.numNodes):
            if (not spanned[i] and dists[i] > maxDist):
                maxDist = dists[i]
                maxI = i
        return maxI

    def getBlockedEdges(self, maxPath):
        blockedEdges = []
        for i in range(len(self.edges)):
            blocked = False
            e = self.edges[i]
            fst = e.getFirst()
            snd = e.getSecond()
            for j in range(len(maxPath)):
                if (fst == maxPath[j] or snd == maxPath[j]):
                    blocked = True
            for j in range(len(maxPath) - 1):
                if ((fst == maxPath[j] and snd == maxPath[j+1]) or (fst == maxPath[j+1] and snd == maxPath[j])):
                    blocked = False
            if (blocked):
                blockedEdges.append(i)

        blockedEdges.sort()
        return blockedEdges
    
class node:
    def __init__(self):
        self.vertices = []

    def addVert(self, val):
        self.vertices.append(val)

    def getVerts(self):
        return self.vertices

class edge:
    def __init__(self, fst, snd, cap):
        self.n1 = fst
        self.n2 = snd
        self.capacity = cap

    def getFirst(self):
        return self.n1

    def getSecond(self):
        return self.n2

    def getCapacity(self):
        return self.capacity

if __name__ == "__main__":
    lines = sys.stdin.readlines()

    l1 = lines[0]
    nodes = int(l1[:(l1.find(" "))])
    edges = int(l1[(l1.find(" ")+1):])
    g = graph(nodes, edges)

    for x in lines[1:]:
        i1 = x.find(" ")
        i2 = x.find(" ", i1+1)
        fst = int(x[:i1])
        snd = int(x[i1+1:i2])
        cap = int(x[i2+1:])
        g.addVerts(fst, snd)
        g.addEdge(fst, snd, cap)
    
    maxPath = g.getMaxPath()
    blockedEdges = g.getBlockedEdges(maxPath)

    if (len(blockedEdges) == 0):
        print("none")
    else: 
        for i in range(len(blockedEdges)):
            print(blockedEdges[i]),