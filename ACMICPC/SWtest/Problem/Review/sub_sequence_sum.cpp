#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 2000000;
int in[21];
bool check[MAX+1];
int n;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++)cin>>in[i];

    for(int i=0; i<(1<<n); i++){
        int sum = 0;
        for(int j=0; j<n; j++){
            if(i&(1<<j))sum += in[j];
            check[sum] = true;
        }
    }
    for(int i=0; i<MAX; i++){
        if(check[i] == false){
            cout << i;
            break;
        }
    }

    return 0;
}