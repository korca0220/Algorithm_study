#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;


int main(){

    cin.sync_with_stdio(false);

    
    while(true){
        cin >> input;    
        if ( input == 0) break;
        vector<int> number;
        vector<int> temp;

        int temp_number_input;
        
        for(int i=0; i<input; i++){
            cin >> temp_number_input;
            number.push_back(temp_number_input);
        }

        for(int i=0; i<6; i++)temp.push_back(1);
        for(int i=0; i<input-6; i++)temp.push_back(0);

        
        do{
            for(int i=0; i<input; i++){
                if(temp[i] != 0) cout << number[i] << " "; 
            }
            cout << "\n";
        }while(prev_permutation(temp.begin(), temp.end()));
        cout << "\n";

        
    }

    return 0;
}