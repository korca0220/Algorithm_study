#include <iostream>
#include <queue>
#include <cstring>
typedef long long ll;
using namespace std;

ll a, b;
ll ans = -1;
void getMin(ll a_in, ll count){

    if(a_in == b){
        if(ans == -1 || ans > count) ans = count;
        return ;
    }
    if(a_in > b)return ;

    getMin(a_in*2, count+1);
    getMin(a_in*10+1, count+1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    getMin(a, 1);
    cout << ans;
    return 0;
}