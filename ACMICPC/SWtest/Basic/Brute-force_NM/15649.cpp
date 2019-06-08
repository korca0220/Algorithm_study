#include <iostream>
#include <vector>
using namespace std;

int N, M;
bool selected[10];
vector<int> number;

void printNandM(int index){

    if(index==M){
        for(int i=0; i<number.size(); i++){
            cout << number[i] << " ";
        }
        cout << "\n";
        return ; 
    }
    for(int i = 1; i<=N; i++){
        if(selected[i]) continue;
        selected[i] = true, number.push_back(i);
        printNandM(index +1);
        selected[i] = false, number.pop_back();
    }

}
int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    printNandM(0);

    return 0;
}