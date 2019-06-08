#include <iostream>
#include <vector>
using namespace std;

int N,M;
vector<int> number;

void printNandM(int index, int start){

    if(index==M){
        for(int i=0; i<number.size(); i++){
            cout << number[i] << " ";
        }
        cout << "\n";
        return ;
    }
    for(int i=start; i<=N; i++){
        number.push_back(i);
        printNandM(index+1, i);
        number.pop_back();
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >>  M;
    printNandM(0, 1);

    return 0;
}