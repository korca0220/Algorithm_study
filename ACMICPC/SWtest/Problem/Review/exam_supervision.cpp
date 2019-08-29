#include <iostream>
typedef long long ll;
using namespace std;
const int MAX =10000000;
int n,b,c;
ll a[MAX];
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    cin >> b >> c;

    ll total=0;
    for(int i=0; i<n; i++){        
        a[i] -=b;
        total += 1;
        if(a[i] < 0) a[i] = 0;

        total += (a[i])/c + (a[i]%c==0?0:1);
    }
    cout << total;

    return 0;
}