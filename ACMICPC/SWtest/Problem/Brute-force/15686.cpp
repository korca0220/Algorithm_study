#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;

int N,M;
bool check[14];
int ans = 987654321;

int getMin(vector<pair<int,int>> &house, vector<pair<int,int>> &chick){

    int sum = 0;
    for(int i=0; i<house.size(); i++){
        int min = 987654321;
        for(int j=0; j<chick.size(); j++){
            if(check[j]){
                int d1 = abs(house[i].first-chick[j].first);
                int d2 = abs(house[i].second-chick[j].second);
                if(min > d1+d2)min = d1+d2;
            }
        }
        sum += min;
    }
    return sum;
}

void go(vector<pair<int,int>> &house, vector<pair<int,int>> &chick, int cnt, int index){

    if(cnt==M){
        int temp = getMin(house, chick);
        if(ans > temp)ans = temp;
        return ;
    }

    for(int i=index; i<chick.size(); i++){
        if(check[i] == false){
            check[i] = true;
            go(house, chick, cnt+1, i);
            check[i] = false;
        }
    }
    return ;

}

int main(){
    scanf("%d %d", &N, &M);
    vector<vector<int>> in(N, vector<int>(N));
    vector<pair<int,int>> house;
    vector<pair<int,int>> chick;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            scanf("%d", &in[i][j]);
            if(in[i][j] == 1)house.emplace_back(make_pair(i,j));
            else if(in[i][j] == 2) chick.emplace_back(make_pair(i,j));
        }
    }
    
    memset(check, false, sizeof(check));
    go(house, chick, 0, 0);
    printf("%d", ans);

    return 0;
}