import sys # Usar infinito
import networkx as nx #Usar os graficos
import matplotlib.pyplot as plt #Apresentar os Gráficos

V = 28 # Quantidade de vértices do Grafo

# Procurar o vertice com menor distância
def minDistancia(dist, lista):
    minimo = sys.maxsize
    min_index = -1 # Caso a distância seja 0 ele irá retornar isso
         
        # Pegar na lista o menor valor e que esteja na lista
    for i in range(len(dist)):
        if dist[i] < minimo and i in lista:
            minimo = dist[i]
            min_index = i
    return min_index
 
 
# Printa o menor caminho de um dado inicio e destino
def printCaminho(parent, j):         
    if parent[j] == -1 : 
        print (j+1, end='') 
        return # Se caso J for o valor inicial ele finaliza
    printCaminho(parent , parent[j])
    print (' -> ', j+1, end='')
         
 
def printDistancia(dist, parent, destino, src):
    print("\n%d --> %d | Distância -> %.2f " % (src+1, destino+1, dist[destino]))
    print('Caminho -> ', end='')
    printCaminho(parent, destino)
    print('\n')
 
 
def dijkstra(graph, src, destino):
 
    linha = len(graph)
    coluna = len(graph[0])

    # Inicializa as distâncias em infinito
    dist = [sys.maxsize] * linha
 
    # Lista para armazenar o menor caminho
    parent = [-1] * linha

    # Distância do vertice inicial
    dist[src] = 0
     
    # Adiciona os vértices a lista
    lista = []
    for i in range(linha):
        lista.append(i)
             
    #Procura o menor caminho para todos os vértices
    while lista:
 
        # Pega a menor distância do vértice da lista
        u = minDistancia(dist,lista)
    
        # Remove o menor elemento    
        lista.remove(u)
 
        # Atualiza a distância dos vertices da lista. 
        # Atualizando dist apenas se estiver na lista
        for i in range(coluna):
            if graph[u][i] and i in lista:
                if dist[u] + graph[u][i] < dist[i]:
                    dist[i] = dist[u] + graph[u][i]
                    parent[i] = u
    # Printa
    printDistancia(dist,parent, destino, src)
  
Grafo = [[0 for x in range(V)] for x in range(V)]

arestas = [(0,1,12.8),(0,7,27.7),(0,8,23.6),(0,6,29),
           (1,2,24.1),(1,3,42),(1,6,17),(1,7,22.3),
           (2,3,12.8),(2,5,30.8),(2,6,32),
           (3,4,20),
           (4,5,25),(4,13,45),(4,14,21.6),
           (5,6,14.8),(5,11,37.3),(5,12,33.4),(5,13,31.3),
           (6,7,24.8),(6,10,32.5),(6,11,33),(6,12,41.3),
           (7,8,26.3),(7,9,50),(7,10,19.8),
           (8,9,24),
           (9,10,24),(9,18,20),(9,19,39.8),
           (10,11,23),(10,18,38),
           (11,12,20),(11,16,39),(11,17,59),
           (12,13,16),(12,15,32.5),(12,16,34.4),
           (13,14,23.8),(13,15,39),
           (15,16,62.2),(15,26,38),(15,27,33),
           (16,17,22.6),(16,22,12.2),
           (17,18,14.7),(17,21,28.3),(17,22,20.4),
           (18,19,34),(18,21,29),
           (19,20,15.7),
           (21,22,58.3),
           (22,23,9.5),(22,25,24.2),
           (25,23,21),
           (23,24,23.6),(23,27,58),
           (24,27,42),
           (26,27,26)]

def setValor(m,n,valor):
    Grafo[m][n] = valor
    Grafo[n][m] = valor

for a in arestas:
    setValor(a[0],a[1],a[2])

GrafoNx = nx.Graph() 
for i in range(V): #Preenche o GrafoNx
    for j in range(V):
        if Grafo[i][j] > 0:
            GrafoNx.add_edge(i+1, j+1, weight=Grafo[i][j]) 

pos = nx.spring_layout(GrafoNx) #Pega a posição
labels = nx.get_edge_attributes(GrafoNx, 'weight') #Pega peso da label
nx.draw(GrafoNx, pos, with_labels=True)
nx.draw_networkx_edge_labels(GrafoNx, pos, edge_labels=labels, font_size=6)
plt.show()
 
inicio = 8
destino = 15
dijkstra(Grafo, inicio-1, destino-1) # Como listas começam no índice zero, faça o -1.

inicio = 8
destino = 26
dijkstra(Grafo, inicio-1, destino-1)

inicio = 8
destino = 27
dijkstra(Grafo, inicio-1, destino-1)