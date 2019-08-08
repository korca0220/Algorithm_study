#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#include <cstring>
using namespace std;

int dist[201][201][31];
int in[201][201];
int W,H;
int K;

int dx[] = {0,0,-1,1,-1,-2,-2,-1,1,2,2,1};
int dy[] = {-1,1,0,0,-2,-1,1,2,2,1,-1,-2};
int cost[] = {0,0,0,0,1,1,1,1,1,1,1,1,};

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
            int nz = z + cost[i];
            if(0>nx || nx >=H || 0>ny || ny >= W || nz > K) continue;
            if(in[nx][ny] == 1) continue;
            if(dist[nx][ny][nz] != -1)continue;
            q.emplace(nx,ny,nz);
            dist[nx][ny][nz] = dist[x][y][z] + 1;
        }
    }
    int ans = -1;
    for(int i=0; i<=K; i++){
        int temp = dist[H-1][W-1][i];
        if(temp == -1) continue;
        if(ans == -1 || ans > temp) ans = temp;
    }
    printf("%d", ans);
}

int main(){
    scanf("%d", &K);
    scanf("%d %d", &W, &H);
    for(int i=0; i<H; i++){
        for(int j=0; j<W; j++){
            scanf("%d", &in[i][j]);
        }
    }
    memset(dist, -1, sizeof(dist));
    bfs();

    return 0;
}