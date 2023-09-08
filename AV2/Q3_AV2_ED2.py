import networkx as nx
class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.grafo = []

    def add_edge(self, u, v, w):
        self.grafo.append([u, v, w])

    def find(self, parent, i):
        if parent[i] == i:
            return i
        return self.find(parent, parent[i])

    def apply_union(self, parent, rank, x, y):
        xroot = self.find(parent, x)
        yroot = self.find(parent, y)
        if rank[xroot] < rank[yroot]:
            parent[xroot] = yroot
        elif rank[xroot] > rank[yroot]:
            parent[yroot] = xroot
        else:
            parent[yroot] = xroot
            rank[xroot] += 1

    def kruskal_algo(self):
        resultado = []
        i, e = 0, 0
        self.grafo = sorted(self.grafo, key=lambda item: item[2])
        parent = []
        rank = []
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        while e < self.V - 1:
            u, v, w = self.grafo[i]
            i = i + 1
            x = self.find(parent, u)
            y = self.find(parent, v)
            if x != y:
                e = e + 1
                resultado.append([u, v, w])
                self.apply_union(parent, rank, x, y)
        

        
        grafo = nx.Graph()
        
        for u, v, distancia in resultado:
            if u == 0: verticeA = 'SFO'
            if u == 1: verticeA = 'LAX'
            if u == 2: verticeA = 'ORD'
            if u == 3: verticeA = 'DFW'
            if u == 4: verticeA = 'JFK' 
            if u == 5: verticeA = 'MIA' 
            if u == 6: verticeA = 'BOS' 
            
            if v == 0: verticeB = 'SFO'
            if v == 1: verticeB = 'LAX'
            if v == 2: verticeB = 'ORD'
            if v == 3: verticeB = 'DFW'
            if v == 4: verticeB = 'JFK' 
            if v == 5: verticeB = 'MIA' 
            if v == 6: verticeB = 'BOS'
            print("\n %s - %d Km - %s:" % (verticeA, distancia, verticeB))
            grafo.add_edge(verticeA,verticeB)
        nx.draw(grafo, with_labels=True)


g = Graph(7) 
g.add_edge(0, 1, 337)
g.add_edge(0, 2, 1846)
g.add_edge(0, 3, 1464)
g.add_edge(0, 6, 2704)
g.add_edge(1, 3, 1235)
g.add_edge(1, 5, 2342)
g.add_edge(2, 3, 802)
g.add_edge(2, 4, 740)
g.add_edge(2, 6, 867)
g.add_edge(3, 5, 1125)
g.add_edge(4, 5, 1090)
g.add_edge(4, 6, 187)
g.add_edge(5, 6, 1258)
g.kruskal_algo()


