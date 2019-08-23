#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll dp[31][31];

ll getDp(int f, int h){

    if(dp[f][h] >0) return dp[f][h];
    if(f==0) return 1;
    if(h==0) return getDp(f-1, h+1);

    return dp[f][h] = getDp(f-1, h+1) + getDp(f, h-1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    while(true){
        cin >> tc;
        if(tc==0) break;
        cout << getDp(tc, 0) << "\n";
    }

    return 0;
}