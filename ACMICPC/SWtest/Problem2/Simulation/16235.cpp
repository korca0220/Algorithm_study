#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <algorithm>
#include <cstring>
using namespace std;

int n,m,k;
int a[10][10]; // 채워 지는 양분 배열
int d[10][10]; // 실제 땅의 양분
int p[10][10]; // 번식이 가능한 나무
vector<int> tree[11][11]; // 칸의 나무의 나이
int dx[] = {-1,-1,-1,0,0,1,1,1};
int dy[] = {-1,0,1,-1,1,-1,0,1};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> a[i][j];
            d[i][j] = 5;
        }
    }
    for(int i=0; i<m; i++){
        int x,y, age;
        cin >> x >> y >> age;
        tree[x-1][y-1].push_back(age);
    }

    while(k--){
        memset(p,0,sizeof(p));
        // 봄,여름,가을,겨울
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                vector<int> temp; // 살아 남은 나무를 저장 할 임시 벡터
                sort(tree[i][j].begin(), tree[i][j].end());
                
                int dead = 0;
                for(int x : tree[i][j]){
                    if(x <= d[i][j]){ // 살아남은 나무 처리(봄)
                        d[i][j] -= x;
                        temp.push_back(x+1);
                        if((x+1) % 5 == 0){ // (가을)
                            for(int h=0; h<8; h++){
                                int nx = i + dx[h];
                                int ny = j + dy[h];
                                if(nx>=0 && nx<n && ny>=0 && ny<n){
                                    p[nx][ny] += 1;
                                }
                            }
                        }
                    }else{ // 죽은 나무 처리(여름)
                        dead += (int)x/2; 
                    }
                }
                // (i,j) 칸에 대한 나무 수행 끝
                tree[i][j] = temp;
                d[i][j] += dead;
                d[i][j] += a[i][j]; // (겨울)
            }
        }
        // 한 해가 끝낫으니 번식된 나무들을 추가함
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int z=0; z<p[i][j]; z++){
                    tree[i][j].push_back(1);
                }
            }
        }
    }
    int total= 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            total += tree[i][j].size();
        }
    }
    cout << total;

    return 0;
}