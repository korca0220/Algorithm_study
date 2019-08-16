#include <iostream>
using namespace std;

int map[21][21];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int dice[7];

int main(){

    int n,m,x,y,k;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    while(k--){
        int c;
        scanf("%d", &c);
        c-=1;

        int nx = x + dx[c];
        int ny = y + dy[c];
        if(nx<0 || nx>=n || ny<0 || ny>=m) continue;

        int temp = dice[1];
        if(c==0){
            dice[1] = dice[4];
            dice[4] = dice[6];
            dice[6] = dice[3];
            dice[3] = temp;
        }else if(c==1){
            dice[1] = dice[3];
            dice[3] = dice[6];
            dice[6] = dice[4];
            dice[4] = temp;
        }else if(c==2){
            dice[1] = dice[2];
            dice[2] = dice[6];
            dice[6] = dice[5];
            dice[5] = temp;
        }else if(c==3){
            dice[1] = dice[5];
            dice[5] = dice[6];
            dice[6] = dice[2];
            dice[2] = temp;
        }

        if(map[nx][ny] == 0){
            map[nx][ny] = dice[1];
        }else{
            dice[1] = map[nx][ny];
            map[nx][ny] = 0;
        }
        printf("%d\n", dice[6]);
        x = nx;
        y = ny;
    }


    return 0;
}