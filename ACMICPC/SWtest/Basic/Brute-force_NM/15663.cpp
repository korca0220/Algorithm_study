#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
vector<int> in_num;
vector<vector<int>> contain_in_num;
vector<int> index_num;
bool selected[10];

void printNandM(int index){

    vector<int> temp;
    if(index == M){
        for(int i =0; i<M; i++){
            temp.push_back(in_num[index_num[i]]);
        }
        contain_in_num.push_back(temp);
        return ;
    }
    for(int i =0; i<N; i++){
        if(selected[i]) continue;
        selected[i] = true, index_num.push_back(i);
        printNandM(index+1);
        selected[i] = false, index_num.pop_back();
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int in_temp;
    for(int i =0; i<N; i++){
        cin >> in_temp;
        in_num.push_back(in_temp);
    }
    printNandM(0);
    sort(contain_in_num.begin(), contain_in_num.end());
    contain_in_num.erase(unique(contain_in_num.begin(), contain_in_num.end()), contain_in_num.end());

    for(auto &v : contain_in_num){
        for(int i=0; i<M; i++){
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}