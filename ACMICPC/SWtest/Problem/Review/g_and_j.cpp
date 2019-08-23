#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;

int n,m;
int in[10][10];
int dist[10][10][20];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool checkBridge(int i, int j){
    bool garo = false;
    if(j-1 >=0 && in[i][j-1] == 0) garo = true;
    if(j+1 < n && in[i][j+1] == 0) garo = true;
    bool sero = false;
    if(i-1 >=0 && in[i-1][j] == 0) sero = true;
    if(i+1 < n && in[i+1][j] == 0) sero = true;
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
        if(in[x][y] >=2 && t%in[x][y] != 0){ //다리 위에 있고, 아직 주기가 안된경우
            int nt = (t+1)%in[x][y];
            if(dist[x][y][nt] == -1){
                dist[x][y][nt] = dist[x][y][t] + 1;
                q.emplace(x,y,nt);
            }
        }else{
            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx<0 || nx>=n || ny<0 || ny>=n) continue;
                if(in[x][y] >=2 && in[nx][ny] >=2) continue; // 오작교를 연속 두번
                if(in[nx][ny] >=1){
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
        if(dist[n-1][n-1][i] == -1) continue;
        if(ans == -1 || ans > dist[n-1][n-1][i]){
            ans = dist[n-1][n-1][i];
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> in[i][j];
        }
    }

    int ans = -1;   
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(in[i][j] == 0 && checkBridge(i,j)){
                in[i][j] = m;
                int temp = bfs();
                if(temp != -1){
                    if(ans==-1 || ans>temp) ans = temp;
                }
               in[i][j] = 0;
            }
        }
    }
    cout << ans;

    return 0;
}