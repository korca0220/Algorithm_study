#include <iostream>
#include <vector>
using namespace std;

int map[21][21];
int dice[7];

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

int main(){
    int n,m,x,y,k;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
        }
    }
    while(k--){
        int i;
        scanf("%d", &i);
        i -= 1;

        int nx, ny;
        nx = x + dx[i];
        ny = y + dy[i];
        if(0>nx || nx>=n || 0>ny || ny>=m) continue;

        if(i==0){ // right
            int temp = dice[1];
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        }else if(i==1){  // left
            int temp = dice[1];
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        }else if(i==2){ // up
            int temp = dice[1];
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        }else if(i==3){ // down
            int temp = dice[1];
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }
        x = nx;
        y = ny;
        if(map[x][y] ==0){
            map[x][y] = dice[6];
        }else{
            dice[6] = map[x][y];
            map[x][y] = 0;
        } 

        printf("%d\n", dice[1]);

    }
    return 0;
}