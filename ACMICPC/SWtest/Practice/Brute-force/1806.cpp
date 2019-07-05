#include <iostream>
using namespace std;

long long n,s;

int main(){
    scanf("%lld %lld", &n, &s);
    int input[n];
    for(int i=0; i<n; i++)scanf("%d", &input[i]);

    int ans = n+1;
    int right=0, left=0, sum=input[0];
    while(left <=right && right < n){
        if(sum < s){
            right+=1;
            sum += input[right];
        }else if(sum == s){
            if(ans > right-left+1) ans = right-left+1;
            right+=1;
            sum += input[right];
        }else if(sum > s){
            if(ans > right-left+1) ans = right-left+1;
            sum -= input[left];
            left++;
        }
    }
    if(ans > n)ans=0;
    printf("%d", ans);

    return 0;
}