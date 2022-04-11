#include <iostream> 

using namespace std; 

int main(){
    string dnaSequence, rnaSequence = "";

    cin >> dnaSequence;

    for(int i = 0; i < dnaSequence.length(); i++){
        if(dnaSequence.at(i) == 'T'){
            rnaSequence.append(1, 'U');
        } else {
            rnaSequence.append(1, dnaSequence.at(i));
        }
    } 

    cout << rnaSequence;
    return 0;
}