const fs = require('fs');

const RNA_codon_table = {
    "UUU": "F",    "CUU" : "L",      "AUU" : "I",      "GUU" : "V",
    "UUC": "F",    "CUC" : "L",      "AUC" : "I",      "GUC" : "V",
    "UUA": "L",    "CUA" : "L",      "AUA" : "I",      "GUA" : "V",
    "UUG": "L",    "CUG" : "L",      "AUG" : "M",      "GUG" : "V",
    "UCU": "S",    "CCU" : "P",      "ACU" : "T",      "GCU" : "A",
    "UCC": "S",    "CCC" : "P",      "ACC" : "T",      "GCC" : "A",
    "UCA": "S",    "CCA" : "P",      "ACA" : "T",      "GCA" : "A",
    "UCG": "S",    "CCG" : "P",      "ACG" : "T",      "GCG" : "A",
    "UAU": "Y",    "CAU" : "H",      "AAU" : "N",      "GAU" : "D",
    "UAC": "Y",    "CAC" : "H",      "AAC" : "N",      "GAC" : "D",
    "UAA": "Stop", "CAA" : "Q",      "AAA" : "K",      "GAA" : "E",
    "UAG": "Stop", "CAG" : "Q",      "AAG" : "K",      "GAG" : "E",
    "UGU": "C",    "CGU" : "R",      "AGU" : "S",      "GGU" : "G",
    "UGC": "C",    "CGC" : "R",      "AGC" : "S",      "GGC" : "G",
    "UGA": "Stop", "CGA" : "R",      "AGA" : "R",      "GGA" : "G",
    "UGG": "W",    "CGG" : "R",      "AGG" : "R",      "GGG" : "G", 
}

function divide_string(string, size){
    string = String(string);
    const numChunks = Math.ceil(string.length / size);
    const chunks = new Array(numChunks);

    for(let i = 0, o = 0; i < numChunks; ++i, o += size){
        chunks[i] = string.substr(o, size);
    }

    return chunks;
}

var protein_string = "";

fs.readFile('rosalind_prot.txt', (err, data) => {
    if(err){
        console.error("An error ocurred: " + err);
        return;
    }

    let list_sequences = divide_string(data, 3);
    for(let i = 0; i < list_sequences.length; i++){
        if(RNA_codon_table[list_sequences[i]] != "Stop"){
            protein_string += RNA_codon_table[list_sequences[i]];
        } else {
            break;
        }
    }

    console.log(protein_string);
});
