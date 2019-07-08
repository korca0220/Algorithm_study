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
    vector<int> rv_n(1<<n);
    for(int i=0; i<n; i++)scanf("%d", &v_n[i]);

    for(int i=0; i<(1<<n); i++){
        for(int j=0; j<n; j++){
            if(i&(1<<j))rv_n[i] += v_n[j];
        }
    }


    scanf("%d", &m);
    vector<int> v_m(m);
    vector<int> rv_m(1<<m);
    for(int i=0; i<m; i++)scanf("%d", &v_m[i]);
    
    for(int i=0; i<(1<<m); i++){
        for(int j=0; j<m; j++){
            if(i&(1<<j)) rv_m[i] += v_m[j];
        }
    }
    sort(rv_n.begin(), rv_n.end());
    sort(rv_m.begin(), rv_m.end());
    reverse(rv_m.begin(), rv_m.end());
    for(int i=0; i<rv_n.size(); i++)printf("%d ", rv_n[i]);
    printf("\n");
    for(int i=0; i<rv_m.size(); i++)printf("%d ", rv_m[i]);
    int left=0, right=0;
    long long ans=0;
    n = (1<<n);
    m = (1<<m);
    while(left < n && right < m){
        if(rv_n[left] + rv_m[right] == T){
            long long l = 1;
            long long r = 1;
            left+=1;
            right+=1;
            while(left < n && rv_n[left]==rv_n[left-1]){
                l+=1;
                left+=1;
            }
            while(right < m && rv_m[right]==rv_m[right-1]){
                r=+1;
                right+=1;
            }
            ans += l * r;
        }else if(rv_n[left] + rv_m[right] < T){
            left+=1;
        }else right +=1;
    }
    printf("%lld", ans);


    return 0;
}