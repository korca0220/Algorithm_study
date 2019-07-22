#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

void bfs(vector<string> &a, int n, int k){

    vector<vector<int>> dist(2, vector<int>(n, -1));
    vector<pair<int, int>> dirs = {{0,1}, {0,-1}, {1,k}};

    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    dist[0][0] = 0;

    bool arrival = false;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(auto dir : dirs){
            int dx = dir.first;
            int dy = dir.second;
            int nx = (x+dx)%2;
            int ny = y+dy;
            if(ny >= n){
                arrival = true;
                break;
            }
            if(ny < 0 ) continue;
            if(a[nx][ny] == '0') continue;
            if(dist[nx][ny] != -1)continue;
            if(ny < dist[x][y] + 1)continue;
            q.push(make_pair(nx, ny));
            dist[nx][ny] = dist[x][y] + 1;
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