#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAX = 1000000;
bool isPrime[MAX];
vector<int> odd;

void getPrime(){

    for(int i=2; i<=MAX; i++)isPrime[i] = true;
    for(int i=2; i<=sqrt(MAX); i++){
        if(isPrime[i]){
            for(int j= i*i; j<=MAX; j+=i)isPrime[j] = false;
        }
    }

    for(int i=2; i<=MAX; i++){
        if(i%2 != 0 && isPrime[i])odd.push_back(i);
    }

}


int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    getPrime();

    int input=-1;
    while(input == 0){
        cin >> input;
        
    }

    return 0;
}