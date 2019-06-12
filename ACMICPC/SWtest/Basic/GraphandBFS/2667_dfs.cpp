#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int input;
int node[30][30];
int check[30][30];

int count_number[25*25];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0 ,1};

void dfs(int x, int y, int cnt){

    check[x][y] = cnt;
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(0<=nx && nx<input && 0<=ny && ny<input){
            if(node[nx][ny] == 1 && check[nx][ny] ==0){                
                dfs(nx, ny, cnt);
            }
        }
    }

}


int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;

    string str;
    for(int i=0; i<input; i++){
        cin >> str;
        for(int j=0; j<input; j++){
            if(str[j] == '0') node[i][j] == 0;
            else node[i][j] = 1;
        }
    }

    int cnt=0;
    for(int i=0; i<input; i++){
        for(int j=0; j<input; j++){
            if(node[i][j] == 1 && check[i][j] == 0){
                dfs(i, j, ++cnt);
            }
        }
    }

    cout << cnt << "\n";
    for(int i=0; i<input; i++){
        for(int j=0; j<input; j++){
            count_number[check[i][j]] +=1;
        }
    }   

    sort(count_number+1, count_number+cnt+1);
    for(int i=1; i<=cnt; i++){
        cout << count_number[i] << "\n";
    }

    return 0;
}