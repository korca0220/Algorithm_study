#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

char color[] = "wyrogb";

void clockwise(vector<vector<char>> & a){
    int temp  = a[0][0];
    a[0][0] = a[2][0];
    a[2][0] = a[2][2];
    a[2][2] = a[2][0];
    a[0][2] = temp;
    temp = a[0][1];
    a[0][1] = a[1][0];
    a[1][0] = a[2][1];
    a[2][1] = a[1][2];
    a[1][2] = temp;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t_case;
    cin >> t_case;

    vector<vector<vector<char>>> q(6, vector<vector<char>>(3, vector<char>(3)));
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                q[i][j][k] = color[i];
            }
        }
    }
    while(t_case){
        int n;
        cin >> n;
        char in;
        for(int i=0; i<n; i++){
            cin >> in;
        }
    }
    return 0;
}