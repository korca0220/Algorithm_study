#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t_input, input;
int count_number = 0;

void findSum(int sum){

    if(sum > input) return ;
    if(sum == input){
        count_number +=1;
        return ;
    }else{
        findSum(sum+1);
        findSum(sum+2);
        findSum(sum+3);
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t_input;
    while(t_input--){
        count_number = 0;
        cin >> input;
        findSum(0);
        cout << count_number << "\n";
    }

    return 0;
}