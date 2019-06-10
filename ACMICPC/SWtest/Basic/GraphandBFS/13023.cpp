#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int N,M;
bool a[2000][2000];
vector<pair<int, int>> friends;
vector<int> g[2000];

int main(){
    
    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N  >> M;
    for(int i=0; i<M; i++){
        int temp_one, temp_two;
        cin >> temp_one >> temp_two;
        // 인접 리스트
        friends.push_back({temp_one, temp_two});
        friends.push_back({temp_two, temp_one});
        // 인접 행렬
        a[temp_one][temp_two] = a[temp_two][temp_one] = true;
        // 간선 리스트
        g[temp_one].push_back(temp_two);
        g[temp_two].push_back(temp_one);
    }
    M *= 2;
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            int A = friends[i].first;
            int B = friends[i].second;

            int C = friends[j].first;
            int D = friends[j].second;
            if( A == B || A == C || A == D || B == C || B == D || C == D){
                continue;
            }

            if(!a[B][C]) continue;

            for(int E : g[D]){
                if(A == E || B == E || C == E || D == E)continue;
                cout << "1";
                return 0;
            }
        }
    }
    cout << "0" ;
    return 0;
}

