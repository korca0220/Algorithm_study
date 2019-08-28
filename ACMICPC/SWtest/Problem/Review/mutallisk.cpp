#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 987654321;
int dp[61][61][61];
int cnt[3];

int getMin(int a, int b, int c){

    if(a<0) return getMin(0, b, c);
    if(b<0) return getMin(a, 0, c);
    if(c<0) return getMin(a, b, 0);
    if(a==0 && b==0 && c==0) return 0;
    int &ans = dp[a][b][c];
    if(ans != -1) return ans;

    ans = MAX;
    vector<int> p = {1,3,9};

    do{
        int temp = getMin(a-p[0], b-p[1], c-p[2]);
        if(ans > temp) ans = temp;
    }while(next_permutation(p.begin(), p.end()));
    ans +=1;
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    for(int i=0; i<n; i++)cin >> cnt[i];

    memset(dp, -1, sizeof(dp));
    cout << getMin(cnt[0], cnt[1], cnt[2]);
    return 0;
}