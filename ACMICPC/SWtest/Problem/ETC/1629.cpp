#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

int a,b,c;

ll getPow(int a, int b, int c){

    if(b == 0 )return 1;

    ll n = getPow(a, b/2, c);
    ll temp = (n * n)%c;

    if(b%2 == 0){
        return temp;
    }else if(b%2 != 0){
        return (a * temp)%c;
    }

}

int main(){

    scanf("%d %d %d", &a, &b, &c);
    printf("%lld", getPow(a,b,c));

    return 0;
}