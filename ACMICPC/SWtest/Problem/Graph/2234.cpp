#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int dist[51][51];
int rooms[51*51];
int in[51][51];
int n,m;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int bfs(int s, int e, int room){

    int cnt = 0;
    queue<pair<int,int>> q;
    q.emplace(s,e);
    dist[s][e] = room;
    while(!q.empty()){
        cnt+=1;
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0>nx || nx > m || 0>ny || ny > n) continue;
            if(in[x][y] & (1<<i)) continue;
            if(dist[nx][ny] == 0){
                q.emplace(nx,ny);
                dist[nx][ny] = room;
            }
        }
    }
    return cnt;
}


int main(){

    scanf("%d %d", &n, &m);
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &in[i][j]);
        }
    }

    int room = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            if(dist[i][j] == 0){
                room+=1;
                rooms[room] = bfs(i, j, room);
            }
        }
    }
    printf("%d\n", room);

    int ans = 0;
    for(int i=1; i<=room; i++){
        if(ans ==0 || ans < rooms[i]) ans = rooms[i]; 
    }

    printf("%d\n", ans);

    //brute - force
    int big = 0;
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            int x = i;
            int y = j;
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(0>nx || nx>=m || 0>ny || ny>=n)continue;
                if(dist[nx][ny] == dist[x][y])continue;
                if(in[x][y] & (1<<i)){
                    if(big < rooms[dist[x][y]] + rooms[dist[nx][ny]]){
                        big = rooms[dist[x][y]] + rooms[dist[nx][ny]];
                    }
                }
            }
        }
    }
    printf("%d", big);

    return 0;
}