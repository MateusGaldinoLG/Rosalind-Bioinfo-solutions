DNAstrings = {}

with open("rosalind_consensus.txt", "r") as f:
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


profile = [[0 for j in range(4)] for i in range(len(DNAstrings[label]))]

consensus = [0 for i in range(len(DNAstrings[label]))]

for label in DNAstrings:
    i = 0
    for base in DNAstrings[label]:
        if(base == "A"):
            profile[i][0] += 1
        elif(base == "C"):
            profile[i][1] += 1
        elif(base == "G"):
            profile[i][2] += 1
        elif(base == "T"):
            profile[i][3] += 1
        i += 1

options = ["A", "C", "G", "T"]

for i in range(len(profile)):
    greatest = 0
    for j in range(len(profile[i])):
        if(profile[i][j] > greatest):
            greatest = profile[i][j]
            consensus[i] = options[j]

print("".join(consensus))

A_profile = "A: "
C_profile = "C: "
G_profile = "G: "
T_profile = "T: "

for i in range(len(profile)):
    for j in range(len(profile[i])):
        if(j == 0):
            A_profile += str(profile[i][0]) + " "
        elif(j == 1):
            C_profile += str(profile[i][1]) + " "
        elif(j == 2):
            G_profile += str(profile[i][2])+ " "
        elif(j == 3):
            T_profile += str(profile[i][3])+ " "

print(A_profile)
print(C_profile)
print(G_profile)
print(T_profile)