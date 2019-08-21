#include <tuple>
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <utility>
using namespace std;

int n,m;
bool check[250][250];
char in[250][250];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

pair<int,int> getFind(int x, int y){

    queue<pair<int,int>> q;
    q.emplace(x,y);
    check[x][y] = true;
    int v=0, o=0;
    while(!q.empty()){
        int x,y;
        tie(x,y) = q.front();
        q.pop();
        if(in[x][y] == 'v')v+=1;
        else if(in[x][y] == 'o')o+=1;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=n || ny<0 || ny >=m) continue;
            if(check[nx][ny] != false) continue;
            if(in[nx][ny] == '#') continue;
            q.emplace(nx,ny);
            check[nx][ny] = true;
        }
    }
    if(v>=o)o=0;
    else v=0;
    return make_pair(v,o);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    
    for(int i=0; i<n; i++)cin >> in[i];

    int v=0, o=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(in[i][j] == 'o' || in[i][j] == 'v'){
                if(check[i][j] == false){
                    int temp1, temp2;
                    tie(temp1, temp2) = getFind(i, j);
                    v += temp1;
                    o += temp2;
                }
            }
        }
    }
    cout << o << " " << v;
    return 0;
}