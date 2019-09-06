#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n,m,d;
int in[20][20];

int go(int a1, int a2, int a3){

    vector<vector<int>> copy(n, vector<int>(m));
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            copy[i][j] = in[i][j];
        }
    }

    int ans = 0;
    while(true){
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(copy[i][j] == 1){
                    cnt +=1;
                }
            }
        }
        if(cnt == 0) break;
        vector<pair<int,int>> deleted(3, make_pair(-1,-1));
        vector<int> arch = {a1, a2, a3};
        for(int k=0; k<3; k++){
            int rx = n; int ry = arch[k];
            int x,y,dist;
            x=y=dist=-1;
            for(int j=0; j<m; j++){
                for(int i=0; i<n; i++){
                    if(copy[i][j] != 0){
                        int dx = abs(rx - i);
                        int dy = abs(ry - j);
                        int dd = dx + dy;
                        if(dd <= d){
                            if(dist == -1 || dist > dd){
                                dist = dd;
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }
            deleted[k] = make_pair(x,y);
        }

        for(auto &p : deleted){
            if(p.first == -1) continue;
            int x = p.first;
            int y = p.second;
            if(copy[x][y] != 0){
                ans +=1;
            }
            copy[x][y] = 0;
        }
        for(int i=n-1; i>=0; i--){
            for(int j=0; j<m; j++){
                if(i==0){
                    copy[i][j] = 0;
                }else{
                    copy[i][j] = copy[i-1][j];
                }
            }
        }
    }
    return ans;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> d; 
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> in[i][j];
        }
    }
    int ans = 0;
    for(int a1=0; a1<m; a1++){
        for(int a2=a1+1; a2<m; a2++){
            for(int a3=a2+1; a3<m; a3++){
                int temp = go(a1,a2,a3);
                if(temp>ans) ans = temp;
            }
        }
    }
    cout << ans;
    return 0;
}