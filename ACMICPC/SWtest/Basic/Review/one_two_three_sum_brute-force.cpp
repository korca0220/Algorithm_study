#include <iostream>
#include <vector>
using namespace std;

int t_input, input;
int total;
void getTotal(int sum){

    if(sum > input) return ;
    if(sum == input){
        total++;
        return ;
    }else{
        getTotal(sum + 1);
        getTotal(sum + 2);
        getTotal(sum + 3);
    }

}
int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t_input;
    while(t_input--){
        cin >> input;
        total = 0;
        getTotal(0);
        cout << total<<"\n";
    }

    return 0;

}