#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(vector<string> &in, int s, int e, int des_x, int des_y){

    int n = in.size();
    int m = in[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1));
    
    queue<pair<int,int>> q;
    q.push(make_pair(s,e));
    dist[s][e] = 0;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            while(0<=nx && nx < n && 0<=ny && ny < m){
                if(in[nx][ny] == '*')break;
                if(dist[nx][ny] == -1){
                    q.push(make_pair(nx,ny));
                    dist[nx][ny] = dist[x][y] + 1;
                }
                nx += dx[i];
                ny += dy[i];
            }
        }
    }
    printf("%d", dist[des_x][des_y]-1);
}

int main(){
    int n,m;
    scanf("%d %d", &m, &n);

    vector<string> in(n);
    int x1,y1,x2,y2;
    x1=y1=x2=y2=-1;
    for(int i=0; i<n; i++){
        cin >> in[i];
        for(int j=0; j<m; j++){
            if(in[i][j] == 'C'){
                if(x1 == -1){
                    x1 = i;
                    y1 = j; 
                }else{
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    bfs(in, x1,y1,x2,y2);

    return 0;
}