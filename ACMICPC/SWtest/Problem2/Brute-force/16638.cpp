#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Term{
    int num;
    int op;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int n;
    cin >> n;
    cin >> str;

    vector<Term> in(n);
    for(int i=0; i<n; i++){
        if(i%2==0){
            in[i] = {str[i]-'0', 0};
        }else{
            int op = 1;
            if(str[i] == '-')op=2;
            else if(str[i] == '*')op=3;
            in[i] = {0, op};
        }
    }

    int m = (n-1)/2;
    int ans = -987654321;
    for(int i=0; i<(1<<m); i++){
        bool pass = true;
        for(int j=0; j<m-1; j++){
            if( (i&(1<<j)) && (i&(1<<(j+1)))){
                pass = false;
            }
        }
        if(!pass) continue;
        vector<Term> priority(in);
        for(int j=0; j<m; j++){
            if(i & (1<<j)){
                int k = 2*j+1;
                if(priority[k].op == 1){
                    priority[k-1].num += priority[k+1].num;
                    priority[k].op = -1;
                    priority[k+1].num = 0;
                }else if(priority[k].op == 2){
                    priority[k-1].num -= priority[k+1].num;
                    priority[k].op = -1;
                    priority[k+1].num = 0;
                }else if(priority[k].op == 3){
                    priority[k-1].num *= priority[k+1].num;
                    priority[k].op = -1;
                    priority[k+1].num = 0;
                }
            }
        }
        vector<Term> c;
        for(int j=0; j<n; j++){
            if(j%2==0){
                c.push_back(priority[j]);
            }else{
                if(priority[j].op == -1){
                    j += 1;
                }else{
                    if(priority[j].op == 3){
                        int num = c.back().num * priority[j+1].num;
                        c.pop_back();
                        c.push_back({num, 0});
                        j+=1;
                    }else{
                        c.push_back(priority[j]);
                    }
                }
            }
        }
        int res = c[0].num;
        int m2 = (c.size()-1)/2;
        for(int j=0; j<m2; j++){
            int k = j*2+1;
            if(c[k].op==1) res += c[k+1].num;
            else if(c[k].op==2) res -= c[k+1].num;
        }
        if(res > ans) ans = res;
    }
    cout << ans;

    return 0;
}