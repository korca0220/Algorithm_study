#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int rooms[51*51];
int dist[51][51];
int in[51][51];
int n,m;

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int bfs(int s, int e, int room){

    queue<pair<int,int>> q;
    q.emplace(s,e);
    dist[s][e] = room;
    int cnt=0;
    while(!q.empty()){
        cnt += 1;
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>= n || ny<0 || ny>=m) continue;
            if(in[x][y] & (1<<i)) continue ; // true인경우 벽
            if(dist[nx][ny] != 0) continue;
            q.emplace(nx,ny);
            dist[nx][ny] = room; 
        }
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> m >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> in[i][j];
        }
    }

    int room = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dist[i][j] == 0){
                room += 1;
                rooms[room] = bfs(i,j, room);
            }
        }
    }
    cout << room << "\n"; //1. 방의 개수

    int ans = -1;
    for(int i=1; i<=room; i++){
        if(ans==-1 || ans< rooms[i]) ans = rooms[i];
    }
    cout << ans << "\n"; //2. 가장 큰 방

    int big = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int x = i;
            int y = j;
            for(int k=0; k<4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx<0 || nx>=n || ny<0 || ny>=m) continue;
                if(dist[x][y] == dist[nx][ny]) continue;
                if(in[x][y] & (1<<k)){
                    if(big < rooms[dist[x][y]] + rooms[dist[nx][ny]]){
                        big = rooms[dist[x][y]] + rooms[dist[nx][ny]];
                    }
                }
            }
        }
    }
    cout << big;
    return 0;
}