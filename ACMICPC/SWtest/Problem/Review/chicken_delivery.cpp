#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int n,m;
int in[51][51];
bool check[14];

int go(vector<pair<int,int>> &home, vector<pair<int,int>> &chick, int index, int cnt){

    if(cnt == m){
        int total=0;
        for(int i=0; i<home.size(); i++){
            int min_num = 987654321;
            for(int j=0; j<chick.size(); j++){
                if(check[j] == false) continue;
                int a = abs(home[i].first - chick[j].first);
                int b = abs(home[i].second - chick[j].second);
                if(min_num>(a+b))min_num = a+b; 
            }
            total += min_num;
        }
        return total;
    }
    int ans = 987654321;
    for(int i=index; i<chick.size(); i++){
        if(check[i])continue;
        check[i] = true;
        int temp = go(home, chick, i, cnt+1);
        if(ans > temp)ans=temp;
        check[i] = false;
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    vector<pair<int,int>> home;
    vector<pair<int,int>> chick;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> in[i][j];
            if(in[i][j] == 1)home.emplace_back(i,j);
            else if(in[i][j] == 2)chick.emplace_back(i,j);
        }
    }
    cout << go(home, chick, 0, 0);

    return 0;
}