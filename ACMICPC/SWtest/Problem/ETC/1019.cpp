#include <iostream>
typedef long long ll;
using namespace std;

ll num[10];

void calcul(ll start, ll ten){

    while(start > 0){
        num[start%10] += ten;
        start /= 10;
    }
}

int main(){
    ll start = 1;
    ll end = 1;
    ll ten = 1;

    scanf("%lld", &end);
    while(start <= end){
        while(start%10 != 0 && start <= end){
            calcul(start, ten);
            start++;
        }
        if(start > end) break;
        while(end%10 != 9 && start <= end){
            calcul(end, ten);
            end--;
        }
        ll cnt = (end/10 - start/10)+1;
        for(int i=0; i<=9; i++){
            num[i] += cnt*ten;
        }
        start /= 10;
        end /= 10;
        ten *= 10LL;
    }

    for(int i=0; i<=9; i++){
        printf("%lld ", num[i]);
    }

    return 0;
}