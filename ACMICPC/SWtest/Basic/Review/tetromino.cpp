#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int T[501][501];
int dT[19][3][2] = {
    {{1,0}, {2,0}, {3,0}},
    {{0,1}, {0,2}, {0,3}},

    {{1,0}, {0,1}, {1,1}},

    {{0,1}, {0,2}, {-1,2}},
    {{0,1}, {0,2}, {1,2}},
    {{-1,0}, {-1,1}, {-1,2}},
    {{1,0}, {1,1}, {1,2}},
    {{0,1}, {1,1}, {2,1}},
    {{0,-1}, {1,-1}, {2,-1}},
    {{1,0}, {2,0}, {2,-1}},
    {{1,0}, {2,0}, {2,1}},

    {{0,1}, {1,1}, {1,2}},
    {{0,1}, {-1,1}, {-1,2}},
    {{1,0}, {1,-1}, {2,-1}},
    {{1,0}, {1,1}, {2,1}},

    {{0,1}, {1,1}, {0,2}},
    {{1,0}, {1,-1}, {1,1}},
    {{1,0}, {1,-1}, {2,0}},
    {{1,0}, {1,1}, {2,0}}
};

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> T[i][j];
        }
    } 

    int max_number = -987654321;
    int sum;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            for(int k=0; k<19; k++){
                sum = T[i][j];
                for(int h=0; h<3; h++){
                    int x = i + dT[k][h][0];
                    int y = j + dT[k][h][1];
                    if(0 <= x && x<N && 0<= y && y<M )sum  = sum +  T[x][y];
                    else {
                        sum = 0;
                        break;
                    }
                }
                max_number = max(max_number, sum);               
            }
        }
    }
    cout << max_number;

    return 0;
}