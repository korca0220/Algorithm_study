#include <iostream>
#include <string>
#include <set>
#include <queue>
#include <utility>
#include <algorithm>
typedef long long ll;
using namespace std;

const int MAX = 1000000000LL;

ll s, t;

void bfs(ll s, ll t){

    queue<pair<ll, string>> q;
    set<ll> dist;
    q.emplace(s, "");
    dist.insert(s);
    while(!q.empty()){
        ll x = q.front().first;
        string str = q.front().second;
        q.pop();
        if(x==t){
            cout << str;
            return ;
        }
        if(0<=x*x && x*x<=MAX && dist.count(x*x) == 0){
            q.emplace(x*x, str+"*");
            dist.insert(x*x);
        }
        if(0<=x+x && x+x<=MAX && dist.count(x+x) == 0){
            q.emplace(x+x, str+"+");
            dist.insert(x+x);
        }
        if(0<=x-x && x-x<=MAX && dist.count(x-x) == 0){
            q.emplace(x-x, str+"-");
            dist.insert(x-x);
        }
        if(0<=x/x && x/x<=MAX && dist.count(x/x) == 0){
            q.emplace(x/x, str+"/");
            dist.insert(x/x);
        }
    }
    cout << "-1";

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s >> t;
    if(s==t){
        cout << "0";
        return 0;
    }
    bfs(s, t);

    return 0;
}