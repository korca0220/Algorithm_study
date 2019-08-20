#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <cstring>
using namespace std;

bool ice[201][201];
int n,m;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    memset(ice, true, sizeof(ice));
    cin >> n >> m;
    for(int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        ice[a][b] = false;
        ice[b][a] = false;
    }
    int cnt=0;
    for(int i=1; i<=n-2; i++){
        for(int j=i+1; j<=n-1; j++){
            for(int k=j+1; k<=n; k++){
                if(ice[i][j] && ice[i][k] && ice[j][k])cnt+=1;
            }
        }
    }
    cout << cnt;

    return 0;
}