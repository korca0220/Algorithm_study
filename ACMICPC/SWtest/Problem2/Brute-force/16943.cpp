#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string a;
    int b;
    cin >> a >> b;
    
    sort(a.begin(), a.end());
    int ans = -1;
    do{
        int c = stoi(a);
        if(a[0] != '0' && c<=b){
            if(ans == -1 || ans < c){
                ans = c;
            }
        }
    }while(next_permutation(a.begin(), a.end()));
    cout << ans;

    return 0;
}