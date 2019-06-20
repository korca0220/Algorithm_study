#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N;
vector<int> num;
int dist[1001];
int b_dist[1001];

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++){
        int temp;
        cin >> temp;
        num.push_back(temp);
    }
    int max_number_one=0;
    // 0 ~ N 까지 LIS
    for(int i=0; i<N; i++){
        dist[i] = 1;
        for(int j=0; j<i; j++){
            if(num[i] > num[j] && dist[i] < dist[j] + 1){
                dist[i] = dist[j] +1;
            }
        }        
    }

    // N ~ 0 까지 LIST
    for(int i=N-1; i>=0; i--){
        b_dist[i] = 1;
        for(int j=N-1; j>i; j--){
            if(num[i] > num[j] && b_dist[i] < b_dist[j]+1){
                b_dist[i] = b_dist[j] + 1;
            }
        }
    }

    for(int i=0; i<N; i++)max_number_one = max(max_number_one, dist[i]+b_dist[i]);
    cout << max_number_one-1 ;

    return 0;
}