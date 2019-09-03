#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

int n;
vector<pair<string, int>> in;
vector<char> ans;

bool check(string s, string prefix, string suffix){

    for(int i=0; i<prefix.length(); i++){
        if(s[i] != prefix[i]) return false;
    }
    for(int i=0; i<suffix.length(); i++){
        if(s[n-i-1] != suffix[suffix.length()-i-1]) return false;
    }
    return true;
}

bool go(string prefix, string suffix){
    string full = prefix + suffix.back();
    for(int i=0; i<n-1; i++){
        if(check(full, in[i*2].first, in[i*2+1].first)){
            ans[in[i*2].second] = 'P';
            ans[in[i*2+1].second] = 'S';
        }else if(check(full, in[i*2+1].first, in[i*2].first)){
            ans[in[i*2+1].second] = 'P';
            ans[in[i*2].second] = 'S';
        }else return false;
    }

    cout << full << "\n";
    for(int i=0; i<ans.size(); i++){
        cout << ans[i];
    }
    return true;

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    ans.resize(2*n-2);
    for(int i=0; i<2*n-2; i++){
        string temp;
        cin >> temp;
        in.emplace_back(temp, i);
    }
    sort(in.begin(), in.end(), [](const auto &u, const auto &v) -> bool{
        return u.first.length() < v.first.length();
    });

    if(go(in[2*n-4].first, in[2*n-3].first) == false){
        go(in[2*n-3].first, in[2*n-4].first);
    }
    return 0;
}