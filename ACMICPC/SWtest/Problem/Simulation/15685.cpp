#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

vector<int> gen(int dir, int gen){

    vector<int> ans = {dir};
    for(int i=1; i<=gen; i++){
        vector<int> temp(ans);
        reverse(temp.begin(), temp.end());
        for(int &i : temp){
            i = (i+1)%4;
        }
        ans.insert(ans.end(), temp.begin(), temp.end());
    }

    return ans;
}

int main(){
    int N;
    scanf("%d", &N);
    bool check[101][101];
    memset(check, false, sizeof(check));

    int x,y,d,g;
    for(int i=0; i<N; i++){
        scanf("%d %d %d %d", &y, &x, &d, &g);
        vector<int> dirs = gen(d, g);
        check[x][y] = true;
        for(int dir: dirs){
            x += dx[dir];
            y += dy[dir];
            check[x][y] = true;
        }
    }

    int ans = 0;
    for(int i=0; i<=99; i++){
        for(int j=0; j<=99; j++){
            if(check[i][j] && check[i+1][j] && check[i][j+1] && check[i+1][j+1]){
                ans += 1;
            }
        }
    }
    printf("%d", ans);

    return 0;
}