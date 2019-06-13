#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int N,M;

bool check[1001][1001];
int node[1001][1001];
int map[1001][1001];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
queue<pair<int, int>> q;

int count_number = 0;
void bfs(){

    int x = q.front().first;
    int y = q.front().second;
    check[x][y] = true;
    map[x][y] = 1;

    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<= nx && nx<M && 0<=ny && ny<N){
                if(map[nx][ny] == 0 && check[nx][ny] == false){
                    q.push(make_pair(nx, ny));
                    map[nx][ny] += map[x][y] + 1;
                    count_number = map[nx][ny]-1;
                    check[nx][ny] = true;
                }
            }
        }
    }
}

int main(){

    cin.sync_with_stdio(false);
    // cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cin>> node[i][j];
            if(node[i][j] == 1){
                map[i][j] = 1;
                q.push(make_pair(i, j));
            }else if (node[i][j] == -1)map[i][j] = -1;
        }
    }

    bfs();
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(map[i][j] == 0){
                cout << "-1";
                return 0;
            }
        }
    }
    cout << count_number;

    return 0;
    
}