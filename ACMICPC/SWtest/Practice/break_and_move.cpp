#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

const int MAX = 2001;
int dist[MAX][MAX][2];
int node[MAX][MAX];

int N,M;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void bfs(){

    queue<tuple<int, int, int>> q;
    dist[0][0][0] = 1;
    q.push(make_tuple(0,0,0));
    while(!q.empty()){
        int x,y,z;
        tie(x,y,z) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= N || 0 > ny || ny >= M)continue;
            if(node[nx][ny] == 0 && dist[nx][ny][z] == 0){
                dist[nx][ny][z] += dist[x][y][z] + 1;
                q.push(make_tuple(nx,ny,z));
            }
            if(node[nx][ny] == 1 && dist[nx][ny][z+1] == 0 && z == 0){
                dist[nx][ny][z+1] += dist[x][y][z] + 1;
                q.push(make_tuple(nx, ny, z+1));
            }
        }
    }

}
int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%1d", &node[i][j]);
        }
    }
    bfs();
    if(dist[N-1][M-1][0] != 0 && dist[N-1][M-1][1] != 0){
        printf("%d", min(dist[N-1][M-1][0], dist[N-1][M-1][1]));
    }else if(dist[N-1][M-1][0] != 0){
        printf("%d", dist[N-1][M-1][0]);
    }else if(dist[N-1][M-1][1] != 0){
        printf("%d", dist[N-1][M-1][1]);
    }else printf("-1");

    return 0;
}