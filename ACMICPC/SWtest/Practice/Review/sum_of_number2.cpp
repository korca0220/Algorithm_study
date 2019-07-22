#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long N,M;
    scanf("%lld %lld", &N, &M);
    vector<long long> in(N);
    for(int i=0; i<N; i++)scanf("%lld", &in[i]);

    long long left=0, right=0, sum=in[0], ans=0;
    while(left <= right && right <N){
        if(sum < M){
            right++;
            sum+= in[right];
        }else if(sum == M){
            ans+=1;
            right++;
            sum+= in[right];
        }else if(sum > M){
            sum -= in[left];
            left++;
            if(left > right && left <N){ //음수
                right = left;
                sum = in[left];
            }
        }
    }
    printf("%lld", ans);

    return 0;
}