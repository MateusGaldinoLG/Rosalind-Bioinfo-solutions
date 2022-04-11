#include <iostream> 

using namespace std; 

int main(){
    string sequence;
    int numA = 0, numC = 0, numG = 0, numT = 0;

    cin >> sequence;

    for(int i = 0; i < sequence.length(); i++){
        if(sequence.at(i) == 'A'){
            numA++;
        } else if(sequence.at(i) == 'C'){
            numC++;
        } else if(sequence.at(i) == 'G'){
            numG++;
        } else if(sequence.at(i) == 'T'){
            numT++;
        }
    }

    cout << numA << " " << numC << " " << numG << " " << numT << endl;
    return 0;
}