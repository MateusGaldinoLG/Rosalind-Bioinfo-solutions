#include <iostream> 

using namespace std; 

long long int fibonacci(long long int n, long long int k){
    if(n == 0){
        return 0;
    } else if (n == 1){
        return 1;
    } else {
        return fibonacci(n-1, k) + k*fibonacci(n-2, k);
    }
}

int main(){
    long long int months, litter;
    cin >> months;
    cin >> litter;

    long long int total = fibonacci(months, litter);

    cout << total;
    return 0;
}