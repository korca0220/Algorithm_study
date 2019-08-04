#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
using namespace std;

int N,M;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

void simul(vector<vector<int>> &in, vector<vector<int>> &copyd, int x, int y, int dir){

    int i = x;
    int j = y;
    while(0<= i && i<N && 0<= j && j<M){
        if(in[i][j] == 6) break;
        copyd[i][j] = in[x][y]; // copyd copy
        i += dx[dir];
        j += dy[dir];
    }

}

int go(vector<vector<int>> &in, vector<tuple<int,int,int>> &cctv, vector<int> &dirs, int index){

    if(cctv.size() == index){
        vector<vector<int>> copyd(in);
        for(int i=0; i<cctv.size(); i++){
            int x,y,z;
            tie(x,y,z) = cctv[i];
            if(z==1){
                // 한쪽 방향
                simul(in, copyd, x,y, dirs[i]);
            }else if(z==2){
                // 서로 반대되는 두 방향
                simul(in,copyd, x,y,dirs[i]);
                simul(in,copyd, x,y,(dirs[i]+2)%4);
            }else if(z==3){
                // 바로 옆의 근접한 두 방향
                simul(in,copyd, x,y,dirs[i]);
                simul(in,copyd, x,y,(dirs[i]+1)%4);
            }else if(z==4){
                // 근접한 세 방향
                simul(in,copyd, x,y,dirs[i]);
                simul(in,copyd, x,y,(dirs[i]+1)%4);
                simul(in,copyd, x,y,(dirs[i]+2)%4);
            }else{
                // 네 방향
                simul(in,copyd, x,y,dirs[i]);
                simul(in,copyd, x,y,(dirs[i]+1)%4);
                simul(in,copyd, x,y,(dirs[i]+2)%4);
                simul(in,copyd, x,y,(dirs[i]+3)%4);
            }

        }
        int cnt =0;
        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(copyd[i][j] == 0){
                    cnt +=1;
                }
            }
        }
        return cnt;
    }
    int ans = 100;
    for(int i=0; i<4; i++){
        dirs[index] = i;
        int temp = go(in, cctv, dirs, index+1);
        if(ans > temp)ans = temp;
    }
    return ans;
}

int main(){

    scanf("%d %d", &N, &M);
    vector<vector<int>> in(N, vector<int>(M));
    vector<tuple<int,int,int>> cctv;
    vector<int> dirs;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            scanf("%d", &in[i][j]);
            if(1<= in[i][j] && in[i][j] <=5){
                cctv.emplace_back(i,j, in[i][j]);
                dirs.push_back(0);
            }
        }
    }
    printf("%d", go(in, cctv, dirs, 0));

    return 0;
}