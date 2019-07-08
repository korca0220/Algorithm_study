#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int> getPrime(int n){

    bool isPrime[n+1];
    vector<int> prime;
    fill(isPrime+2, isPrime+n+1, true);
    for(int i=2; i<=n; i++){
        if(isPrime[i]) prime.push_back(i);
        for(int j=i*2; j<=n; j+=i){
            isPrime[j] = false;
        } 
    }
    return prime;
}

int main(){
    int N;
    scanf("%d", &N);
    vector<int> p_num = getPrime(N);

    int left=0, right=0, cnt=0, sum= p_num.empty() ? 0 : p_num[0];
    while(left <=right && right < p_num.size()){
        if(sum <= N){
            if(sum == N){
                cnt +=1;    
            }
            right+=1;
            if(right < p_num.size()){
                sum += p_num[right];
            }
        }else if (sum > N){
            sum -=p_num[left++];
        }
    }
    printf("%d", cnt);

    return 0;
}