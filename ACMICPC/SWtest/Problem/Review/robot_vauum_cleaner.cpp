#include <iostream>
#include <vector>
using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    int r,c,d;
    scanf("%d %d %d", &r,&c,&d);

    vector<vector<int>> map(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
        }
    }

    while(true){
        map[r][c] = 2;

        if(map[r-1][c] != 0 && map[r+1][c] != 0 && map[r][c-1] != 0 && map[r][c+1] != 0){
            if(map[r-dx[d]][c-dy[d]] == 1)break;
            else{
                r -= dx[d];
                c -= dy[d];
            } 
        }else{
            d=(d+3)%4; // left-side
            if(map[r+dx[d]][c+dy[d]] == 0){
                r += dx[d];
                c += dy[d];
            }
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 2)cnt+=1;
        }
    }
    printf("%d", cnt);

    return 0;
}