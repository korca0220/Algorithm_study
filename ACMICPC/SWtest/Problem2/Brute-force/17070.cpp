#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int map[17][17];

int go(int x, int y, int dir){

    if(x==n-1 && y==n-1) return 1;

    int ans = 0;
    if(dir==0){
        if(y+1 < n && map[x][y+1] == 0){
            ans += go(x, y+1, 0);
        }
        if(x+1 < n && y+1 < n && map[x+1][y] ==0 && map[x][y+1] == 0 && map[x+1][y+1] == 0){
            ans += go(x+1, y+1, 1);
        }
    }else if(dir==1){
        if(y+1 < n && map[x][y+1] == 0){
            ans += go(x, y+1, 0);
        }
        if(x+1 < n && y+1 < n && map[x+1][y] == 0 && map[x][y+1] == 0 && map[x+1][y+1] == 0){
            ans += go(x+1, y+1, 1 );
        }
        if(x+1 < n && map[x+1][y] == 0){
            ans += go(x+1, y, 2);
        }
    }else if(dir==2){
        if(x+1 < n && y+1 < n && map[x+1][y] == 0 && map[x][y+1] == 0 && map[x+1][y+1] == 0){
            ans += go(x+1, y+1, 1);
        }
        if(x+1 < n && map[x+1][y] == 0){
            ans += go(x+1, y, 2);
        }
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n ;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
        }
    }
    cout << go(0,1,0);

    return 0 ;
}