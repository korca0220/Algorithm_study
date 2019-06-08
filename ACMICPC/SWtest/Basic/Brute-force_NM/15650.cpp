#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool selected[10];
vector<int> number;

void printNandM(int index, int start){

    if(index==M){
        for(int i=0; i<number.size(); i++){
            cout << number[i] << " ";
        }
        cout << "\n";
        return ;
    }
    for(int i = start; i<=N; i++){
        number.push_back(i);
        printNandM(index+1, i+1);
        number.pop_back();
    }
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    printNandM(0, 1);

    return 0;
}