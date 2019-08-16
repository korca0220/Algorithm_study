#include <iostream>
#include <vector>
using namespace std;
int N,L;
bool check(vector<int> &line){

    vector<int> c(N, false);
    for(int i=1; i<N; i++){
        if(line[i-1] != line[i]){
            int diff = abs(line[i-1] - line[i]);
            if(diff != 1) return false;
            if(line[i-1] < line[i]){
                for(int j=1; j<=L; j++){
                    if(i-j<0) return false;
                    if(line[i-1] != line[i-j]) return false;
                    if(c[i-j]) return false;
                    c[i-j] = true;
                }
            }else if(line[i-1] > line[i]){
                for(int j=0; j<L; j++){
                    if(i+j >= N) return false;
                    if(line[i] != line[i+j]) return false;
                    if(c[i+j]) return false;
                    c[i+j] = true;
                }
            }
        }
    }
    return true;
}

int main(){

    ios::sync_with_stdio(false);

    cin >> N >> L;
    vector<vector<int>> in(N, vector<int>(N));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> in[i][j];
        }
    }
    vector<int> garo;
    vector<int> sero;
    int ans = 0;
    for(int i=0; i<N; i++){
        garo.clear(); sero.clear();
        for(int j=0; j<N; j++){
            garo.push_back(in[i][j]);
            sero.push_back(in[j][i]);
        }
        if(check(garo)) ans += 1;
        if(check(sero)) ans += 1;
    }
    cout << ans;
    return 0;
}