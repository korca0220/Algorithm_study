#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int map[9][9];
int copy_m[9][9];
int n,m;
int wall = 0;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(){

    queue<pair<int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            copy_m[i][j] = map[i][j];
            if(copy_m[i][j] == 2){
                q.push(make_pair(i,j));
            }
        }
    }

    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0<= nx && nx < n && 0<=ny && ny < m){
                if(copy_m[nx][ny] == 0){
                    copy_m[nx][ny] = 2;
                    q.push(make_pair(nx,ny));
                }
            }
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(copy_m[i][j] == 0)cnt+=1;
        }
    }
    if(wall < cnt) wall = cnt;

}

int main(){

    scanf("%d %d", &n, &m);
    vector<pair<int,int>> zero;
    int sx, sy;
    sx=sy=-1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
            if(map[i][j] == 0){
                zero.push_back(make_pair(i,j));
            }
        }
    }

    for(int i=0; i<zero.size()-2; i++){
        for(int j=i+1; j<zero.size()-1; j++){
            for(int k=j+1; k<zero.size(); k++){
                pair<int,int> one = zero[i];
                pair<int,int> two = zero[j];
                pair<int,int> three = zero[k];

                map[one.first][one.second] = 1;
                map[two.first][two.second] = 1;
                map[three.first][three.second] = 1;

                bfs();
                map[one.first][one.second] = 0;
                map[two.first][two.second] = 0;
                map[three.first][three.second] = 0;
            }
        }
    }
    printf("%d", wall);

    return 0;
}