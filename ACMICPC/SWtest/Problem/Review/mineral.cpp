#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int n,m;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(int s, int e, vector<vector<bool>> &check, vector<string> in, vector<pair<int,int>> &group){

    queue<pair<int,int>> q;
    group.emplace_back(s,e);
    q.emplace(s,e);
    check[s][e] = true;
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny>=m)continue;
            if(check[nx][ny] == false && in[nx][ny] == 'x'){
                q.emplace(nx,ny);
                group.emplace_back(nx,ny);
                check[nx][ny] = true;
            }
        }
    }
}

void simulate(vector<string> &in){

    vector<vector<bool>> check(n, vector<bool>(m, false));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(in[i][j] == '.') continue;
            if(check[i][j]) continue;
            vector<pair<int,int>> group;
            bfs(i,j, check, in, group);
            
            vector<int> low(m, -1); // col-low-value
            for(auto &p : group){
                low[p.second] = max(low[p.second], p.first);
                in[p.first][p.second] = '.';
            }

            int lowest = n;
            for(int i,j=0; j<m; j++){
                if(low[j] == -1) continue;
                for(i=low[j]; i<n && in[i][j]=='.'; i++); // semicolon warning!
                lowest = min(lowest, i-low[j]-1);
            }
            

            for(auto &p : group){
                p.first += lowest;
                in[p.first][p.second] = 'x';
                check[p.first][p.second] = true;
            }
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin >> n >> m;
    vector<string> in(n);
    for(int i=0; i<n; i++){
        cin >> in[i];
    }

    int turn;
    cin >> turn;
    for(int i=0; i<turn; i++){
        int shoot;
        cin >> shoot;
        shoot = n - shoot;
        if(i%2 == 0){ // left
            for(int j=0; j<m; j++){
                if(in[shoot][j] == 'x'){
                    in[shoot][j] = '.';
                    break;
                }
            }
        }else{
            for(int j=m-1; j>=0; j--){
                if(in[shoot][j] == 'x'){
                    in[shoot][j] = '.';
                    break;
                }
            } 
        }
        simulate(in);
    }
    for(int i=0; i<n; i++){
        cout << in[i] << "\n";
    }
    return 0;
}