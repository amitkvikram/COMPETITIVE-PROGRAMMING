import numpy as np

nMax = 1000


def getN():
    return np.random.randint(1, nMax+1)


def getK(n):
    return np.random.randint(1, n + 1)


def getNode(numPorts):
    return np.random.randint(1, numPorts)

def getPruferCode(group):
    pruferCode = []
    for i in range(len(group) - 2):
        x = np.random.randint(len(group) + 1)
        pruferCode.append(group[x - 1])
    
    leaves = []
    dic = set(pruferCode)
    for node in group:
        if(node not in dic):
            leaves.append(node)

    return pruferCode, leaves

def pruferCodeToTree(pruferCode, leaves):
    # print("--------------------")
    # print(pruferCode, leaves)
    leaves = set(leaves)
    edges = []
    while len(pruferCode) != 0:
        x = min(leaves)
        y = pruferCode[len(pruferCode) - 1]
        pruferCode.pop()
        edges.append((x, y))
        leaves.remove(x)
        if(y not in pruferCode):
            leaves.add(y)
    edges.append((min(leaves), max(leaves)))
    # print(edges)
    # print("--------------------")
    return edges

def addEdgeBetweenIsland(groups, source, Destination):
    ind1 = np.random.randint(len(groups[source - 1]))
    ind2 = np.random.randint(len(groups[Destination - 1]))  

    return (groups[source - 1][ind1], groups[Destination - 1][ind2])


# numPorts = getN()
numPorts = int(input("Enter numPorts: "))
print("numPorts: {}".format(numPorts))
# numIsland = getK(numPorts)
numIsland = int(input("Enter number of island: "))
groups = [[] for _ in range(numIsland)]
portIslandMap = [0 for _ in range(numPorts)]

#divide ports in islands
for i in range(numPorts):
    island = np.random.randint(numIsland)
    groups[island].append(i+1)
    portIslandMap[i] = island + 1

for group in groups:
    if(len(group) == 0):
        print("Invalid group")
        exit()

#x may be equal to y i.e Joey and Chandler may be at same place
x = getNode(numPorts)
y = getNode(numPorts)

JoeyPort = x
ChandlerPort = y

m1 = 0
UndirectedEdges = []

print("numPorts = {}\nJoey at Port = {}\nChandler at Port = {}\nnumIsland = {}".format(numPorts, x, y, numIsland))
print("Joey at island = {}\nChandler at island = {} ".format(portIslandMap[x - 1], portIslandMap[y - 1]))
for group in groups:
    print("group = {}".format(group))

for group in groups:
    if len(group) == 1:
        continue
    elif len(group) == 2:
        edges = [(group[0], group[1])]
    else: 
        pruferCode, leaves = getPruferCode(group)
        edges = pruferCodeToTree(pruferCode, leaves)
    UndirectedEdges += edges

m1 = len(UndirectedEdges)

# print("Undirecte Edges = ", UndirectedEdges)

## generate directed edges
m2 = 0
DirectedEdges = []
while True:
    flag = input("Want to generate edge: ")
    if(flag == "n"):
        break

    x, y = list(map(int, input("Enter edge: ").split()))
    edge = addEdgeBetweenIsland(groups, x, y)
    DirectedEdges.append(edge)
    m2+=1


# m2 = int(input("Enter number of directed edges"))
# temp = np.arange(numIsland) + 1
# for i in range(m2):
#     x, y = np.random.choice(temp, 2, replace = False)
#     edge = addEdgeBetweenIsland(groups, x, y)
#     DirectedEdges.append(edge)


print("m, m2 = ", m1, m2)
# print("Directed Edges = ", DirectedEdges)

#save input
fileName = input("Enter FileName")
file = open(fileName, 'w')
file.write(str(numPorts))
file.write("\n")
file.write(str(JoeyPort) + " " + str(ChandlerPort))
file.write("\n")
file.write(str(m1))
file.write("\n")
for edge in UndirectedEdges:
    file.write(str(edge[0]) + " " + str(edge[1]))
    file.write("\n")
file.write(str(m2))
file.write("\n")
for edge in DirectedEdges:
    file.write(str(edge[0]) + " " + str(edge[1]))
    file.write("\n")