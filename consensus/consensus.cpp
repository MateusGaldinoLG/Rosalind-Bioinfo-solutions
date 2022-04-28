#include <iostream> 
#include <fstream>
#include <string>
#include <vector>

using namespace std; 

typedef struct DNAStrand{
    string label;
    string sequence;
}DNAStrand;

int main(){
    ifstream f;
    int numStrands = 0;

    vector<DNAStrand> strands;

    f.open("rosalind_consensus.txt", ios::in);
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

    int size = strands.at(0).sequence.length();

    int **profile = (int **)malloc(4*sizeof(int *));
    for(int i = 0; i < 4; i++){
        profile[i] = (int *)calloc(size, sizeof(int));
    
    }

    char *consensus = (char *)calloc(size+1, sizeof(char));

    for(auto strand : strands){
        for(int i = 0; i < strand.sequence.size(); i++){
            if(strand.sequence.at(i) == 'A'){
                profile[i][0]++;
            } else if(strand.sequence.at(i) == 'C'){
                profile[i][1]++;
            } else if(strand.sequence.at(i) == 'G'){
                profile[i][2]++;
            } else if(strand.sequence.at(i) == 'T'){
                profile[i][3]++;
            }
        }
    }

    char options[] = {'A', 'C', 'G', 'T'};

    for(int m = 0; m < size; m++){
        int greatest = 0;
        for(int i = 0; i < 4; i++){
            if(profile[i][m] > greatest){
                greatest = profile[i][m];
                consensus[m] = options[i];
            }
        }
    }

    cout << consensus << endl;

    string Aprofile = "A: ";
    string Cprofile = "C: ";
    string Gprofile = "G: ";
    string Tprofile = "T: ";

    for(int m = 0; m < size; m++){
        int greatest = 0;
        for(int i = 0; i < 4; i++){
            if(i == 0){
                Aprofile += profile[m][i];
            } else if(i == 1){
                Cprofile += profile[m][i];
            } else if(i == 2){
                Gprofile += profile[m][i];
            } else if(i == 3){
                Tprofile += profile[m][i];
            }
        }
    }

    cout << Aprofile << endl;
    cout << Cprofile << endl;
    cout << Gprofile << endl;
    cout << Tprofile << endl;


    for(int i = 0; i < 4; i++){
        free(profile[i]);
    }

    free(profile);
    free(consensus);

    f.close();

    return 0;
}