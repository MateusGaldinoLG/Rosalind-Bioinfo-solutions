
DNAstrings = {}

with open("rosalind_grph.txt", "r") as f:
    label = ""
    while True:
        line = f.readline()
        if not line:
            break
        if(line[0] != '>'):
            DNAstrings[label] += line.strip()
        elif(line[0] == '>'):
            label = line[1:]
            DNAstrings[label] = ""

adjList = []
numEdges = 0
isEqual = True

for label in DNAstrings:
    for label2 in DNAstrings:
        if(label == label2): 
            continue
        isEqual = True
        length = len(DNAstrings[label])
        label1Node = DNAstrings[label][-3:]
        label2Node = DNAstrings[label2][:3]
        if(label1Node == label2Node):
            adjList.insert(numEdges, [label, label2])
            numEdges += 1


with open("answer.txt", "w") as f:
    for edge in adjList:
        f.write(edge[0].strip() + " " + edge[1].strip() + "\n")


