#include <iostream>
#include <string>
using namespace std;

const int MONTH[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int t_input;
string input;


int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    cin >> t_input;
    int test_count = 1;
    while(t_input--){
        cin >> input;
        string year = input.substr(0, 4);
        string month = input.substr(4, 2);
        string day = input.substr(6, 2);

        int real_day = MONTH[stoi(month)];
        if (stoi(day) > real_day){
            cout << "#" << test_count << " -1\n";            
        }
        else{
            cout << "#" << test_count <<" " <<year << "/" << month << "/" << day << "\n";
        }
        test_count++;
    }
    

    return 0;
}