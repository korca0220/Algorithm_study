#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

const int MAX = 1000000;
int N;
ll in[MAX+1];
int B,C;

int main(){

    scanf("%d", &N);
    for(int i=0; i<N; i++){
        scanf("%lld", &in[i]);
    }
    scanf("%d %d", &B, &C);
    ll total=0;

    for(int i=0; i<N; i++){
        in[i] -= B;
        total+=1;
        if(in[i] <0) in[i] = 0;

        total += (in[i]/C) + ((in[i]%C) == 0 ? 0:1);
    }
    printf("%lld", total);

    return 0;
}