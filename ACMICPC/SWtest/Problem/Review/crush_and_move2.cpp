#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

int dist[1001][1001][11];
int n,m,k;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0}; 

void bfs(vector<string> &in){

    queue<tuple<int, int, int>> q; 
    q.emplace(0,0,k);
    dist[0][0][k] = 1;
    while(!q.empty()){
        int x,y,z;
        tie(x,y,z) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
            if(dist[nx][ny][z] == -1 && in[nx][ny] == '0'){
                q.emplace(nx,ny,z);
                dist[nx][ny][z] = dist[x][y][z] +1;
            }
            if(dist[nx][ny][z-1] == -1 && in[nx][ny] == '1' && z-1>=0){
                q.emplace(nx,ny,z-1);
                dist[nx][ny][z-1] = dist[x][y][z] + 1;
            }
        }

    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    vector<string> in(n);
    for(int i=0; i<n; i++)cin >> in[i];

    memset(dist, -1, sizeof(dist));
    bfs(in);

    int ans = -1;
    for(int i=0; i<=k; i++){
        int temp = dist[n-1][m-1][i];
        if(temp == -1) continue;
        if(ans == -1 || ans > temp){
            ans = temp;  
        }  
    }
    cout << ans ;

    return 0;
} 