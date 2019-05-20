#include <iostream>
#include <algorithm>
using namespace std;


int t_input;
int a, b;

int gcd(int one, int two){

    int num_one = max(one, two);
    int num_two = min(one, two);
    if (num_one % num_two == 0) return num_two;
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

        cin >> a >> b;
        cout << (a*b)/gcd(a,b) << "\n";
    }

    return 0;
}