#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int PERSON = 3;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;

    vector<vector<int>> d(n, vector<int>(n));
    vector<vector<int>> in(PERSON, vector<int>(20));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> d[i][j];
        }
    }
    // set - person
    for(int i=0; i<20; i++){
        cin >> in[1][i];
        in[1][i] -= 1;
    }
    for(int i=0; i<20; i++){
        cin >> in[2][i];
        in[2][i] -= 1;
    }
    in[0].resize(n);
    for(int i=0; i<n; i++)in[0][i] = i;

    do{
        vector<int> win = {0,0,0};
        vector<int> index = {0,0,0};
        int p1 = 0;
        int p2 = 1;
        while(true){
            if(p1 > p2) swap(p1, p2);
            if(index[p1] >= in[p1].size()) break;
            if(index[p2] >= in[p2].size()) break;
            int result = d[in[p1][index[p1]]][in[p2][index[p2]]];
            index[p1] += 1;
            index[p2] += 1;
            if(result == 2){ // p1-win
                win[p1] += 1;
                if(win[p1] == k) break;
                p2 = PERSON-p1-p2;
            }else{  // p2-win or draw
                win[p2] += 1;
                if(win[p2] == k) break;
                p1 = PERSON-p1-p2;
            }
        }
        if(win[0] == k){
            cout << "1";
            return 0;
        }
    }while(next_permutation(in[0].begin(), in[0].end()));
    cout << "0";

    return 0;
}