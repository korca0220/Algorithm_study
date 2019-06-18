#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    int t_input;
    do{
        vector<int> lotto;
        vector<int> d;
        cin >> t_input;
        for(int i=0; i<6; i++)d.push_back(1);
        for(int i=0; i<t_input-6; i++)d.push_back(0);
        for(int i=0; i<t_input; i++){
            int temp;
            cin >> temp;
            lotto.push_back(temp);
        }
        do{
            for(int i=0; i<t_input; i++){
                if (d[i] != 0) cout << lotto[i] << " "; 
            }
            cout << "\n";
        }while(prev_permutation(d.begin(), d.end()));
        cout << "\n";
    }while(t_input != 0);


    return 0;
}