#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;

vector<int> getPrime(int n){

    bool p[n+1];
    memset(p, true, sizeof(p));
    vector<int> r_p;
    for(int i=2; i<=n; i++){
        if(p[i] == false) continue;
        else r_p.push_back(i);
        for(int j=i*2; j<=n; j+=i){
            p[j] = false;
        }
    }
    return r_p;
}

int main(){
    scanf("%d", &N);
    vector<int> prime = getPrime(N);

    int left=0, right=0, sum=prime.empty()? 0:prime[0], ans=0;
    while(left <= right && right < prime.size()){
        if(sum <= N){
            if(sum==N)ans++;
            right++;
            if(right < prime.size()){
                sum+=prime[right];
            }
        }else if(sum > N)sum-=prime[left++];
    }
    printf("%d", ans);

    return 0;
}