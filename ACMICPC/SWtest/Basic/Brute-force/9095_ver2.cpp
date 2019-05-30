#include <iostream>
using namespace std;

int t_input, input;
int total;

void getTotal(int count){

    if(count == input){
        total++;
        return ;
    }
    if(count > input) return;

    for(int i=1; i<=3; i++){
        getTotal(count + i);
    }
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t_input;
    while(t_input--){
        total = 0;
        cin >> input;
        getTotal(0);
        cout << total << "\n";
    }


    return 0;
}