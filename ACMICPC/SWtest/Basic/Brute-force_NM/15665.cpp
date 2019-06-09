#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> in_num, in_temp;
vector<vector <int>> contain_num;

void getContainVector(int index){

    if(index == M){
        vector<int> temp;
        for(int i =0; i<M; i++){
            temp.push_back(in_num[in_temp[i]]);
        }
        contain_num.push_back(temp);
        return ;
    }
    for(int i =0; i<N; i++){
        in_temp.push_back(i);
        getContainVector(index +1);
        in_temp.pop_back();
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int temp;
    for(int i=0; i<N; i++){
        cin >> temp;
        in_num.push_back(temp);
    }
    sort(in_num.begin(), in_num.end());
    getContainVector(0);
    sort(contain_num.begin(), contain_num.end());
    contain_num.erase(unique(contain_num.begin(), contain_num.end()), contain_num.end());

    for(auto &v : contain_num){
        for(int i=0; i<M; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}