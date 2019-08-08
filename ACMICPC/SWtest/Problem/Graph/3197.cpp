#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

char in[1501][1501];

bool cswan[1501][1501];
bool cwater[1501][1501];
int r,c;

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
            if(0>nx || nx >= r || 0>ny || ny >=c) continue;
            if(cwater[nx][ny]) continue;    

            cwater[nx][ny] = true;
            if(in[nx][ny] == '.'){
                water.emplace(nx,ny);                
            }else { // 'X'
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
            int nx = x +dx[i];
            int ny = y +dy[i];
            if(0>nx || nx>=r || 0>ny || ny>=c) continue;
            if(cswan[nx][ny]) continue;
            
            cswan[nx][ny] = true;
            if(in[nx][ny] == '.'){
                swan.emplace(nx,ny);
            }else{ // 'X'
                n_swan.emplace(nx,ny);
            }
        }
    }
}

int main(){
    scanf("%d %d", &r, &c);
    int sx1,sy1,sx2,sy2;
    sx1=sy1=sx2=sy2=-1;

    queue<pair<int,int>> swan, water, n_swan, n_water;
    for(int i=0; i<r; i++){
        cin >> in[i];
        for(int j=0; j<c; j++){
            if(in[i][j] == 'L'){
                if(sx1==-1){
                    sx1 = i; sy1 = j;
                }else{
                    sx2 = i; sy2 = j;
                }
                in[i][j] = '.';
            }
            if(in[i][j] == '.'){
                water.emplace(i,j);
                cwater[i][j] = true;
            }
        }
    }
    swan.emplace(sx1,sy1);
    cswan[sx1][sy1] = true;
    int day=0;
    while(true){
        bfs_w(water, n_water);
        bfs_s(swan, n_swan);
        
        if(cswan[sx2][sy2]) {
            printf("%d", day);
            break;
        }
        day+=1;
        water = n_water;
        swan = n_swan;
        n_water = queue<pair<int,int>>();
        n_swan = queue<pair<int,int>>();
    }

    return 0;
}