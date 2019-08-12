#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int dp[50][50][50][3][3];
string in;
int al_num[50];

bool check(int a, int b, int c, int p1, int p2){
    int &ans = dp[a][b][c][p1][p2]; //memoization
    if(a+b+c == 0){
        return 1;
    }

    if(ans != -1 ) return ans;
    if(a>0 && check(a-1, b, c, 0, p1) == 1){
        return ans = 1;
    }

    if(b>0 && p1 != 1){
        if(check(a,b-1,c, 1, p1) == 1){
            return ans = 1;
        }
    }

    if(c>0 && p1 != 2 && p2 != 2){
        if(check(a,b,c-1, 2, p1) == 1){
            return ans = 1;
        }
    }

    return ans = 0;
}

string getHistory(int a, int b, int c, int p1, int p2){

    if(a+b+c == 0){
        return "";
    }

    if(a>0 && check(a-1, b, c, 0, p1) == 1){
        return "A" + getHistory(a-1,b,c,0,p1);
    }

    if(b>0 && p1 != 1){
        if(check(a,b-1,c,1,p1)==1){
            return "B" + getHistory(a,b-1,c,1,p1);
        }
    }

    if(c>0 && p1 != 2 && p2 != 2){
        if(check(a,b,c-1, 2, p1) == 1){
            return "C" + getHistory(a,b,c-1, 2, p1);
        }
    }
    return "";

}

int main(){
    cin >> in;

    for(int i=0; i<in.length(); i++){
        al_num[in[i]-'A'] += 1;
    }

    memset(dp, -1, sizeof(dp));
    int ans = check(al_num[0], al_num[1], al_num[2], 0, 0);
    if(ans == 0){
        printf("-1");
    }else{
        cout << getHistory(al_num[0], al_num[1], al_num[2], 0, 0);
    }

    return 0;
}