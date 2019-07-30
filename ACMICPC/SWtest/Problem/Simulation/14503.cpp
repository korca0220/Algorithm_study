#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool status[4];

int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

int main(){

    int n,m;
    scanf("%d %d", &n, &m);

    int r,c,d;
    scanf("%d %d %d", &r,&c,&d);
    vector<vector<int>> in(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &in[i][j]);
        }
    }

    while(true){
        in[r][c] = 2;
        // 2-3, 2-4
        if(in[r-1][c] != 0 && in[r][c+1] != 0 && in[r+1][c] != 0 && in[r][c-1] !=0){
            if(in[r-dx[d]][c-dy[d]] == 1) break;
            else{
                r -= dx[d];
                c -= dy[d];
            }
        }else{
            d = (d+3)%4;
            if(in[r+dx[d]][c+dy[d]] == 0){
                r += dx[d];
                c += dy[d];
            }
        }
    }
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(in[i][j] == 2) cnt+=1;
        }
    }
    printf("%d", cnt);

    return 0;
}