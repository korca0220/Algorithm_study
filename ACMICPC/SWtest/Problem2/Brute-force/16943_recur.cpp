#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int a[11];
int n,b;
bool check[11];

int go(int index, int num){

    if(index==n) return num;
    int ans = -1;
    for(int i=0; i<n; i++){
        if(check[i]) continue;
        if(index==0 && a[i] == 0)continue;
        check[i] = true;
        int temp = go(index+1, num*10+a[i]);
        if(temp <= b){
            if(ans == -1 || ans< temp) ans = temp;
        }
        check[i] = false;
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str >> b;
    n = str.length();
    for(int i=0; i<n; i++)a[i] = str[i]-'0';

    cout << go(0, 0);

    return 0;
}