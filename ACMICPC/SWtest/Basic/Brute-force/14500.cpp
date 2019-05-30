#include <iostream>
using namespace std;

int input_n, input_m;
int polio[500][500];
int d_tetro[19][3][2] = {
    // 일자 도형
    {{0,1}, {0,2}, {0,3}}, 
    {{1,0}, {2,0}, {3,0}},
    // 네모 도형
    {{0,1}, {1,0}, {1,1}},
    // ㄱ자 도형
    {{0,1}, {0,2}, {1,2}},
    {{0,1}, {0,2}, {-1,2}},
    {{-1,0}, {0,1}, {0,2}},
    {{1,0}, {0,1}, {0,2}},
    {{0,-1}, {1,0}, {2,0}},
    {{1,0}, {2,0}, {2,1}},
    {{1,0}, {2,0}, {2,-1}},
    {{0,1}, {1,0}, {2,0}},
    // ㄹ자 도형
    {{0,1}, {1,1}, {1,2}},
    {{0,1}, {-1,1}, {-1,2}},
    {{1,0}, {1,1}, {2,1}},
    {{1,0}, {1,-1}, {2,-1}},
    // ㅗ자 도형
    {{1,0}, {1,1}, {2,0}},
    {{1,0}, {1,-1}, {2,0}},
    {{1,0}, {1,-1}, {1,1}},
    {{1,0}, {0, -1}, {0,1}}
};

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    cin >> input_n >> input_m;
    for(int i=0; i<input_n; i++){
        for(int j=0; j<input_m; j++){
            cin >> polio[i][j];
        }
    }

    int result =0;
    for(int i=0; i<input_n; i++){
        for(int j=0; j<input_m; j++){
            for(int k=0; k<19; k++){
                int sum = polio[i][j];
                bool checker = true;
                for(int h=0; h<3; h++){
                    int x = i + d_tetro[k][h][0];
                    int y = j + d_tetro[k][h][1];
                    if ( 0 <= x && x <input_n && 0 <= y && y <input_m){
                        sum += polio[x][y];
                    }else {
                        checker = false;
                        break;
                    }
                }
                if(result < sum && checker) result = sum;
            }
        }
    }

    cout << result << "\n";
    return 0;
}