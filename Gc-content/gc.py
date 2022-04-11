def GC(sequence):
    numGC = 0
    for base in sequence:
        if(base == 'G' or base == 'C'):
            numGC += 1
    if(sequence != ""):
        GC_content = numGC / len(sequence)
        return GC_content
    else:
        return 0

DNAstrings = {}

with open("rosalind_gc.txt", "r") as f:
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

greatestLabel = 0
nameGratest = ""
for label in DNAstrings:
    gc = 100 * (GC(DNAstrings[label]))
    if(gc > greatestLabel):
        greatestLabel = gc
        nameGratest = label
print(nameGratest, end='')
print("{}".format((greatestLabel)))
