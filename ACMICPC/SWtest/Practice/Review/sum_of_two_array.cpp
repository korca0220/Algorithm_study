#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

long long T;
int N,M;

int main(){
    scanf("%lld", &T);
    scanf("%d", &N);
    vector<int> in_A(N);
    for(int i=0; i<N; i++)scanf("%d", &in_A[i]);
  
    scanf("%d", &M);
    vector<int> in_B(M);
    for(int i=0; i<M; i++)scanf("%d", &in_B[i]);

    vector<int> A,B;
    for(int i=0; i<N; i++){
        int sum = 0;
        for(int j=i; j<N; j++){
            sum += in_A[j];
            A.push_back(sum);
        }
    }
    for(int i=0; i<M; i++){
        int sum = 0;
        for(int j=i; j<M; j++){
            sum += in_B[j];
            B.push_back(sum);
        }
    }
    in_A.clear(); in_B.clear();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    long long ans = 0;
    for(int i=0; i<A.size(); i++){
        auto p = equal_range(B.begin(), B.end(), T-A[i]);
        ans += p.second - p.first;
    }
    printf("%lld", ans);

    return 0;
}