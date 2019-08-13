#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    int n,k;
    scanf("%d %d", &n ,&k);

    for(int a=0; a<=n; a++){
        int b = n-a;
        if(a*b < k) continue; // a*b 는 k쌍을 만들어냄
        vector<int> cnt(b+1);
        for(int i=0; i<a; i++){
            int x = min(b, k);
            cnt[x] += 1;
            k-=x;
        }
        
        for(int i=b; i>=0; i--){
            for(int j=0; j<cnt[i]; j++){
                printf("A");
            }
            if(i >0) printf("B");
        }
        return 0;
    }
    printf("-1");

    return 0;
}