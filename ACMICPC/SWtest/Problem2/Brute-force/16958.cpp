#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct City{
    int s,x,y;
};
int n,m,t;

int direct(City i, City j){
    int t1 = abs(i.x - j.x);
    int t2 = abs(i.y - j.y);
    return t1 + t2;
}
int near(int i, vector<City> &c, vector<vector<int>> &dist){

    int ans = -1;
    int where = -1;
    for(int k=0; k<n; k++){
        if(c[k].s == 1){
            if(ans==-1 || ans > dist[i][k]){
                ans = dist[i][k];
                where = k;
            }
        }
    }
    return where;
}

int cal(int a, int b, vector<City> &c, vector<vector<int>> &dist){

    int ans = dist[a][b];

    int as = near(a, c, dist);
    int bs = near(b, c ,dist);
    if(c[as].s == 1 && c[bs].s == 1 && as != -1 && bs != -1){
        int temp = dist[a][as] + t + dist[b][bs];
        if(ans > temp) ans = temp;
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> t;
    vector<City> in(n);
    for(int i=0; i<n; i++){
        cin >> in[i].s >> in[i].x >> in[i].y;
    }
    vector<vector<int>> dist(n, vector<int>(n));
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dist[i][j] = dist[j][i] = direct(in[i], in[j]);
        }
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        a-=1 ; b-=1;
        int ans = cal(a,b, in, dist);
        cout << ans << "\n";
    }

    return 0;
}