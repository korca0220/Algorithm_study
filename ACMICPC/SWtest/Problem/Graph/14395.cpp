#include <iostream>
#include <queue>
#include <string>
#include <set>
#include <utility>
#include <tuple>
#include <algorithm>
typedef long long ll;
using namespace std;

const ll MAX = 1000000000LL;

void bfs(ll s, ll t){

    queue<pair<ll, string>> q;
    q.emplace(s, "");
    set<ll> check;
    check.insert(s);
    while(!q.empty()){
        ll x;
        string str;
        tie(x,str) = q.front();
        q.pop();
    
        if(x == t){
            if(str.length() == 0){
                str = "0";
            }
            cout << str;
            return ;
        }
        if(0<= x*x && x*x <= MAX && check.count(x*x) == 0){
            q.emplace(x*x, str+"*");
            check.insert(x*x);
        }
        if(0<= x+x && x+x <= MAX && check.count(x+x) == 0){
            q.emplace(x+x, str+"+");
            check.insert(x+x);
        }
        if(0<= x-x && x-x <= MAX && check.count(x-x) == 0){
            q.emplace(x-x, str+"-");
            check.insert(x-x);
        }
        if(0<= x/x && x/x <= MAX && check.count(x/x) == 0){
            q.emplace(x/x, str+"/");
            check.insert(x/x);
        }
    }
    printf("-1");
}

int main(){
    ll s, t;
    scanf("%lld %lld", &s, &t);
    bfs(s, t);

    return 0;
}