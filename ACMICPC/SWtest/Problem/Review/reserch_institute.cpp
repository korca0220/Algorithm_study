#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int n,m;
int in[9][9];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int ans = -1;
void bfs(){

    queue<pair<int,int>> q;
    vector<vector<int>> copy_m(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            copy_m[i][j] = in[i][j];
            if(copy_m[i][j] == 2){
                q.emplace(i,j);
            }
        }
    }
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<n && ny>=0 && ny<m){
                if(copy_m[nx][ny] == 0){
                    copy_m[nx][ny] = 2;
                    q.emplace(nx,ny);
                }
            }
        }
    }

    int total = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(copy_m[i][j] == 0)total+=1;
        }
    }
    if(ans<total) ans = total;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<pair<int,int>> sequre;
    vector<pair<int,int>> virus;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> in[i][j];
            if(in[i][j] == 0)sequre.emplace_back(i,j);
        }
    }
    int size = sequre.size();
    for(int i=0; i<size-2; i++){
        for(int j=i+1; j<size-1; j++){
            for(int k=j+1; k<size; k++){
                pair<int,int> one = sequre[i];
                pair<int,int> two = sequre[j];
                pair<int,int> three = sequre[k];

                in[one.first][one.second] = 1;
                in[two.first][two.second] = 1;
                in[three.first][three.second] = 1;
                bfs();
                in[one.first][one.second] = 0;
                in[two.first][two.second] = 0;
                in[three.first][three.second] = 0;
            }
        }
    }
    cout << ans;

    return 0;
}