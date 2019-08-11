#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int in[11][11];
int dist[10][10][20];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool ok(int i, int j){
    bool garo = false;
    if(j-1 >= 0 && in[i][j-1] ==0) garo =true;
    if(j+1 < N && in[i][j+1] == 0) garo = true;
    bool sero = false;
    if(i-1 >= 0 && in[i-1][j] == 0) sero = true;
    if(j+1 < N && in[i+1][j] == 0) sero = true;
    return !(garo && sero);
}

int bfs(){

    memset(dist, -1, sizeof(dist));
    queue<tuple<int,int,int>> q;
    q.emplace(0,0,0);
    dist[0][0][0] = 0;
    while(!q.empty()){
        int x,y,t;
        tie(x,y,t) = q.front();
        q.pop();
        // 오작교 위
        if(in[x][y] >=2 && t%in[x][y] != 0){
            int nt = (t+1)%in[x][y];
            if(dist[x][y][nt] == -1){
                dist[x][y][nt] = dist[x][y][t] + 1;
                q.emplace(x,y,nt);
            }
        }else{
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0>nx || nx>=N || 0>ny || ny>=N) continue;
                if(in[x][y] >=2 && in[nx][ny] >= 2) continue; // 두번 연속 오작교 X
                if(in[nx][ny] >=1){ // 오작교 or 길
                    int nt = (dist[x][y][t]+1)%in[nx][ny];
                    if(dist[nx][ny][nt] == -1){
                        dist[nx][ny][nt] = dist[x][y][t] + 1;
                        q.emplace(nx,ny,nt); 
                    }
                }
            }            
        }            
    }

    int ans = -1;
    for(int i=0; i<20; i++){
        if(dist[N-1][N-1][i] == -1) continue;
        if(ans==-1 || dist[N-1][N-1][i] < ans){
            ans = dist[N-1][N-1][i];
        }
    }
    return ans;
}

int main(){
    scanf("%d %d", &N, &M);
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &in[i][j]);
        }
    }

    int ans = -1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(in[i][j] == 0 && ok(i,j)){
                in[i][j] = M;
                int now = bfs();
                if(now != -1){
                    if(ans == -1 || ans > now){
                        ans = now;
                    }
                }
                in[i][j] = 0;
            }
        }
    }
    printf("%d", ans);

    return 0;
}