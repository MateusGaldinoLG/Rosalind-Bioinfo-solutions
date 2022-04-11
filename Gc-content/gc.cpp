#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

using namespace std; 

typedef struct DNAStrand{
    string label;
    string sequence;
}DNAStrand;

double GC(string sequence){
    double numGC = 0;
    double GC_content;
    for(int i = 0; i < sequence.length(); i++){
        if(sequence.at(i) == 'G' || sequence.at(i) == 'C'){
            numGC++;
        }
    }
    if(sequence != ""){
        GC_content = numGC /  sequence.length();
        return GC_content;
    }

    return 0.0;
}

int main(){
    ifstream f;
    int numStrands = 0;
    vector<DNAStrand> strands;
    f.open("rosalind_gc.txt", ios::in);
    if(!f.is_open()){
        cout << "No file found";
        exit(1);
    }


    string line;


    while(getline(f, line)){
        if(line.at(0) == '>'){
            strands.insert(strands.end(), {line.substr(1), ""});
            numStrands++;
        } else {
            strands.at(numStrands-1).sequence.append(line);
        }
    }

    double greatest = 0;
    string nameGreatest = "";
    for(auto strand : strands){
        double gc = 100 * (GC(strand.sequence));
        if(gc > greatest){
            greatest = gc;
            nameGreatest = strand.label;
        }
    }

    cout << nameGreatest << endl;
    cout << greatest;
    f.close();
    
    return 0;
}