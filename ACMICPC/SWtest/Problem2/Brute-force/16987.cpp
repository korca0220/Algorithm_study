#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int s[9];
int w[9];
int n;

int go(int index){

    if(index == n){
        int cnt=0;
        for(int i=0; i<n; i++){
            if(s[i] <= 0){
                cnt+=1;
            }
        }
        return cnt;
    }
    if(s[index] <=0) return go(index+1);

    int ans=0;
    bool ok = false;
    for(int i=0; i<n; i++){
        if(i == index) continue;
        if(s[i] <=0) continue;
        ok = true;
        s[index] -= w[i];
        s[i] -= w[index];
        int temp = go(index+1);
        if(temp > ans) ans = temp;
        s[index] += w[i];
        s[i] += w[index];
    }
    if(!ok) return go(index+1);

    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> s[i] >> w[i];
    }    
    cout << go(0);

    return 0;
}