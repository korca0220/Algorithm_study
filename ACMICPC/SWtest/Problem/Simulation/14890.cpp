#include <iostream>
#include <vector>
using namespace std;

bool getCheck(vector<int> &in, int len){

    int n = in.size();
    vector<bool> check(n, false);
    for(int i=1; i<n; i++){
        if(in[i-1] != in[i]){
            int diff = abs(in[i-1] - in[i]);
            if(diff != 1){
                return false;
            }
            if(in[i-1] < in[i]){
                for(int j=1; j<=len; j++){
                    if(i-j < 0) return false;
                    if(in[i-1] != in[i-j]) return false;
                    if(check[i-j]) return false;
                    check[i-j] = true;
                }
                
            }else if(in[i-1] > in[i]){
                for(int j=0; j<len; j++){
                    if(i+j >= n) return false;
                    if(in[i] != in[i+j]) return false;
                    if(check[i+j]) return false;
                    check[i+j] = true;
                }
            }
        }
    }
    return true;
}

int main(){

    int n,l;
    scanf("%d %d", &n, &l);
    vector<vector<int>> in(n, vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%d", &in[i][j]);
        }
    }

    int ans = 0;
    for(int i=0; i<n; i++){
        vector<int> row;
        vector<int> col;
        for(int j=0; j<n; j++){
            row.push_back(in[i][j]);
            col.push_back(in[j][i]);
        }
        if(getCheck(row, l)) ans+=1;
        if(getCheck(col, l)) ans+=1;
    }
    printf("%d", ans);

    return 0;
}