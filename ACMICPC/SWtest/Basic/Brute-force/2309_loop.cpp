#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 9;
int dwarf[MAX];

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int sum=0;
    for(int i=0; i<9; i++){
        cin >> dwarf[i];
        sum += dwarf[i];
    }

    sort(dwarf, dwarf+MAX);
    for(int i=0; i<8; i++){
        for(int j=i+1; j<9; j++){
            if(sum - dwarf[i] - dwarf[j] == 100){
                for(int k=0; k<9; k++){
                    if( i != k && j != k){
                        cout << dwarf[k] << "\n";
                    }
                }
                return 0;
            }
        }
    }



    return 0;
}