#include <iostream>
using namespace std;

char in[33][33];
int n,m;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};

bool ok(int x, int y){
    return 0<=x && x<n && 0<=y && y<m;                      
}

int go(int x, int y, int cnt){

    int ans = -1;
    if(cnt==0) return 0; // 더 이상 탐색할 부분이 없음
    for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        while(ok(nx,ny) && in[nx][ny]=='.'){
            in[nx][ny] = '#';
            cnt -= 1;
            nx += dx[i];
            ny += dy[i];                                    
        }
        nx -= dx[i];
        ny -= dy[i];

        // 갈 곳이 없는 경우 (x==nx)&&(y==ny)
        if(!(x==nx && y==ny)){
            int temp = go(nx, ny, cnt);            
            if(temp != -1){
                if(ans == -1 || ans > temp+1){
                    ans = temp+1;                           
                }  
            }
        }
        
        while(!(x==nx&&y==ny)){
            in[nx][ny] = '.';
            cnt += 1;
            nx -= dx[i];
            ny -= dy[i];                                    
        }
    }
    return ans;                                             
}

int main(){

    int t_case = 1;
    while(cin >> n >> m){
        int cnt = 0;
        for(int i=0; i<n; i++){
            cin >> in[i];
            for(int j=0; j<m; j++){
                if(in[i][j] == '.'){
                    cnt += 1;
                }
            }
        }        
        int ans = -1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(in[i][j] == '.'){
                    in[i][j] = '#';                
                    int temp = go(i,j, cnt-1);
                    if(temp != -1){
                        if(ans == -1 || ans > temp){
                            ans = temp; 
                        }
                    }
                    in[i][j] = '.';                        
                }
            }
        }
        cout << "Case " << t_case << ": " << ans << '\n';
        t_case += 1;                                          
    }
    
    return 0;                                               
}