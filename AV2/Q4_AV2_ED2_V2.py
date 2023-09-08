import networkx as nx
import pandas as pd
import sys

INF = sys.maxsize

with open('dados.csv','r') as f:
    G = [[int(entry) for entry in line.split()] for line in f.readlines()]    

V = len(G) # Quantidade de vertices
print('\n\nLista formada apartir do txt:')
print(G)


selected = [False] * V
selected[0] = True
no_edge = 0

print("\n\Vertices : pesos")
grafo = nx.Graph()
while (no_edge < V - 1):
    minimum = INF
    x = 0
    y = 0
    for i in range(V):
        if selected[i]:
            for j in range(V):
                if ((not selected[j]) and G[i][j]):  
                    if minimum > G[i][j]:
                        minimum = G[i][j]
                        x = i
                        y = j
    print(str(x) + "-" + str(y) + " : " + str(G[x][y]))
    grafo.add_edge(x,y)
    selected[y] = True
    no_edge += 1
nx.draw(grafo, with_labels=True)