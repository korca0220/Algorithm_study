#include <iostream>
#include <string>
#include <string>
#include <algorithm>
using namespace std;

int in[101];
int c,p;

int cal(int s, string block){

    if(s + block.length() > c) return 0;
    int base = in[s] - (block[0] - '0');
    for(int i=1; i<block.length(); i++){
        if(base != in[s+i] - (block[i]-'0')) return 0;
    }
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> c >> p;
    for(int i=0; i<c; i++)cin >> in[i];

    int ans = 0;
    for(int i=0; i<c; i++){
        if(p==1){
            ans += cal(i, "0") + cal(i, "0000");
        }else if(p==2){
            ans += cal(i, "00");
        }else if(p==3){
            ans += cal(i, "001") + cal(i, "10");
        }else if(p==4){
            ans += cal(i, "100") + cal(i, "01");
        }else if(p==5){
            ans += cal(i, "000") + cal(i, "01") + cal(i, "101") + cal(i, "10");
        }else if(p==6){
            ans += cal(i, "000") + cal(i, "00") + cal(i, "011") + cal(i, "20");
        }else if(p==7){
            ans += cal(i, "000") + cal(i, "02") + cal(i, "110") + cal(i, "00");
        }
    }
    cout << ans;

    return 0;
}