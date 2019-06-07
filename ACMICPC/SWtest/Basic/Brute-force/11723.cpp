#include <iostream>
#include <vector>
#include <string>
using namespace std;

int t_input;
int bit = 0;

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t_input;

    string temp_oper;
    int temp_value;
    while(t_input--){
        cin >> temp_oper;
        if (temp_oper == "all") bit = (1 << 21) - 1;
        else if (temp_oper == "empty") bit = 0;
        else cin >> temp_value;
        
        if(temp_oper == "add")bit =  bit | (1 << temp_value - 1);
        else if(temp_oper == "remove") bit = bit & ~(1 << temp_value - 1);
        else if(temp_oper == "check"){
            if(bit & (1 << temp_value-1))cout << "1\n";
            else cout << "0\n";
        }
        else if(temp_oper == "toggle") bit = bit ^ (1 << temp_value - 1);
    }

    return 0;
}