#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,S;

int main(){
    scanf("%d %d", &N, &S);
    vector<int> in(N);
    for(int i=0; i<N; i++)scanf("%d", &in[i]);
    int m = N/2;
    N = N-m;
    vector<int> array1(1<<N);
    vector<int> array2(1<<m);

    for(int i=0; i<(1<<N); i++){
        for(int j=0; j<N; j++){
            if(i&(1<<j)){
                array1[i] += in[j];
            }
        }
    }
    for(int i=0; i<(1<<m); i++){
        for(int j=0; j<m; j++){
            if(i&(1<<j)){
                array2[i] += in[j+N];
            }
        }
    }
    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());
    reverse(array2.begin(), array2.end());

    N = (1<<N);
    m = (1<<m);
    int left=0, right=0;
    long long ans=0;
    while(left<N && right <m){
        if(array1[left] + array2[right] == S){
            long long c1 = 1;
            long long c2 = 1;
            left++;
            right++;
            while(left<N && array1[left-1] == array1[left]){
                c1++;
                left++;
            }
            while(right<m && array2[right-1] == array2[right]){
                c2++;
                right++;
            }
            ans += c1*c2;
        }else if(array1[left] + array2[right] < S){
            left++;
        }else right++;
    }
    if(S==0)ans -= 1;
    printf("%lld", ans);

    return 0;
}