#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    long long T;
    scanf("%lld", &T);
    int n, m;
    
    scanf("%d", &n);
    vector<int> v_n(n);
    vector<int> rv_n;
    for(int i=0; i<n; i++)scanf("%d", &v_n[i]);

    for(int i=0; i<n; i++){
        int sum =0;
        for(int j=i; j<n; j++){
            sum += v_n[j];
            rv_n.push_back(sum);
        }
    }


    scanf("%d", &m);
    vector<int> v_m(m);
    vector<int> rv_m;
    for(int i=0; i<m; i++)scanf("%d", &v_m[i]);
    
    for(int i=0; i<m; i++){
        int sum = 0;
        for(int j=i; j<m; j++){
            sum += v_m[j];
            rv_m.push_back(sum);
        }
    }
    sort(rv_n.begin(), rv_n.end());
    sort(rv_m.begin(), rv_m.end());
    long long ans=0;

    for(int i=0; i<rv_n.size(); i++){
        auto p = equal_range(rv_m.begin(), rv_m.end(), T-rv_n[i]);
        ans += p.second - p.first;
    }
    
    printf("%lld", ans);


    return 0;
}