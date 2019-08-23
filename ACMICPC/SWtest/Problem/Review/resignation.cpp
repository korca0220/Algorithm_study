#include <iostream>
typedef long long ll;
using namespace std;

const int MAX = 1500000;
ll dp[MAX+50]; // MAX + T-MAX(50)
ll T[MAX+1];
ll P[MAX+1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> T[i] >> P[i];
    } 

    for(int i=0; i<n; i++){
        dp[i+T[i]] = max(dp[i+T[i]], dp[i]+P[i]);
        dp[i+1] = max(dp[i+1], dp[i]);
    }
    cout << dp[n];

    return 0;
}