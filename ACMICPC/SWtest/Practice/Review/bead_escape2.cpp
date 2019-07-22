#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 10;
int N,M;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

vector<int> genDir(int k){

    vector<int> temp(MAX);
    for(int i=0; i<MAX; i++){
        temp[i] = k&3;
        k >>= 2;
    }
    return temp;
}
bool valid(vector<int> &v){

    for(int i=0; i+1<v.size(); i++){
        if(v[i] == 0 && v[i+1] == 1) return false;
        if(v[i] == 1 && v[i+1] == 0) return false;
        if(v[i] == 2 && v[i+1] == 3) return false;
        if(v[i] == 3 && v[i+1] == 2) return false;
        if(v[i] == v[i+1]) return false;
    }
    return true;
}
pair<bool, bool> simulate(vector<string> &in, int k, int &x, int &y){

    if(in[x][y] == '.') return make_pair(false, false);
    bool moved = false;
    while(true){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(in[nx][ny] == '#') return make_pair(moved, false);
        else if(in[nx][ny] == 'R' || in[nx][ny] == 'B') return make_pair(moved, false);
        else if(in[nx][ny] == '.'){
            swap(in[nx][ny], in[x][y]);
            x = nx;
            y = ny;
            moved = true;
        }else if(in[nx][ny] == 'O'){
            in[x][y] = '.';
            moved = true;
            return make_pair(moved, true);
        }
    }
    return make_pair(moved, false);
}
int countCheck(vector<string> in, vector<int> &dirs){

    int rx,ry,bx,by;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(in[i][j] == 'R'){
                rx = i;
                ry = j;
            }else if(in[i][j] == 'B'){
                bx = i;
                by = j;
            }
        }
    }

    int cnt = 0;
    for(int dir : dirs){
        cnt += 1;
        bool hole1=false, hole2=false;
        while(true){
            auto p1 = simulate(in, dir, rx, ry);
            auto p2 = simulate(in, dir, bx, by);

            if(p1.first == false && p2.first == false){
                break;
            }
            if(p1.second) hole1 = true;
            if(p2.second) hole2 = true;
        }
        if(hole2) return -1;
        if(hole1) return cnt;
    }
    return -1;


}

int main(){
    scanf("%d %d", &N, &M);
    vector<string> input(N);
    for(int i=0; i<N; i++){
        cin >> input[i];
    }

    int ans = -1;
    for(int s=0; s<(1<<(MAX*2)); s++){
        vector<int> dirs = genDir(s);
        if(!valid(dirs)) continue;
        int cnt = countCheck(input, dirs);
        if(cnt == -1) continue;
        if(ans == -1 || cnt < ans) ans = cnt;
    }
    printf("%d", ans);


    return 0;
}
