#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int tetro[19][3][2] ={
    // ㅡ    
    {{1,0}, {2,0}, {3,0}},
    {{0,1}, {0,2}, {0,3}},

    //ㅁ
    {{1,0}, {0,1}, {1,1}},

    //ㄱ
    {{0,1}, {0,2}, {-1,2}},
    {{0,1}, {0,2}, {1,2}},
    {{-1,0}, {-1,1}, {-1,2}},
    {{1,0}, {1,1}, {1,2}},
    {{0,1}, {1,1}, {2,1}},
    {{0,-1}, {1,-1}, {2,-1}},
    {{1,0}, {2,0}, {2,-1}},
    {{1,0}, {2,0}, {2,1}},

    // ㄹ
    {{0,1}, {1,1}, {1,2}},
    {{0,1}, {-1,1}, {-1,2}},
    {{1,0}, {1,-1}, {2,-1}},
    {{1,0}, {1,1}, {2,1}},

    //ㅗ
    {{0,1}, {1,1}, {0,2}},
    {{1,0}, {1,-1}, {1,1}},
    {{1,0}, {1,-1}, {2,0}},
    {{1,0}, {1,1}, {2,0}}
};

int map[1001][1001];

int main(){

    int n,m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%d", &map[i][j]);
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int a=0; a<19; a++){
                int sum = map[i][j];
                for(int b=0; b<3; b++){
                    int nx = i + tetro[a][b][0];
                    int ny = j + tetro[a][b][1];
                    if(0> nx || nx >= n || 0> ny || ny >= m){
                        sum = 0;
                        break;
                    }
                    sum += map[nx][ny];
                }
                if(ans<sum) ans = sum;
            }
        }
    }
    printf("%d", ans);

    return 0;
}