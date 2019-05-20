#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 1000;
bool isPrime[MAX];
int input;


void getPrime(){

    for(int i=2; i<=MAX; i++)isPrime[i] = true;
    for(int i=2; i<=sqrt(MAX); i++){

        if(isPrime[i]){
            for(int j=i*i; j<=MAX; j+=i){
                isPrime[j] = false;
            }
        }
    }    

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int get_num;
    int count = 0;
    getPrime();

    cin >> input;

    for(int i=0; i<input; i++){
        cin >> get_num;
        if (get_num == 0 || get_num == 1) continue;
        if(isPrime[get_num]) count++;
    }
    cout << count <<"\n";

    return 0;
}