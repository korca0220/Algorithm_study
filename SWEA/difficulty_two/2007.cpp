#include <iostream>
#include <string>
using namespace std;

int t_input;
string input;

int getCheckPattern(string in_str){

    string temp_str = "";
    string correct_str = "";
    for(int i=0; i<in_str.length(); i++){
        bool check = true;
        temp_str = temp_str+ in_str[i];
        if(temp_str.length() >= 2){
            for(int j=0; j<temp_str.length(); j++){
                if(temp_str[j] == in_str[i+j+1]) continue;
                else {
                    check = false;
                    break;
                }
            }
            if(check) {
                correct_str = temp_str;
                break;
            }
        }
    }

    return correct_str.length();
}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t_input;
    int test_count = 1;
    while(t_input--){
        cin >> input;
        cout << "#" << test_count << " "<< getCheckPattern(input)<< "\n";
        test_count++;        
    }

    return 0;
}