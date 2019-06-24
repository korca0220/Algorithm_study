#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int n,m;
bool check[101][101];
int node[101][101];
int dist[101][101];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int bfs(){

    check[0][0] = true;
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    dist[0][0] = 1;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < n && 0 <= ny && ny < m){
                if(check[nx][ny] == false && node[nx][ny] == 1){
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] += dist[x][y] + 1;
                }
            }
        }
    }
    return dist[n-1][m-1];
}
int main(){

    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &node[i][j]);
        }
    }

    printf("%d", bfs());


    return 0;
}