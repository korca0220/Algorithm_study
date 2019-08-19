#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
using namespace std;
int n,m;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
void simulate(vector<vector<int>> &in, vector<vector<int>> &copyd, int i, int j, int dir){

    int x = i;
    int y = j;
    while(x >=0 && x<n && y>=0 && y<m){
        if(copyd[x][y] == 6)break;
        copyd[x][y] = in[i][j];
        x += dx[dir];
        y += dy[dir];
    }
}

int go(vector<vector<int>> &in, vector<tuple<int,int,int>> &cctv, vector<int> &dirs, int index){
    
    int size = cctv.size();
    if(size == index){
        vector<vector<int>> copyd(in);
        for(int i=0; i<size; i++){
            int x,y,z;
            tie(x,y,z) = cctv[i];
            if(z == 1){
                simulate(in, copyd, x,y, dirs[i]);
            }else if(z == 2){
                simulate(in, copyd, x,y, dirs[i]);
                simulate(in, copyd, x,y, (dirs[i]+2)%4);
            }else if(z == 3){
                simulate(in, copyd, x,y, dirs[i]);
                simulate(in, copyd, x,y, (dirs[i]+1)%4);
            }else if(z == 4){
                simulate(in, copyd, x,y, dirs[i]);
                simulate(in, copyd, x,y, (dirs[i]+1)%4);
                simulate(in, copyd, x,y, (dirs[i]+2)%4);
            }else if(z == 5){
                simulate(in, copyd, x,y, dirs[i]);
                simulate(in, copyd, x,y, (dirs[i]+1)%4);
                simulate(in, copyd, x,y, (dirs[i]+2)%4);
                simulate(in, copyd, x,y, (dirs[i]+3)%4);
            }
        }

        int cnt= 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(copyd[i][j] == 0)cnt+=1;
            }
        }
        return cnt;
    }
    int ans = 100;
    for(int i=0; i<4; i++){
        dirs[index] = i;
        int temp = go(in, cctv, dirs, index+1);
        if(ans > temp) ans = temp;
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<tuple<int,int,int>> cctv;
    vector<vector<int>> in(n, vector<int>(m));
    vector<int> dir;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> in[i][j];
            if(1<= in[i][j] && in[i][j] <=5){
                cctv.emplace_back(i,j, in[i][j]);
                dir.push_back(0);
            }
        }
    }
    int ans = go(in, cctv, dir, 0);
    cout << ans;

    return 0;
}