#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int n;
int in[21][21];

int calcul(vector<int> &one, vector<int> &two){

    int o_size = one.size();
    int t_size = two.size();

    int total1, total2;
    total1=total2 = 0;
    for(int i=0; i<o_size; i++){
        for(int j=0; j<o_size; j++){
            if(i!=j){
                total1 += in[one[i]][one[j]];
            }
        }
    }
    for(int i=0; i<t_size; i++){
        for(int j=0; j<t_size; j++){
            if(i!=j){
                total2 += in[two[i]][two[j]];
            }
        }
    }
    int diff = abs(total1 - total2);
    return diff;
}


int main(){

    ios::sync_with_stdio(false);

    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> in[i][j];
        }
    }

    vector<int> one, two;
    int ans = 987654321;
    for(int i=0; i<(1<<n)-1; i++){
        one.clear();
        two.clear();
        for(int j=0; j<n; j++){
            if(i&(1<<j))one.push_back(j);
            else two.push_back(j);
        }
        int temp = calcul(one, two);
        ans = min(ans, temp);
    }   
    cout << ans;

    return 0;
}