#include <iostream>
using namespace std;

long long N,M;

int main(){

    scanf("%lld %lld", &N, &M);
    int input[N];
    for(int i=0; i<N; i++)scanf("%d", &input[i]);

    int cnt=0, sum=input[0], right=0, left=0;
    // 1way O(n^2)
    // for(int i=0; i<N; i++){
    //     long long sum = 0;
    //     for(int j=i; j<N; j++){
    //         sum += input[j];
    //         if(sum == M)cnt+=1;
    //         if(sum > M)break;
    //     }
    // }

    //2way O(n)
    while(left <= right && right < N){
        if(sum < M){
            right+=1;
            sum += input[right];
        }else if(sum == M){
            cnt+=1;
            right+=1;
            sum += input[right];
        }else if(sum > M){
            sum -= input[left];
            left++;
            if(left > right && left < N){ //음수의 수가 있을때 처리하기 위함
                right = left;
                sum = input[left];
            }
        }
    }
    printf("%d", cnt);

    return 0;
}