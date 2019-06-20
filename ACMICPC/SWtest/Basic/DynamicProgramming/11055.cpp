#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> num;
int S[1001];

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
    }

    for(int i=0; i<N; i++){
        S[i] = num[i];
        for(int j=0; j<i; j++){
            if(num[i] > num[j] && S[i] < S[j]+num[i]){
                S[i] = S[j] + num[i];
            }
        }
    }
    int max_number = 0;
    for(int i=0; i<N; i++){
        max_number = max(max_number, S[i]);
    }
    cout << max_number;

    return 0;
}