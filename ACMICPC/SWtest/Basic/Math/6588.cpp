#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1000000;
bool isPrime[MAX];


void getPrime(){

    for(int i=2; i<=MAX; i++)isPrime[i] = true;
    for(int i=2; i<=sqrt(MAX); i++){
        if(isPrime[i]){
            for(int j= i*i; j<=MAX; j+=i)isPrime[j] = false;
        }
    }

}


int main(){

    getPrime();

    return 0;
}