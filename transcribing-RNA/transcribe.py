dna_sequence = input()
rna_sequence = ""

for base in dna_sequence:
    if(base == "T"):
        rna_sequence += "U"
    else:
        rna_sequence += base

print(rna_sequence)
