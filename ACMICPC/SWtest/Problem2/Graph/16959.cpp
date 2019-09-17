#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
int map[10][10];
int dist[10][10][100][3];

int dx1[] = {-2,-1,1,2,2,1,-1,-2};
int dy1[] = {1,2,2,1,-1,-2,-2,-1};
int dx2[] = {0,0,1,-1};
int dy2[] = {1,-1,0,0};
int dx3[] = {1,1,-1,-1};
int dy3[] = {1,-1,1,-1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    memset(dist, -1, sizeof(dist));
    queue<tuple<int,int,int,int>> q;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >>map[i][j];
            map[i][j] -=1;
            if(map[i][j] == 0){
                for(int k=0; k<3; k++){
                    dist[i][j][0][k] = 0;
                    q.emplace(i,j, 0, k);
                }
            }
        }
    }
    int ans = -1;
    while(!q.empty()){
        int x,y,num,mal;
        tie(x,y,num,mal) = q.front(); q.pop();
        // 끝(n*n)칸에 도착한경우
        if(num == n*n-1){
            if(ans==-1 || ans>dist[x][y][num][mal]){
                ans = dist[x][y][num][mal];
            }
        }
        // 제자리에서 말을 바꾸는경우( +1초)
        for(int i=0; i<3; i++){
            if(mal == i) continue;
            if(dist[x][y][num][i] == -1){
                dist[x][y][num][i] = dist[x][y][num][mal] + 1;
                q.emplace(x,y,num,i);
            }
        }
        if(mal == 0){ // night
            for(int i=0; i<8; i++){
                int nx = x + dx1[i];
                int ny = y + dy1[i];
                if(nx>=0 && nx<n && ny>=0 && ny<n){
                    int n_num = num;
                    if(map[nx][ny] == num + 1){
                        n_num = num+1;
                    }
                    if(dist[nx][ny][n_num][mal] == -1){
                        dist[nx][ny][n_num][mal] = dist[x][y][num][mal] + 1;
                        q.emplace(nx,ny,n_num, mal);
                    }
                }
            }
        }else if(mal == 1){ //rook
            for(int i=0; i<4; i++){
                for(int l=1;;l++){
                    int nx = x + dx2[i] * l;
                    int ny = y + dy2[i] * l;
                    if(nx>=0 && nx<n && ny>=0 && ny<n){
                        int n_num = num;
                        if(map[nx][ny] == num+1){
                            n_num = num+1;
                        }
                        if(dist[nx][ny][n_num][mal] == -1){
                            dist[nx][ny][n_num][mal] = dist[x][y][num][mal] +1;
                            q.emplace(nx, ny, n_num, mal);
                        }
                    }else break;
                }
            }
        }else if(mal == 2){ // bishop
            for(int i=0; i<4; i++){
                for(int l=1;;l++){
                    int nx = x + dx3[i] * l;
                    int ny = y + dy3[i] * l;
                    if(nx>=0 && nx<n && ny>=0 && ny<n){
                        int n_num = num;
                        if(map[nx][ny] == num + 1){
                            n_num = num + 1;
                        }
                        if(dist[nx][ny][n_num][mal] == -1){
                            dist[nx][ny][n_num][mal] = dist[x][y][num][mal] + 1;
                            q.emplace(nx,ny,n_num,mal);
                        }
                    }else break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}