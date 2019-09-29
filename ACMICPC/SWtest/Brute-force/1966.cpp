#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <utility>
#include <deque>
#include <algorithm>
using namespace std;

int main(){

    int t_case;
    int n,m;
    cin >> t_case;
    while(t_case--){
        cin >> n >> m;
        vector<int> v;
        deque<pair<int,int>> dq;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            v.push_back(temp);
            dq.emplace_back(temp, i);
        }
        sort(v.begin(), v.end());

        int count = 0;
        while(!dq.empty()){
            int x,y;
            tie(x,y) = dq.front();
            if(x == v.back()){
                count+=1;
                v.pop_back();
                if(y == m)break;
            }else{
                dq.emplace_back(x,y);
            }
            dq.pop_front();
        }
        cout << count << "\n";
    }


    return 0;
}