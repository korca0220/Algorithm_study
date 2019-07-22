#include <iostream>
#include <vector>
using namespace std;


int main(){
    int N;
    long long M;
    scanf("%d %lld", &N, &M);
    vector<long long> in(N);
    for(int i=0; i<N; i++)scanf("%lld", &in[i]);

    long long left=0, right=0, sum=in[0], ans = N+1;
    while(left <= right && right < N){
        if(sum < M){
            right+=1;
            sum += in[right];
        }else if(sum >= M){
            int cur = right-left+1;            
            if(ans > cur) ans = cur;
            sum -= in[left];            
            left+=1;
        }
    }
    if(ans > N)printf("0");
    else printf("%d", ans);



    return 0;
}