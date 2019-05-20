#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 100;
int t_input, t_num;
int input[MAX];

long gcd(long one, long two){

    long num_one = max(one, two);
    long num_two = min(one, two);
    if(num_one % num_two == 0)return num_two;
    else{
        return gcd(num_two, num_one%num_two);
    }

}


int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t_input;
    while(t_input--){
        long sum = 0;
        cin >> t_num;
        for(int i=0; i<t_num; i++){
            cin >> input[i];
        }
        for(int i=0; i<t_num-1; i++){
            for(int j=i+1; j<t_num; j++){
                sum += gcd(input[i], input[j]);
            }
        }
        cout << sum << "\n";

    }

    return 0;
}