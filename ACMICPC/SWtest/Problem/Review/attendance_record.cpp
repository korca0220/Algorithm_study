#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[50][50][50][3][3];
int cnt[3];

int check(int a, int b, int c, int p1, int p2){

    int &ans = dp[a][b][c][p1][p2];
    if(a+b+c == 0) return ans = 1;
    if(ans != -1) return ans;

    if(a>0 && check(a-1, b, c, 0, p1) == 1){
        return ans = 1;
    }
    if(b>0 && p1 != 1){
        if(check(a,b-1,c,1,p1) == 1){
            return ans = 1;
        }
    }
    if(c>0 && p1 != 2 && p2 != 2){
        if(check(a,b,c-1, 2, p1)==1){
            return ans = 1;
        }
    }
    return ans = 0;

}
string getHistory(int a, int b, int c, int p1, int p2){

    if(a+b+c == 0) return ""; //end;

    if(a>0 && check(a-1, b, c, 0, p1) == 1){
        return "A" + getHistory(a-1, b, c, 0, p1);
    }

    if(b>0 && p1 != 1){
        if(check(a,b-1, c, 1, p1) == 1){
            return "B" + getHistory(a, b-1, c, 1, p1);
        }
    }
    if(c>0 && p1 != 2 && p2 != 2){
        if(check(a,b,c-1, 2, p1) == 1){
            return "C" + getHistory(a,b,c-1, 2, p2);
        }
    }
    return "";
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    for(int i=0; i<str.length(); i++){
        cnt[str[i]-'A'] += 1;
    }

    memset(dp, -1, sizeof(dp));
    int ans = check(cnt[0], cnt[1], cnt[2], 0, 0);
    if( ans == 0){
        cout << "-1";
    }else{
        cout << getHistory(cnt[0], cnt[1], cnt[2], 0, 0);
    }

    return 0;
}