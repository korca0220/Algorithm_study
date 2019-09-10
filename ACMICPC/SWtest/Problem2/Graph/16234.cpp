#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
using namespace std;

int n,l,r;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool bfs(vector<vector<int>> &a, int l, int r){

    vector<vector<bool>> check(n, vector<bool>(n, false));
    bool ok = false;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == false){
                queue<pair<int,int>> q;
                vector<pair<int,int>> p_print;
                p_print.emplace_back(i,j);
                q.emplace(i,j);
                check[i][j] = true;
                int sum = a[i][j];
                while(!q.empty()){
                    int x,y;
                    tie(x,y) = q.front();
                    q.pop();
                    for(int i=0; i<4; i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        if(nx>=0 && nx< n && ny>=0 && ny < n){
                            if(check[nx][ny])continue;
                            int diff = abs(a[x][y] - a[nx][ny]);
                            if(l <= diff && diff <= r){
                                ok = true;
                                q.emplace(nx,ny);
                                p_print.emplace_back(nx,ny);
                                check[nx][ny] = true;
                                sum += a[nx][ny];
                            }
                        }
                    }
                }
                int value = sum / p_print.size();
                while(!p_print.empty()){
                    int x,y;
                    tie(x,y) = p_print.back();
                    a[x][y] = value;
                    p_print.pop_back();
                }
            }
        }
    }
    return ok;
}

int main(){
    ios::sync_with_stdio(false);
    // cin.tie(NULL);

    cin >> n >> l >> r;
    vector<vector<int>> in(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> in[i][j];
        }
    }

    int ans = 0;
    while(true){
        if(bfs(in,l,r)){
            ans +=1;
        }else break;
    }
    cout << ans;

    return 0;
}