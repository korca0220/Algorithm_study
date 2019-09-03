#include <iostream>
using namespace std;

bool check[1001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n ;
    cin >> n;
    int cnt = 0;
    for(int i=0; i<=n; i++){
        for(int v=0; v<=n-i; v++){
            for(int x=0; x<=n-i-v; x++){
                int l = n-i-v-x;
                int sum = (i*1) + (v*5) + (x*10) + (l*50);
                if(check[sum] == false){
                    check[sum] = true;
                    cnt +=1;
                }
            }
        }
    }
    cout << cnt;

    return 0;
}