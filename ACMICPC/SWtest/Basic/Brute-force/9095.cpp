#include <iostream>
using namespace std;

int input;
int t_input;
int total=0;

void getTotal(int count){

    if(count == input){
        total++;
        return ;
    }
    if(count > input) return;

    getTotal(count +1);
    getTotal(count +2);
    getTotal(count +3);
    
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t_input;

    while(t_input--){
        cin >> input;
        getTotal(0);
        cout << total << "\n";
        total = 0;
    }
    

    return 0;
}