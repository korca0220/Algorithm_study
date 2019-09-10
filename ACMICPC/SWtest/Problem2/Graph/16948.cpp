#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dist[201][201];
int dx[] = {-2, -2 ,0 ,0, 2, 2};
int dy[] = {-1, 1, -2, 2, -1, 1};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int x1,x2,y1,y2;
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;

    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    dist[x1][y1] = 0;
    q.emplace(x1,y1);
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<6; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx >= 0 && nx < n && ny>=0 && ny<n){
                if(dist[nx][ny] == -1){
                    q.emplace(nx,ny);
                    dist[nx][ny] = dist[x][y] + 1;
                }
            }
        }
    }
    cout << dist[x2][y2];

    return 0;
}