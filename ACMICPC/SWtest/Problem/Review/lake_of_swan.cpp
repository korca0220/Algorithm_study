#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int r,c;
char in[1501][1501];
bool check_w[1501][1501];
bool check_s[1501][1501];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs_w(queue<pair<int,int>> &water, queue<pair<int,int>> &n_water){

    while(!water.empty()){
        int x = water.front().first;
        int y = water.front().second;
        water.pop();
        in[x][y] = '.';
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx >= r || ny<0 || ny >= c) continue;
            if(check_w[nx][ny]) continue;
            
            check_w[nx][ny] = true;
            if(in[nx][ny] == '.'){
                water.emplace(nx,ny);
            }else{
                n_water.emplace(nx,ny);                
            }
        }
    }

}

void bfs_s(queue<pair<int,int>> &swan, queue<pair<int,int>> &n_swan){

    while(!swan.empty()){
        int x = swan.front().first;
        int y = swan.front().second;
        swan.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>= r || ny <0 || ny>=c) continue;
            if(check_s[nx][ny]) continue;
            
            check_s[nx][ny] = true;
            if(in[nx][ny] == '.'){
                swan.emplace(nx,ny);
            }else{
                n_swan.emplace(nx,ny);                
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c;

    queue<pair<int,int>> water, n_water, swan, n_swan;

    int sx1,sy1,sx2,sy2;
    sx1=sy1=sx2=sy2=-1;
    for(int i=0; i<r; i++){
        cin >> in[i];
        for(int j=0; j<c; j++){
            if(in[i][j] =='L'){
                if(sx1 == -1){
                    sx1=i, sy1=j;
                }else{
                    sx2=i, sy2=j;
                }
                in[i][j] = '.';
            }
            if(in[i][j] =='.'){
                water.emplace(i,j);
                check_w[i][j] = true;
            }
        }
    }
    swan.emplace(sx1,sy1);
    check_s[sx1][sy1] = true;
    int day = 0;
    while(true){
        bfs_w(water, n_water);
        bfs_s(swan, n_swan);

        if(check_s[sx2][sy2]){
            cout << day;
            break;
        }
        day+=1;
        
        water = n_water;
        swan  = n_swan;
        n_water = queue<pair<int,int>>();
        n_swan  = queue<pair<int,int>>();
    }


    return 0;
}