#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int input;
vector<int> N;
vector<int> O;
int oper[4];

int min_num = 9887654321;
int max_num = -987654321;
int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> input;
    for(int i=0; i<input; i++){
        int temp;
        cin >>temp;
        N.push_back(temp);
    }
    for(int i=0; i<4; i++){
        cin >> oper[i];
    }
    for(int i=0; i<4; i++){
        for(int j=0; j<oper[i]; j++){
            O.push_back(i);
        }
    }
    do{
        int sum = N[0];            
        for(int i=1; i<input; i++){
            if(O[i-1] == 0)sum+=N[i];
            else if(O[i-1] == 1)sum-=N[i];
            else if(O[i-1] == 2)sum*=N[i];
            else if(O[i-1] == 3)sum/=N[i];
        }
        min_num = min(min_num, sum);
        max_num = max(max_num, sum);
    }while(next_permutation(O.begin(), O.end()));

    cout << max_num << "\n";
    cout << min_num << "\n";

    return 0;
}