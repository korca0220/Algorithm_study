#include <iostream>
#include <vector>
using namespace std;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};


int main(){
    int N;
    scanf("%d", &N);
    vector<vector<bool>> apple(N+1, vector<bool>(N+1, false));
    
    int k;
    scanf("%d", &k);
    for(int i=1; i<=k; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        apple[a][b] = true;
    }
    int L;
    scanf("%d", &L);

    int dir = 0; //right
    int time = 0;
    int len = 1;
    int x,y;
    x=y=1;
    vector<vector<int>> d(N+1, vector<int>(N+1, -1));
    d[x][y] = 0;
    for(int i=0; i<=L; i++){
        int t = N*N+1; // to enter directional value and go to the end.
        char ch = 'L'; //
        if(i < L){
            cin >> t >> ch;
        }
        while(time < t){
            time+=1;
            x += dx[dir];
            y += dy[dir];
            if(x <= 0 || x > N || y <= 0 || y > N ){
                printf("%d", time);
                return 0;
            }
            if(apple[x][y]){
                len+=1;
                apple[x][y] = false;
            }
            if(d[x][y] != -1){
                if(time-d[x][y] <= len){
                    printf("%d", time);
                    return 0;
                }
            }
            d[x][y] = time;
        }
        if(ch == 'L'){
            dir = (dir+3)%4;
        }else {
            dir = (dir+1)%4;
        }

    }

    return 0;
}