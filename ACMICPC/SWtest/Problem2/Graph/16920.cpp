#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;

int dist[1001][1001];
int map[1001][1001];
queue<pair<int,int>> q[10];
queue<pair<int,int>> next_q[10];
int s[10];
int n,m,p;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void bfs(){
    while(true){
        bool ok = false; 
        for(int player=1; player<=p; player++){
            memset(dist, 0, sizeof(dist));
            while(!q[player].empty()){
                ok = true;
                int x,y;
                tie(x,y) = q[player].front();
                q[player].pop();
                if(dist[x][y] == s[player]){
                    next_q[player].emplace(x,y);
                }
                if(map[x][y] >0 && map[x][y] != player) continue;
                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx>=0 && nx<n && ny>=0 && ny<m){
                        if(map[nx][ny] == 0){
                            dist[nx][ny] = dist[x][y] + 1;
                            if(dist[nx][ny] <= s[player]){
                                q[player].emplace(nx,ny);
                                map[nx][ny] = player;
                            }
                        }
                    }
                }
            }
            q[player] = next_q[player];
            next_q[player] = queue<pair<int,int>>();
        }
        if(!ok){
            break;
        }
    }
    vector<int> p_m(p+1);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] > 0){
                p_m[map[i][j]] += 1;
            }
        }
    }
    for(int i=1; i<p_m.size(); i++){
        cout << p_m[i] << " ";
    }

}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >>p;
    for(int i=1; i<=p; i++)cin >> s[i];
    string str;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){
            if(str[j] == '.')map[i][j] = 0;
            else if(str[j] == '#')map[i][j] = -1;
            else map[i][j] = str[j] - '0';
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] > 0){
                q[map[i][j]].emplace(i,j);
            }
        }
    }
    bfs();
    
    return 0;
}