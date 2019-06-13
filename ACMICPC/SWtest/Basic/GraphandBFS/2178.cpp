#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
#include <string>
using namespace std;

int N,M;

bool check[100][100];
int node[100][100];
int dist[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};


void bfs(int x, int y){

    queue<pair<int,int>> q;
    q.push(make_pair(x, y));
    check[x][y] = true;
    dist[x][y] = 1;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(0<=8 && nx<N && 0<=ny && ny<M){
                if(node[nx][ny] == 1 && check[nx][ny] == false){
                    q.push(make_pair(nx, ny));
                    dist[nx][ny] += dist[x][y] + 1;
                    check[nx][ny] = true;
                }
            }
        }
    }
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        for(int j=0; j<M; j++){
            if(str[j]=='0') node[i][j] = 0;
            else node[i][j] = 1;
        }
    }
    bfs(0,0);
    cout << dist[N-1][M-1]<< "\n";

    return 0;
}