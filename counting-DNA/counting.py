sequence = input()

numA, numC, numG, numT = 0, 0, 0, 0

for symbol in sequence:
    if(symbol == "A"):
        numA += 1
    elif(symbol == "C"):
        numC += 1
    elif(symbol == "G"):
        numG += 1
    elif(symbol == "T"):
        numT += 1

print("{} {} {} {}".format(numA, numC, numG, numT))