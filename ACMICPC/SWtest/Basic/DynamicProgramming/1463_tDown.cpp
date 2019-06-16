#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000000;
int input;
int number[MAX+1];

int getMin(int x){

    if (x==1) return 0;
    if(number[x] > 0) return number[x];
    
    number[x] = getMin(x-1) + 1;
    if( x%2 == 0){
        int temp = getMin(x/2) + 1;
        if(number[x] > temp) number[x] = temp;
    }
    if(x%3 == 0){
        int temp = getMin(x/3) + 1;
        if(number[x] > temp) number[x] = temp;
    }
    return number[x];
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    cout << getMin(input) << "\n";

    return 0;
}