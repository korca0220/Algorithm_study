#include <iostream>
using namespace std;

const int MAX = 1000;
const int MOD = 42;
int number[MAX] = {0,};


int main(){
    
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int input;
    int count_over=0;
    for(int i =0; i<10; i++){
        cin >> input;
        if(number[input%MOD] == 0){
            number[input%MOD] = 1;
            count_over++;
        }
    }
    cout << count_over << "\n";



    return 0;
}