#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int n,l,r,x;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> l >> r >> x;
    vector<int> in(n);
    for(int i=0; i<n; i++){
        cin >> in[i];
    }
    int ans = 0;
    for(int i=0; i<(1<<n); i++){
        vector<int> temp;
        for(int j=0; j<n; j++){
            if(i&(1<<j)){
                temp.push_back(in[j]);
            }
        }
        auto min_max = minmax_element(temp.begin(), temp.end());
        int sum = accumulate(temp.begin(), temp.end(), 0);
        if(l<= sum && sum <= r && abs(*min_max.first - *min_max.second) >=x){
            ans += 1;
        }
    }
    cout << ans;

    return 0;
}