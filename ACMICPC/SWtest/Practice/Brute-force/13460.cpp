#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 10;
// [dx,dy] = left, right, up, dow(0,1,2,3)
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
int N, M;

vector<int> gen(int k){

    vector<int> temp(MAX);
    for(int i=0; i<MAX; i++){
        temp[i] = k&3; // 000000'00' 이진수에서 두자리씩(4진법) = k%4
        k >>= 2; // = k /= 2
    }
    return temp;
}

bool valid(vector<int> &v){

    // 서로 반대 방향은 의미가 없다
    // 같은 방향도 의미가 없다
    for(int i=0; i+1<v.size(); i++){
        if(v[i] == 0 && v[i+1] == 1) return false;
        if(v[i] == 1 && v[i+1] == 0) return false;
        if(v[i] == 2 && v[i+1] == 3) return false;
        if(v[i] == 3 && v[i+1] == 2) return false;
        if(v[i] == v[i+1]) return false;
    }
    return true;

}


pair<bool, bool> simulate(vector<string> &a, int k, int &x, int &y){// refer x,y 

    if(a[x][y] == '.') return make_pair(false, false);
    bool moved = false; // 이동 가능한지에 대한 변수
    while(true){
        // k는 방향(0,1,2,3)
        // 벽이라는 조건이 있기때문에 nx,ny의 범위 조절 필요 X
        int nx = x + dx[k]; 
        int ny = y + dy[k];


        if(a[nx][ny] == '#')return make_pair(moved, false);
        else if(a[nx][ny] == 'R' || a[nx][ny] == 'B') return make_pair(moved, false);
        else if(a[nx][ny] == '.'){ // '.' 이기때문에 계속 이동(벽에 닿을떄까지)
            swap(a[nx][ny], a[x][y]);
            x = nx;
            y = ny;
            moved = true;
        }else if(a[nx][ny] == 'O'){ // 구멍으로 빠졋으므로 맵에서 제거 ( = '.')
            a[x][y] = '.';
            moved = true;
            return make_pair(moved, true);
        }
    }
    return make_pair(moved, false);

}

int check(vector<string> a, vector<int> &dirs){

    int hx,hy,rx,ry,bx,by;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(a[i][j] == 'O'){
                hx = i, hy = j;
            }else if(a[i][j] == 'R'){
                rx = i, ry = j;
            }else if(a[i][j] == 'B'){
                bx = i, by = j;
            }
        }
    }

    int cnt = 0;
    for(int k : dirs){
        cnt += 1;
        bool hole1=false, hole2=false; // hole1 = red, hole2 = blue
        while(true){
            auto p1 = simulate(a, k, rx, ry);
            auto p2 = simulate(a, k, bx, by);

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
    for(int i=0; i<(1<<(MAX*2)); i++){
        vector<int> four = gen(i); //10개의 방향을 담고 있음
        if(!valid(four)) continue;
        int cur = check(input, four);
        if(cur == -1) continue;
        if(ans == -1 || ans > cur) ans = cur;
    }
    printf("%d", ans);

    return 0;
}