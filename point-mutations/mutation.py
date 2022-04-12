sequence1 = input()
sequence2 = input()

size = len(sequence1)

hamming_distance = 0

# theta(n) efficiency

for i in range(size):
    if(sequence1[i] != sequence2[i]):
        hamming_distance += 1

print(hamming_distance)