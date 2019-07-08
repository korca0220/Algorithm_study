#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int N, S;
    scanf("%d %d", &N, &S);

    int array[N+1];
    for(int i=0; i<N; i++)scanf("%d", &array[i]);
    int m = N/2;
    N = N-m;
    vector<int> array1(1<<N), array2(1<<m);

    for(int i=0; i<(1<<N); i++){
        for(int j=0; j<N; j++){
            if(i&(1<<j)){
                array1[i] += array[j];
            }
        }
    }

    for(int i=0; i<(1<<m); i++){
        for(int j=0; j<m; j++){
            if(i&(1<<j)){
                array2[i] += array[j+N];
            }
        }
    }
    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());
    reverse(array2.begin(), array2.end());
    N = (1<<N);
    m = (1<<m);
    int left = 0, right = 0;
    long long ans = 0;
    while(left < N && right < m){
        if(array1[left] + array2[right] == S){
            long long c1 = 1;
            long long c2 = 1;
            left +=1;
            right +=1;
            while(left < N && array1[left] == array1[left-1]){
                c1+=1;
                left+=1;
            }
            while(right < m && array2[right] == array2[right-1]){
                c2 +=1;
                right+=1;
            }
            ans += c1 * c2;    
        }else if(array1[left] + array2[right] < S){
            left+=1;
        }else right +=1;
        
    }

    if(S == 0) ans -= 1;
    printf("%lld", ans);


    return 0;
}