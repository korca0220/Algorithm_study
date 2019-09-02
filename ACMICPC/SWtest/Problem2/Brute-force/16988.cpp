#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

int map[21][21];
int n,m;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int bfs(){

    vector<vector<int>> dist(n, vector<int>(m, -1));
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] ==2 && dist[i][j] == -1){
                bool pass = true;
                queue<pair<int,int>> q;
                q.emplace(i,j);
                dist[i][j] = 0;
                int cur = 0;
                while(!q.empty()){
                    cur += 1;
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for(int i=0; i<4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(nx>=0 && nx<n && ny>=0 && ny<m){
                            if(map[nx][ny] == 0){
                                pass = false;
                            }else if(map[nx][ny] == 2 && dist[nx][ny] == -1){
                                q.emplace(nx,ny);
                                dist[nx][ny] = dist[x][y] + 1;
                            }
                        }
                    }
                }
                if(pass)ans += cur;
            }
        }
    }
    return ans; 
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<pair<int,int>> zero;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 0)zero.emplace_back(i,j);
        }
    }
    int len = zero.size();
    if(len < 2){
        cout << "0";
        return 0;
    }
    int ans = 0;
    for(int i=0; i<len-1; i++){
        pair<int,int> one = zero[i];
        for(int j=i+1; j<len; j++){        
            pair<int,int> two = zero[j];

            map[one.first][one.second] = 1;
            map[two.first][two.second] = 1;

            int cur = bfs();
            if(cur != -1){
                if(ans < cur) ans = cur;
            }
            map[two.first][two.second] = 0;
        }
        map[one.first][one.second] = 0;
    }
    cout << ans;

    return 0;
}