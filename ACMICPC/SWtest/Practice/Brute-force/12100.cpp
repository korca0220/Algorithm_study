#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

const int MAX = 5;
int N;

vector<int> gen(int n){

    vector<int> temp(MAX);
    for(int i=0; i<MAX; i++){
        temp[i] = (n&3); // 00000000(2) 에서 뒤의 두자리를 저장(4진법) 00 00 00 00 2^2
        n >>= 2; // 저장한 뒤의 두자리 shift right 
    }
    return temp;
}

int check(vector<vector<int>> &a, vector<int> &dirs){

    vector<vector<pair<int, bool>>> d(N, vector<pair<int,bool>>(N)); // N개의 벡터를 pair 벡터 N개로 초기화
    // 2-array + pair(first,second) , first = value, second = T/F
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            d[i][j].first = a[i][j];
        }
    }
    for(int dir : dirs){ // 0 up, 1 down, 2 right, 3 left
        bool ok = false;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                d[i][j].second = false;
            }
        }
        while(true){
            ok = false;
            if(dir == 0){ // down
                for(int i=N-2; i>=0; i--){
                    for(int j=0; j<N; j++){
                        if(d[i][j].first == 0) continue;
                        if(d[i+1][j].first == 0){ // 아래가 빈칸인 경우
                            d[i+1][j].first = d[i][j].first;
                            d[i+1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        }else if(d[i+1][j].first == d[i][j].first){// 숫자가 같은 경우
                            if(d[i+1][j].second == false && d[i][j].second == false){
                                d[i+1][j].first *=2;
                                d[i+1][j].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        } 
                    
                    }
                    
                }
            }else if(dir == 1){ // up
                for(int i=1; i<N; i++){
                    for(int j=0; j<N; j++){
                        if(d[i][j].first == 0)continue;
                        if(d[i-1][j].first == 0){
                            d[i-1][j].first = d[i][j].first;
                            d[i-1][j].second = d[i][j].second;
                            d[i][j].first = 0;
                            ok = true;
                        }else if(d[i-1][j].first == d[i][j].first){
                            if(d[i-1][j].second == false && d[i][j].second == false){
                                d[i-1][j].first *=2;
                                d[i-1][j].second = true;
                                d[i][j].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            }else if(dir == 2){ // right
                for(int i=N-2; i>=0; i--){
                    for(int j=0; j<N; j++){
                        if(d[j][i].first == 0) continue;
                        if(d[j][i+1].first == 0){
                            d[j][i+1].first = d[j][i].first;
                            d[j][i+1].second = d[j][i].second;
                            d[j][i].first = 0;
                            ok = true; 
                        }else if(d[j][i+1].first == d[j][i].first){
                            if(d[j][i+1].second == false && d[j][i].second == false){
                                d[j][i+1].first *= 2;
                                d[j][i+1].second = true;
                                d[j][i].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            }else if(dir == 3){ // left
                for(int i=1; i<N; i++){
                    for(int j=0; j<N; j++){
                        if(d[j][i].first == 0)continue;
                        if(d[j][i-1].first == 0){
                            d[j][i-1].first = d[j][i].first;
                            d[j][i-1].second = d[j][i].second;
                            d[j][i].first = 0;
                            ok = true;
                        }else if(d[j][i-1].first == d[j][i].first){
                            if(d[j][i-1].second == false && d[j][i].second == false){
                                d[j][i-1].first *= 2;
                                d[j][i-1].second = true;
                                d[j][i].first = 0;
                                ok = true;
                            }
                        }
                    }
                }
            }
            if(!ok)break;
        }
    }
    int ans = 0;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(ans < d[i][j].first){
                ans = d[i][j].first;
            }
        }
    }
    return ans;
}

int main(){

    scanf("%d", &N);
    vector<vector<int>> input(N, vector<int> (N)); // N*N 2-array initialize
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &input[i][j]);
        }
    }


    int ans = 0;
    for(int i=0; i<(1<<(MAX*2)); i++){
        vector<int> dirs = gen(i);
        int cnt = check(input, dirs);
        if(ans < cnt) ans = cnt;
    }
    printf("%d", ans);

    return 0;
}