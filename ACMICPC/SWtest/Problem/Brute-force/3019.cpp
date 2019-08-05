#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C,P;
int in[101];

int cal(int c, string t){

    if(c+t.size() > C) return 0;
    int base = in[c] - (t[0] - '0');
    for(int i=1; i<t.size(); i++){
        if(base != in[c+i] - (t[i]-'0')) return 0;
    }
    return 1;

}

int main(){

    scanf("%d %d", &C, &P);
    for(int i=0; i<C; i++)scanf("%d", &in[i]);

    int ans = 0;
    for(int i=0; i<C; i++){
        if(P == 1){
            ans += cal(i, "0") + cal(i, "0000");
        }
        else if(P==2){
            ans += cal(i, "00");
        }
        else if(P==3){
            ans += cal(i, "001") + cal(i, "10");
        }
        else if(P==4){
            ans += cal(i, "100") + cal(i, "01");
        }
        else if(P==5){
            ans += cal(i, "000") + cal(i, "01") + cal(i, "101") + cal(i, "10");
        }
        else if(P==6){
            ans += cal(i, "000") + cal(i, "00") + cal(i, "011") + cal(i, "20");
        }
        else if(P==7){
            ans += cal(i, "000") + cal(i, "02") + cal(i, "110") + cal(i, "00");
        }
    }
    printf("%d", ans);

    return 0;
}