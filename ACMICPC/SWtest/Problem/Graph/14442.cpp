#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>
using namespace std;

int dist[1001][1001][11];

int n,m,k;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(vector<string> &in){

    queue<tuple<int,int,int>> q;
    q.emplace(0,0,k);
    dist[0][0][k] = 1;
    while(!q.empty()){
        int a,b,c;
        tie(a,b,c) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = a + dx[i];
            int ny = b + dy[i];
            if(0>nx || nx >= n || 0>ny || ny >= m) continue;
            if(in[nx][ny] == '0' && dist[nx][ny][c] == 0){
                q.emplace(nx,ny,c);
                dist[nx][ny][c] = dist[a][b][c] + 1;
            }
            if(in[nx][ny] == '1' && c-1>=0 && dist[nx][ny][c-1] == 0){
                q.emplace(nx,ny,c-1);
                dist[nx][ny][c-1] = dist[a][b][c] + 1;
            }
        }
    }
    int ans = -1;
    for(int i=0; i<=k; i++){
        int temp = dist[n-1][m-1][i];
        if(temp ==0) continue;
        if(ans == -1 || ans > temp) ans = temp;
    }
    printf("%d", ans);

}

int main(){
    scanf("%d %d %d", &n, &m, &k);
    vector<string> in(n);

    for(int i=0; i<n; i++){
        cin >> in[i];
    }

    bfs(in);

    return 0;
}