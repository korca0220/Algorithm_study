#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;
int des[10][10];
int min_number = 987654321;

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> input;
    vector<int> dx;
    for(int i=0; i<input; i++) dx.push_back(i);
    for(int i=0; i<input; i++){
        for(int j=0; j<input; j++){
            cin >> des[i][j];
        }
    }

    do{        
        bool check = true;
        int sum = 0;
        for(int i=0; i<input-1; i++){
            if(des[dx[i]][dx[i+1]] == 0) check = false;
            else sum += des[dx[i]][dx[i+1]];
        }

        if (check && des[dx[input-1]][dx[0]] != 0){
            sum += des[dx[input-1]][dx[0]];
            if(min_number > sum ) min_number= sum;
        }

    }while(next_permutation(dx.begin(), dx.end()));


    cout << min_number;
    return 0;

}