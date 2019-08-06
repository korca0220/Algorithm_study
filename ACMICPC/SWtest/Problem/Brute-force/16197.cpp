#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int n,m;
vector<string> in(20);

int getSimul(int turn, int x1, int y1, int x2, int y2){

    if(turn==11) return -1;
    bool fail1=false, fail2=false;
    if(0>x1 || x1>=n || 0>y1 || y1>=m) fail1= true;
    if(0>x2 || x2>=n || 0>y2 || y2>=m) fail2= true;
    if(fail1 && fail2) return -1;
    if(fail1 || fail2) return turn;

    int ans = -1;
    for(int i=0; i<4; i++){
        int nx1 = x1+dx[i];
        int ny1 = y1+dy[i];
        int nx2 = x2+dx[i];
        int ny2 = y2+dy[i];
        if(0<=nx1 && nx1<n && 0<=ny1 && ny1<m && in[nx1][ny1] == '#'){
            nx1 = x1;
            ny1 = y1;
        }
        if(0<=nx2 && nx2<n && 0<=ny2 && ny2<m && in[nx2][ny2] == '#'){
            nx2 = x2;
            ny2 = y2;
        }
        int temp = getSimul(turn+1, nx1,ny1,nx2,ny2);
        if(temp == -1) continue;
        if(ans == -1 || ans > temp) ans = temp;
    }
    return ans;
}

int main(){

    scanf("%d %d", &n, &m);
    int x1,y1,x2,y2;
    x1=y1=x2=y2=-1;
    for(int i=0; i<n; i++){
        cin >> in[i];
        for(int j=0; j<m; j++){
            if(in[i][j] == 'o'){
                if(x1==-1 && y1 ==-1){
                    x1 = i;
                    y1 = j;
                }else{
                    x2 = i;
                    y2 = j;
                }
            }
        }
    }
    printf("%d",getSimul(0, x1,y1,x2,y2));


    return 0;
}