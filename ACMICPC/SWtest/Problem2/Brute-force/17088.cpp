#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> in(n);
    for(int i=0; i<n; i++) cin>> in[i];

    int ans = -1;
    for(int d1=-1; d1<=1; d1++){
        for(int d2=-1; d2<=1; d2++){
            int change = 0;
            if(d1 != 0) change +=1;
            if(d2 != 0) change +=1;
            int s0 = in[0] + d1;
            int diff = (in[1] + d2) - s0;
            int an = s0 + diff; 
            bool ok = true;
            for(int i=2; i<n; i++){
                an += diff;
                if(an == in[i]) continue;
                if(an == in[i]+1) change += 1;
                else if(an == in[i] -1) change += 1;
                else{
                    ok = false;
                    break;
                }
            }
            if(ok){
                if(ans==-1 || ans > change) ans = change;
            }
        }
    }
    cout << ans; 

    return 0;
}