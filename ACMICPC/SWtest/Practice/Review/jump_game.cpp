#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

void bfs(vector<string> &in, int n, int k){

    vector<pair<int,int>> dirs = {{0,1}, {0,-1}, {1,k}};
    vector<vector<int>> dist(2, vector<int>(n, -1));

    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    dist[0][0] = 0;
    bool arrival = false;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(auto dir : dirs){
            int nx = (x + dir.first)%2;
            int ny = y + dir.second;
            if(ny >= n){
                arrival = true;
                break;
            }else{
                if(in[nx][ny] == '0') continue;
                if(dist[nx][ny] != -1) continue ;
                if(ny < dist[x][y] + 1) continue;
                q.push(make_pair(nx,ny));
                dist[nx][ny] = dist[x][y] + 1;
            }
        }
        if(arrival)break;
    }
    printf(arrival?"1":"0");
}

int main(){
    int n,k;
    scanf("%d %d", &n, &k);

    vector<string> in(2);
    for(int i=0; i<2; i++){
        cin >> in[i];
    }
    bfs(in, n, k);

    return 0;
}