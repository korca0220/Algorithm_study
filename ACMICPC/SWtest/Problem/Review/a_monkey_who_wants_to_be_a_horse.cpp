#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <utility>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int n,m,k;
int dist[201][201][31];
int in[201][201];

int dx[] = {0,0,-1,1,-1,-2,-2,-1,1,2,2,1};
int dy[] = {-1,1,0,0,-2,-1,1,2,2,1,-1,-2};
int cost[] = {0,0,0,0,1,1,1,1,1,1,1,1};

void bfs(){

    queue<tuple<int,int,int>> q;
    q.emplace(0,0,0);
    dist[0][0][0] = 0;
    while(!q.empty()){
        int x,y,z;
        tie(x,y,z) = q.front();
        q.pop();
        for(int i=0; i<12; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int ncost = z + cost[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m || ncost >k) continue;
            if(dist[nx][ny][ncost] != -1) continue;
            if(in[nx][ny] == 1) continue;
            q.emplace(nx,ny, ncost);
            dist[nx][ny][ncost] = dist[x][y][z] + 1;
        }
    }
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k;
    cin >> m >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> in[i][j];
        }
    }
    memset(dist, -1, sizeof(dist));
    bfs();

    int ans = -1;
    for(int i=0; i<=k; i++){
        int temp = dist[n-1][m-1][i];
        if(temp == -1) continue;
        if(ans == -1 || ans > temp) ans = temp;
    }
    cout << ans;

    return 0;
}