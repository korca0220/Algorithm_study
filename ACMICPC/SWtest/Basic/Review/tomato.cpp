#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

bool check[1001][1001];
int node[1001][1001];
int dist[1001][1001];

int n, m;
queue<pair<int, int>> q;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0 ,1};
void bfs(){

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx <n && 0<= ny && ny <m){
                if(check[nx][ny] == false && node[nx][ny] == 0){
                    dist[nx][ny] += dist[x][y] + 1;
                    check[nx][ny] = true;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }
}

int main(){
    scanf("%d %d", &m, &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &node[i][j]);
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(node[i][j] == 1){
                q.push(make_pair(i, j));
                check[i][j] = true;
                dist[i][j] = 1;
            }else if(node[i][j] == -1)dist[i][j] = -1;
        }
    }
    bfs();
    int mx = -98654321;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(dist[i][j] == 0){
                printf("-1");
                return 0;
            }
            mx = max(mx, dist[i][j]);
        }
    }
    printf("%d", mx-1);

    return 0;
}