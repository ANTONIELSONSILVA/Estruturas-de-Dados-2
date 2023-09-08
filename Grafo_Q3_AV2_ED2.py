import networkx as nx
import matplotlib.pyplot as plt

# Classe
class Graph:
    def __init__(self, vertices):
        self.V = vertices
        self.graph = []

    def adiciona_aresta(self, u, v, w):
        self.graph.append([u, v, w])

    # Função de busca
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

    # Algoritmo
    def kruskal(self):
        calculo = []
        i, e = 0, 0
        self.graph = sorted(self.graph, key=lambda item: item[2])
        parent = []
        rank = []
        for node in range(self.V):
            parent.append(node)
            rank.append(0)
        while e < self.V - 1:
            u, v, w = self.graph[i]
            i = i + 1
            x = self.find(parent, u)
            y = self.find(parent, v)
            if x != y:
                e = e + 1
                calculo.append([u, v, w])
                self.apply_union(parent, rank, x, y)
        
        G = nx.Graph()
        for i, j, distancia in calculo:
            if i == 0: cidadeA = 'SFO'
            if i == 1: cidadeA = 'LAX'
            if i == 2: cidadeA = 'ORD'
            if i == 3: cidadeA = 'DFW'
            if i == 4: cidadeA = 'JFK' 
            if i == 5: cidadeA = 'MIA' 
            if i == 6: cidadeA = 'BOS' 
            if j == 0: cidadeB = 'SFO'
            if j == 1: cidadeB = 'LAX'
            if j == 2: cidadeB = 'ORD'
            if j == 3: cidadeB = 'DFW'
            if j == 4: cidadeB = 'JFK' 
            if j == 5: cidadeB = 'MIA' 
            if j == 6: cidadeB = 'BOS'
            print("\n%s - %s: distância de %d km" % (cidadeA, cidadeB, distancia))
            G.add_edge(cidadeA,cidadeB, weight=distancia)
        pos = nx.spring_layout(G) #Pega a posição
        nx.draw(G, pos,with_labels=True, node_size=1000)
        labels = nx.get_edge_attributes(G, 'weight') #Pega peso da label
        nx.draw_networkx_edge_labels(G, pos,edge_labels=labels, font_size=9)

g = Graph(7) 
g.adiciona_aresta(0, 1, 337)
g.adiciona_aresta(0, 2, 1846)
g.adiciona_aresta(0, 3, 1464)
g.adiciona_aresta(0, 6, 2704)

g.adiciona_aresta(1, 3, 1235)
g.adiciona_aresta(1, 5, 2342)

g.adiciona_aresta(2, 3, 802)
g.adiciona_aresta(2, 4, 740)
g.adiciona_aresta(2, 6, 867)

g.adiciona_aresta(3, 5, 1125)

g.adiciona_aresta(4, 5, 1090)
g.adiciona_aresta(4, 6, 187)

g.adiciona_aresta(5, 6, 1258)

g.kruskal()
plt.show()