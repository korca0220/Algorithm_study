#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n = 10;
int map[10][10];
int num_of[6] = {0,5,5,5,5,5}; 

int go(int z){

    if(z==n*n){ // 25
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(map[i][j] == 1)return -1;
            }
        }
        return 0;
    }

    int x = z/n;
    int y = z%n;

    if(map[x][y] == 0)return go(z+1);

    int ans = -1;
    for(int k=5; k>=1; k--){
        if(num_of[k] > 0 ){
            if(x+k-1 < n && y+k-1 < n){
                bool ok = true;
                for(int i=x; i<x+k; i++){
                    for(int j=y; j<y+k; j++){
                        if(map[i][j] == 0){
                            ok = false;
                            break;
                        }
                    }
                    if(!ok)break;
                }            
                if(ok){            
                    for(int i=x; i<x+k; i++){
                        for(int j=y; j<y+k; j++){
                            map[i][j] = 0;
                        }
                    }
                    num_of[k] -=1;
                    int temp = go(z+1);
                    num_of[k] +=1;
                    if(temp != -1){
                        if(ans == -1 || ans > temp+1){
                            ans = temp + 1;
                        }
                    }
                    for(int i=x; i<x+k; i++){
                        for(int j=y; j<y+k; j++){
                            map[i][j] = 1;
                        }
                    }
                }
            }
        }
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    cout << go(0);

    return 0;
}