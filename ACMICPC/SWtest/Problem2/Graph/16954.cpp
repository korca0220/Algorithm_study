#include <iostream>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int n = 8;
vector<string> map(n);
bool dist[8][8][9];
int dx[] = {0,0,-1,1,0,-1,-1,1,1};
int dy[] = {-1,1,0,0,0,-1,1,1,-1};
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<n; i++){
        cin >> map[i];
    }

    memset(dist, false, sizeof(dist));
    queue<tuple<int,int,int>> q;
    q.emplace(n-1, 0, 0);
    dist[n-1][0][0] = true;
    bool ok = false;
    while(!q.empty()){
        int x,y,z;
        tie(x,y,z) = q.front();
        q.pop();
        if(x == 0 && y == n-1) ok = true;
        for(int i=0; i<9; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = min(z+1, 8);
            if(nx>=0 && nx<n && ny>= 0 && ny<n){
                if(nx-z >= 0 && map[nx-z][ny] == '#') continue; // 다음 이동 위치 벽의 존재
                if(nx-z-1 >= 0 && map[nx-z-1][ny] == '#') continue; // 1초후 벽의 상태
                if(dist[nx][ny][nz] == false){
                    q.emplace(nx,ny,nz);
                    dist[nx][ny][nz] = true; 
                }
            }
        }
    }
    cout << (ok?"1":"0");
    return 0;
}