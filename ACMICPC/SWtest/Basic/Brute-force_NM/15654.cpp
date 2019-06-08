#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
vector<int> number;
vector<int> p_number;
bool selected[10];


void printNandM(int index){

    if(index == M){
        for(int i=0; i<p_number.size(); i++){
            cout << number[p_number[i]] << " ";
        }
        cout << "\n";
        return ;
    }
    
    for(int i=0; i<N; i++){
        if(selected[i]) continue;
        selected[i] = true;
        p_number.push_back(i);
        printNandM(index+1);
        selected[i] = false;
        p_number.pop_back();
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
        number.push_back(temp);
    }
    sort(number.begin(), number.end());
    printNandM(0);

    return 0;
    
}