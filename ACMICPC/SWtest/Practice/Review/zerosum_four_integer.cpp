#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int main(){
    scanf("%d", &N);
    vector<int> A(N), B(N), C(N), D(N);
    for(int i=0; i<N; i++)scanf("%d %d %d %d", &A[i], &B[i], &C[i], &D[i]);

    vector<int> A_B;
    vector<int> C_D;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            A_B.push_back(A[i]+B[j]);
            C_D.push_back(C[i]+D[j]);
        }
    }
    long long ans = 0;
    sort(C_D.begin(), C_D.end());
    for(int i=0; i<A_B.size(); i++){
        auto p = equal_range(C_D.begin(), C_D.end(), 0-A_B[i]);
        ans += p.second - p.first;
    }
    printf("%lld", ans);

    return 0;
}