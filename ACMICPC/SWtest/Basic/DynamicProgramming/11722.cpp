#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N;
vector<int> num;
int dist[1001];

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin>> N;
    for(int i=0; i<N; i++){
        int temp;
        cin >>temp;
        num.push_back(temp);
    }

    for(int i=0; i<N; i++){
        dist[i] = 1;
        for(int j=0; j<i; j++){
            if(num[i] < num[j] && dist[i] < dist[j] + 1){
                dist[i] = dist[j] +1;
            }
        }
    }

    int max_number = 0;
    for(int i=0; i<N; i++){
        max_number = max(max_number, dist[i]);
    }
    cout << max_number;

    return 0;
}