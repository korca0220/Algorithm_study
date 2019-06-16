#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
int input;
int number[MAX+1];

int getMin(int x){

    number[1] = 0;
    for(int i=2; i<=x; i++){
        number[i] = number[i-1] + 1;
        if(i%2 == 0 && number[i] > number[i/2] + 1){
            number[i] = number[i/2] + 1;
        }
        if(i%3 == 0 && number[i] > number[i/3] + 1){
            number[i] = number[i/3] + 1;
        }
    }
    return number[x];

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin>>input;
    cout << getMin(input) << "\n";

    return 0;
}