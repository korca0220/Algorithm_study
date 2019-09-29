#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++){
        int kg, cm;
        cin >> kg >> cm;
        v.emplace_back(kg, cm);
    }
    int count;
    for(int i=0; i<v.size(); i++){
        count = 1;
        for(int j=0; j<v.size(); j++){
            if(i==j)continue;
            if(v[i].first < v[j].first && v[i].second < v[j].second){
                count += 1;
            }
        }
        cout << count << " ";
    }
    return 0;
}