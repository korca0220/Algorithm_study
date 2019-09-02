#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 5;
int dist[N][N][N];
int dx[] = {0,0,-1,1,0,0};
int dy[] = {-1,1,0,0,0,0};
int dz[] = {0,0,0,0,-1,1};
int ans = -1;
vector<vector<int>> clockwise(vector<vector<int>> &a){

    vector<vector<int>> temp(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
           temp[i][j] = a[N-j-1][i]; 
        }
    }
    return temp;
}   
int bfs(vector<vector<vector<int>>> &b){

    if(b[0][0][0] == 0) return -1;
    memset(dist, -1, sizeof(dist));
    queue<tuple<int,int,int>> q;
    dist[0][0][0] = 0;
    q.emplace(0,0,0);
    while(!q.empty()){
        int x,y,z;
        tie(x,y,z) = q.front();
        q.pop();
        for(int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(0<=nx && nx<N && 0<=ny && ny<N && 0<=nz && nz<N){
                if(dist[nx][ny][nz] == -1 && b[nx][ny][nz] == 1){
                    q.emplace(nx,ny,nz);
                    dist[nx][ny][nz]  = dist[x][y][z] + 1;
                }
            }
        }
    }
    return dist[N-1][N-1][N-1];
}
void go(vector<vector<vector<int>>> &b, int index){

    if(index == 5){
        int cur = bfs(b);
        if(cur != -1){
            if(ans==-1 || ans` > cur)ans = cur;
        }
        return ;
    }
    for(int i=0; i<4; i++){
        go(b, index+1);
        b[index] = clockwise(b[index]);
    }
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<vector<vector<int>>> in(N, vector<vector<int>>(N, vector<int>(N)));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            for(int k=0; k<N; k++){
                cin >> in[i][j][k];
            }
        }
    }
    vector<int> order;
    for(int i=0; i<N; i++)order.push_back(i);

    do{
        vector<vector<vector<int>>> b(N);
        for(int i=0; i<N; i++){
            b[order[i]] = in[i];
        }
        go(b, 0);
    }while(next_permutation(order.begin(), order.end()));    
    cout << ans;

    return 0;
}