strand = input()
inverseStrand = strand[::-1]
strandComplement = ""


for base in inverseStrand:
    if base == 'A':
        strandComplement += "T"
    elif base == "T":
        strandComplement += "A"
    elif base == "G":
        strandComplement += "C"
    elif base == "C":
        strandComplement += "G"

print(strandComplement)
