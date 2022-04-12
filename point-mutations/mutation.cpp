#include <iostream> 

using namespace std; 

int main(){
    string sequence1, sequence2;
    int hammingDistance = 0;

    cin >> sequence1;
    cin >> sequence2;

    for(int i = 0; i < sequence1.length(); i++){
        if(sequence1[i] != sequence2[i]){
            hammingDistance++;
        }
    }

    cout << hammingDistance;

    return 0;
}