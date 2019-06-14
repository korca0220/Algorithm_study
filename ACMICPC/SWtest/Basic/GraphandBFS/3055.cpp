#include <iostream>
#include <queue>
#include <utility>
#include <string>
#include <tuple>
#include <cstring>
using namespace std;

int R,C;
char node[100][100];
int water[100][100];
int dist[100][100];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

queue<pair<int, int>> q;

void bfs_water(){

    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx>=R || 0 > ny || ny>=C){
                continue;
            }
            if(water[nx][ny] != -1)continue;
            if(node[nx][ny] == 'X')continue;
            if(node[nx][ny] == 'D')continue;
            q.push(make_pair(nx, ny));
            water[nx][ny] = water[x][y] + 1;
        }
    }
}

void bfs_find(int start_x, int start_y){

    q.push(make_pair(start_x, start_y));
    dist[start_x][start_y] = 0;
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx>=R || 0 > ny || ny >= C){
                continue;
            }
            if(node[nx][ny] == 'X')continue;
            if(dist[nx][ny] != -1 )continue;
            if(water[nx][ny] != -1 && dist[x][y]+1 >= water[nx][ny])continue;
            q.push(make_pair(nx, ny));
            dist[nx][ny] = dist[x][y] + 1;
        }
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    memset(dist, -1, sizeof(dist));
    memset(water, -1, sizeof(water));
    cin >> R >> C;
    for(int i=0; i<R; i++){
        cin >> node[i];
    }

    int des_x, des_y;
    int start_x, start_y;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(node[i][j] == '*'){
                q.push(make_pair(i,j));
                water[i][j] = 0;
            }
            else if(node[i][j] == 'S'){
                start_x=i; start_y=j;    
            }
            else if(node[i][j] == 'D'){
                des_x=i; des_y=j;
            }
        }
    }
    bfs_water();
    bfs_find(start_x, start_y);

    if(dist[des_x][des_y] == -1) cout << "KAKTUS\n";
    else cout << dist[des_x][des_y] << "\n";

    return 0;
}
