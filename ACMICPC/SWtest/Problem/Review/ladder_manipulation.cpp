#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n,m,h;
int in[31][11];

int check(int start){
    
    int r=1;
    while(r<=h){
        if(in[r][start] == 1){
            start+=1;
        }else if(in[r][start] == 2){
            start-=1;
        }
        r+=1;
    }
    return start;

}

bool go(){

    for(int i=1; i<=n; i++){
        if(check(i) != i)return false;
    }
    return true;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> h;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        in[a][b] = 1;
        in[a][b+1] = 2;
    }

    vector<pair<int,int>> avail;
    for(int i=1; i<=h; i++){
        for(int j=1; j<n; j++){
            if(in[i][j] != 0 ) continue;
            if(in[i][j+1] != 0)continue;
            avail.emplace_back(i,j);
        }
    }

    int ans=-1;
    if(go()){
        cout << "0";
        return 0;
    }

    int size = avail.size();
    for(int i=0; i<size; i++){
        int x1 = avail[i].first;
        int y1 = avail[i].second;
        if(in[x1][y1] != 0 || in[x1][y1+1] != 0) continue;
        in[x1][y1] = 1;
        in[x1][y1+1] = 2;

        if(go()){
            if(ans==-1 || ans>1)ans=1;
        }

        for(int j=i+1; j<size; j++){
            int x2 = avail[j].first;
            int y2 = avail[j].second;
            if(in[x2][y2] != 0 || in[x2][y2+1] != 0) continue;
            in[x2][y2] = 1;
            in[x2][y2+1] = 2;

            if(go()){
                if(ans==-1 || ans>2)ans=2;
            }

            for(int k=j+1; k<size; k++){
                int x3 = avail[k].first;
                int y3 = avail[k].second;
                if(in[x3][y3] != 0 || in[x3][y3+1] != 0) continue;
                in[x3][y3] = 1;
                in[x3][y3+1] = 2;

                if(go()){
                    if(ans == -1 || ans>3) ans=3;
                }
                in[x3][y3] = 0;
                in[x3][y3+1] = 0;
            }
            in[x2][y2] = 0;
            in[x2][y2+1] = 0;
        }
        in[x1][y1] = 0;
        in[x1][y1+1] = 0;
    }
    
    cout << ans;

    return 0;
}