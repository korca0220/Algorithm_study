#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <tuple>
#include <set>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;

int map[1001][1001];
bool dist[1001][1001];
int group[1001][1001];
vector<int> group_size;
int n,m;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void bfs(int i, int j){
    int g = group_size.size();
    queue<pair<int,int>> q;
    dist[i][j] = true;
    group[i][j] = g;
    q.emplace(i,j);
    int cnt = 1;
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int t=0; t<4; t++){
            int nx = x + dx[t];
            int ny = y + dy[t];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(map[nx][ny] == 0 && dist[nx][ny] == 0){
                    q.emplace(nx,ny);
                    dist[nx][ny] = true;
                    group[nx][ny] = g;
                    cnt+=1;
                }
            }
        }
    }
    group_size.push_back(cnt);
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int k=1;
    queue<pair<int,int>> wall;
    for(int i=0; i<n; i++){
        string str;
        cin >> str;
        for(int j=0; j<m; j++){   
            map[i][j] = str[j]-'0';
            if(map[i][j] == 1)wall.emplace(i,j);
        }
    }
    memset(dist, false, sizeof(dist));
    memset(group, -1, sizeof(group));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 0 && dist[i][j] == false){
                bfs(i,j);
            }
       }
    }
    while(!wall.empty()){
        int i ,j;
        tie(i,j) = wall.front();
        wall.pop(); 
        int last = -1;
        set<int> near;
        for(int t=0; t<4; t++){
            int nx = i + dx[t];
            int ny = j + dy[t];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(map[nx][ny] == 0){
                    near.insert(group[nx][ny]);
                }
            }
        }
        for(int p : near){
            map[i][j] += group_size[p];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cout << map[i][j]%10;
        }
        cout << "\n";
    }
    return 0;
}