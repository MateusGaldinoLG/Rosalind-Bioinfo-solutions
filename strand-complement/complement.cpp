#include <iostream> 

using namespace std; 

int main(){
    string strand, strandComplement = "";

    cin >> strand;

    for(int i = strand.length() - 1; i >= 0; i--){
        if(strand.at(i) == 'A'){
            strandComplement.append("T");
        } else if(strand.at(i) == 'T'){
            strandComplement.append("A");
        } else if(strand.at(i) == 'C'){
            strandComplement.append("G");
        } else if(strand.at(i) == 'G'){
            strandComplement.append("C");
        }
    }

    cout << strandComplement;

    return 0;
}