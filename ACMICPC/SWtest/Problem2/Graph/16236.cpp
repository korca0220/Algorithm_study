#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
tuple<int,int,int> bfs(vector<vector<int>> &a, int i, int j, int size ){

    vector<vector<int>> dist(n, vector<int>(n, -1));
    queue<pair<int,int>> q;
    vector<tuple<int,int,int>> ans;
    q.emplace(i,j);
    dist[i][j] = 0;
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        for(int k=0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx>=0 && nx<n && ny>=0 && ny<n){
                bool ok  = false;
                bool eat = false;
                if(dist[nx][ny] == -1){
                    if(a[nx][ny] == 0) ok = true;
                    else if(size > a[nx][ny]) ok=eat=true;
                    else if(size == a[nx][ny]) ok = true;

                    if(ok){
                        q.emplace(nx,ny);
                        dist[nx][ny] = dist[x][y] + 1;
                        if(eat){
                            ans.emplace_back(dist[nx][ny], nx, ny);
                        }
                    }
                }
            }
        }
    }
    if(ans.empty()){
        ans.emplace_back(-1,-1,-1);
    }else{
        sort(ans.begin(), ans.end());
    }
    return ans[0];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<vector<int>> in(n, vector<int>(n));
    int x,y;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> in[i][j];
            if(in[i][j] == 9){
                tie(x,y) = make_pair(i,j);
                in[x][y] = 0;
            }
        }
    }

    int size = 2;
    int exp = 0;
    int ans = 0;
    while(true){
        int dist,nx,ny;
        tie(dist,nx,ny) = bfs(in, x,y, size);
        if(dist == -1)break;
        in[nx][ny] = 0;
        ans += dist;
        exp +=1;
        if(exp == size){
            size +=1;
            exp = 0;
        }
        tie(x,y) = make_pair(nx,ny);
    }
    cout << ans;

    return 0;
}