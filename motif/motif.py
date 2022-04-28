sequence = input()
subsequence = input()

numEqual = 0
positionOccurrences = []


for i in range(len(sequence)-len(subsequence)):
    numEqual = 0
    for j in range(len(subsequence)):
        if(sequence[i+j] == subsequence[j]):
            numEqual += 1
    if(numEqual == len(subsequence)):
        positionOccurrences.append(i+1)

print(' '.join(map(str, positionOccurrences)))

