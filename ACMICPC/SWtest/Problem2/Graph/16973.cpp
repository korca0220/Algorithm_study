#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include <utility>
#include <cstring>
using namespace std;

int n,m;
int h,w,Sr,Sc,Fr,Fc;
int map[1001][1001];
int dist[1001][1001];
int s[1001][1001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int sum_quad(int x1, int y1, int x2, int y2){
    return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n>>m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >>map[i][j];
        }
    } 
    cin >> h >>w >> Sr >> Sc >> Fr >> Fc;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + map[i][j];
        }
    }
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    dist[Sr][Sc] = 0;
    q.emplace(Sr,Sc);
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(1<=nx && nx+h-1 <=n && 1<=ny && ny+w-1<=m){
                if(sum_quad(nx,ny, nx+h-1, ny+w-1) ==0){
                    if(dist[nx][ny] == -1){
                        q.emplace(nx,ny);
                        dist[nx][ny] = dist[x][y] + 1;
                    }
                }
            }
        }
    }
    cout << dist[Fr][Fc];

    return 0;
}