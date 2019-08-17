#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
vector<int> gen(int dir, int gen){

    vector<int> ans = {dir};
    for(int i=1; i<=gen; i++){
        vector<int> temp(ans);
        reverse(temp.begin(), temp.end());
        for(int &v : temp){
            v = (v+1)%4;
        }
        ans.insert(ans.end(), temp.begin(), temp.end());
    }
    return ans;
}

int main(){ 

    int n;
    scanf("%d", &n);

    bool map[101][101];
    memset(map, false, sizeof(map));
    while(n--){
        int x,y,d,g;
        scanf("%d %d %d %d", &y, &x, &d, &g);
        vector<int> dirs = gen(d, g);
        map[x][y] = true;
    
        for(int dir : dirs){
            x+=dx[dir];
            y+=dy[dir];
            map[x][y] = true;
        }
    }
    int ans = 0;
    for(int i=0; i<=99; i++){
        for(int j=0; j<=99; j++){
            if(map[i][j] && map[i+1][j] && map[i][j+1] && map[i+1][j+1]){
                ans+=1;
            }
        }
    }    
    printf("%d", ans);

    return 0;
}