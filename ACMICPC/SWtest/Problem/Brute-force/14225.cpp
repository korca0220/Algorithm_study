#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 2000000;
int in[21];
bool check[MAX+1];

int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)scanf("%d", &in[i]);

    for(int i=1; i<(1<<n); i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            if(i&(1<<j)) sum += in[j];
        }
        check[sum] = true;
    }
    for(int i=1; i<=MAX; i++){
        if(check[i] == false){
            printf("%d", i);
            break;
        }
    }    

    return 0;
}