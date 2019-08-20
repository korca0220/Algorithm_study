#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int n,m;
char in[21][21];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int simulate(int x1, int y1, int x2, int y2, int index){

    if(index==11) return -1;  //10을 넘은경우
    bool fail1, fail2;
    fail1=fail2=false;
    if(x1<0 || x1>=n || y1<0 || y1>=m) fail1 = true;
    if(x2<0 || x2>=n || y2<0 || y2>=m) fail2 = true;
    if(fail1 && fail2) return -1;
    if(fail1 || fail2) return index;

    int ans = -1;
    for(int i=0; i<4; i++){
        int nx1 = x1 + dx[i]; int ny1 = y1 + dy[i];
        int nx2 = x2 + dx[i]; int ny2 = y2 + dy[i];
        if(nx1 >=0 && nx1<n && ny1>=0 && ny1<m && in[nx1][ny1] == '#'){
            nx1 = x1;
            ny1 = y1;
        }
        if(nx2 >=0 && nx2<n && ny2>=0 && ny2<m && in[nx2][ny2] == '#'){
            nx2 = x2;
            ny2 = y2;
        }
        int temp = simulate(nx1, ny1, nx2, ny2, index+1);
        if(temp == -1) continue;
        if(ans == -1 || ans >temp) ans = temp;
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int x1,y1,x2,y2;
    x1=y1=x2=y2=-1;
    for(int i=0; i<n; i++){
        cin >> in[i];
        for(int j=0; j<m; j++){
            if(in[i][j] == 'o'){
                if(x1==-1){
                    x1=i; y1=j;
                }else{
                    x2=i; y2=j;
                }
            }
        }
    }
    int ans = simulate(x1,y1,x2,y2,0);
    cout << ans;

    return 0;
}