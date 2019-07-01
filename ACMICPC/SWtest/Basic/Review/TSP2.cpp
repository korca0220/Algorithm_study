#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;
int W[11][11];
vector<int> p;
int min_num = 987654321;

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(int i=0; i<input; i++)p.push_back(i);
    for(int i=0; i<input; i++){
        for(int j=0; j<input; j++){
            cin >> W[i][j];
        }
    }
    
    do{
        int sum=0; 
        bool check = true;
        for(int i=0; i<input-1; i++){            
            if(W[p[i]][p[i+1]] != 0){
                sum += W[p[i]][p[i+1]];
            }else {                
                check = false;                
            }
        }
        if(W[p[input-1]][p[0]] != 0 && check == true){
            sum += W[p[input-1]][p[0]];
            min_num = min(min_num, sum);
        }        
    }while(next_permutation(p.begin(), p.end()));
    cout << min_num << "\n";

    return 0;
}