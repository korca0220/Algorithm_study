#include <iostream>
#include <vector>
using namespace std;

int n;
int gather(vector<int> &in){

    int len = in.size();
    if(len == 2) return 0;
    int ans = 0;
    for(int i=1; i<len-1; i++){
        int sum = in[i-1] * in[i+1];
        vector<int> temp(in);
        temp.erase(temp.begin()+i);
        sum += gather(temp);
        if(ans<sum ) ans = sum;
    }
    return ans;

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    vector<int> in(n, 0);
    for(int i=0; i<n; i++)cin >> in[i];

    cout << gather(in);
    return 0;
}