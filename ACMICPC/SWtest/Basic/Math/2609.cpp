#include <iostream>
#include <algorithm>
using namespace std;

int a, b;

int gcd(int one, int two){

    int num_one = max(one, two);
    int num_two = min(one, two);
    if (num_one % num_two == 0)return num_two;

    else{
        return gcd(num_two, num_one%num_two);
    }

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    int gcd_num = gcd(a,b);
    cout << gcd_num << "\n" << (a*b)/gcd_num;

    return 0;
}