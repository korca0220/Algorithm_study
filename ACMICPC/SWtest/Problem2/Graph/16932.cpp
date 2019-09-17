#include <tuple>
#include <queue>
#include <vector>
#include <set>
#include <utility>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int map[1001][1001];
int group[1001][1001];
vector<int> group_size;
bool check[1001][1001];
int n,m;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
void bfs(int i, int j){

    int g = group_size.size();
    queue<pair<int,int>> q;
    q.emplace(i,j);
    check[i][j] = true;
    group[i][j] = g;
    int cnt =0;
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        cnt +=1;
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(map[nx][ny] == 1 && check[nx][ny] == false){
                    q.emplace(nx,ny);
                    group[nx][ny] = g;
                    check[nx][ny] = true;
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
    queue<pair<int,int>> zero;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
            if(map[i][j] == 0 )zero.emplace(i,j);
        }
    }
    memset(group, -1 ,sizeof(group));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1 && check[i][j] == false){
                bfs(i,j);
            }
        }
    }
    while(!zero.empty()){
        int x,y;
        tie(x,y) = zero.front();
        zero.pop();
        set<int> near;
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(map[nx][ny] == 1){
                    near.insert(group[nx][ny]);
                }
            }
        }
        for(int p:near){
            map[x][y] += group_size[p];
        }
    }
    int ans = -1;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ans==-1 || ans<map[i][j])ans=map[i][j];
        }
    }
    cout << ans+1;

    return 0;
}