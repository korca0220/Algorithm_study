#include <iostream>
typedef long long ll;
using namespace std;
ll a,b,c;

ll getPow(int a, int b){

    if(b==0) return 1;

    ll n = getPow(a, b/2);
    ll temp = (n*n)%c;

    if(b%2 == 0) return temp;
    else if(b%2 != 0) return (a*temp)%c;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c;
    cout << getPow(a,b);
    
    return 0;
}