#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    vector<int> in(n);
    for(int i=0; i<n; i++)cin >> in[i];
    
    int ans = -1;
    for(int i=1; i<=1000; i++){
        int cnt = 0;
        for(int j=0; j<n; j++){
            if(in[j] != i+(j*k)){
                cnt +=1;
            }
        }
        if(ans == -1 || ans > cnt) ans = cnt;
    }
    cout << ans;

    return 0;
}