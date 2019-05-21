#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 10;

int t_input;

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t_input;

    int in;
    int test_count = 1;
    while(t_input--){
        vector<int> input;
        for(int i=0; i<MAX; i++){
            cin >> in;
            input.push_back(in);
        }
        vector<int>::const_iterator it;
        it = max_element(input.begin(), input.end());
        cout << "#" << test_count << " " << *it << "\n";
        test_count++;
    }

    return 0;
}