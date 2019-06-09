#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> in_num;
vector<int> temp;

void printNandM(int index, int start){

    if(index == M){
        for(int i =0; i<M; i++){
            cout << in_num[temp[i]] << " ";
        }
        cout << "\n";
        return ;
    }
    for(int i = start; i<N; i++){
        temp.push_back(i);
        printNandM(index+1, i);
        temp.pop_back();
    }
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    int in_temp;
    for(int i= 0; i<N; i++){
        cin >> in_temp;
        in_num.push_back(in_temp);
    }

    sort(in_num.begin(), in_num.end());
    printNandM(0, 0);

    return 0;
}