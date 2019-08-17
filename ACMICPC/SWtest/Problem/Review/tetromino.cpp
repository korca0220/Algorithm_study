#include <iostream>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

int n,m;
int in[501][501];
bool check[501][501];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int ans = 0;

int except_case[4][3][2] = {
    {{0,1}, {1,1}, {0,2}},
    {{1,0}, {1,-1}, {1,1}},
    {{1,0}, {1,-1}, {2,0}},
    {{1,0}, {1,1}, {2,0}}
};

void getMax(int i, int j, int index, int sum){

    if(i>= n || i<0 || j>=m || j<0)return ;
    if(index==4){
        if(ans < sum) ans = sum;
        return ;
    }

    if(check[i][j]) return ;
    check[i][j] = true;
    for(int x=0; x<4; x++){
        getMax(i+dx[x], j+dy[x], index+1, sum+in[i][j]);
    }
    check[i][j] = false;
}

int main(){
    
    ios::sync_with_stdio(false);
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> in[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            getMax(i,j, 0, 0);
            for(int a=0; a<4; a++){
                int sum = in[i][j];
                for(int b=0; b<3; b++){
                    int nx = i + except_case[a][b][0];
                    int ny = j + except_case[a][b][1];
                    if(nx<0 || nx>=n || ny<0 || ny>=m){
                        sum = 0;
                        break;
                    }
                    sum += in[nx][ny];
                }
                if(ans < sum) ans = sum;
            }
        }
    }
    cout << ans;
    return 0;
}