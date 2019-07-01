#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
#include <tuple>
#include <cstring>
using namespace std;

char node[101][101];
int water[101][101];
int dist[101][101];

int R,C;
queue<pair<int,int>> wat;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void water_bfs(){

    while(!wat.empty()){
        int x,y;
        tie(x,y) = wat.front();
        wat.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= R || 0 > ny || ny >= C)continue;
            if(water[nx][ny] != -1)continue;
            if(node[nx][ny] == 'D')continue;
            if(node[nx][ny] == 'X')continue;
            wat.push(make_pair(nx,ny));
            water[nx][ny] = water[x][y] +1;
        }
        
    }
}

void find_bfs(int start_x, int start_y){
    
    queue<pair<int, int>> q;
    dist[start_x][start_y] = 0;
    q.push(make_pair(start_x, start_y));
    while(!q.empty()){
        int x, y;
        tie(x,y) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 > nx || nx >= R || 0 > ny || ny >= C)continue;
            if(dist[nx][ny] != -1)continue;
            if(node[nx][ny] == 'X')continue;
            if(water[nx][ny] != -1 && dist[x][y]+1 >= water[nx][ny])continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx, ny));
        }
    }
}

int main(){

    scanf("%d %d", &R, &C);
    memset(water, -1, sizeof(water));
    memset(dist, -1, sizeof(dist));
    
    int start_x, start_y;
    int des_x, des_y;
    for(int i=0; i<R; i++){
        scanf("%s", node[i]);
        for(int j=0; j<C; j++){
            if(node[i][j] == '*'){
                wat.push(make_pair(i,j));
                water[i][j] = 0;
            }
            else if(node[i][j] == 'S'){
                start_x = i; start_y = j;
            }
            else if(node[i][j] == 'D'){
                des_x = i; des_y = j;
            }
        }
    }
    water_bfs();
    find_bfs(start_x, start_y);

    if(dist[des_x][des_y] != -1)printf("%d", dist[des_x][des_y]);
    else printf("KAKTUS");

    return 0;
}