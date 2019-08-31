#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

string color = "wrbogy";

void clockwise(vector<vector<char>> &a){
    int temp  = a[0][0];
    a[0][0] = a[2][0];
    a[2][0] = a[2][2];
    a[2][2] = a[0][2];
    a[0][2] = temp;
    temp = a[0][1];
    a[0][1] = a[1][0];
    a[1][0] = a[2][1];
    a[2][1] = a[1][2];
    a[1][2] = temp;
}
void R(vector<vector<vector<char>>> &a){

    vector<vector<char>> temp = a[0];
    for(int i=0; i<3; i++){
        a[0][i][2] = a[1][i][2];
        a[1][i][2] = a[5][i][2];
        a[5][i][2] = a[3][i][2];
        a[3][i][2] = temp[i][2];
    }
    clockwise(a[2]);
}
void L(vector<vector<vector<char>>> &a){

    vector<vector<char>> temp = a[0];
    for(int i=0; i<3; i++){
        a[0][i][0] = a[3][i][0];
        a[3][i][0] = a[5][i][0];
        a[5][i][0] = a[1][i][0];
        a[1][i][0] = temp[i][0];
    }
    clockwise(a[4]);
}

void F(vector<vector<vector<char>>> &a){

    vector<vector<char>> temp = a[1];
    a[1] = a[4];
    a[4] = a[3];
    a[3] = a[2];
    a[2] = temp;
    clockwise(a[0]); clockwise(a[0]); clockwise(a[0]);
    clockwise(a[1]); clockwise(a[1]); clockwise(a[1]);
    clockwise(a[2]); clockwise(a[2]); clockwise(a[2]);
    clockwise(a[3]); clockwise(a[3]); clockwise(a[3]);
    clockwise(a[4]); clockwise(a[4]); clockwise(a[4]);
    clockwise(a[5]); 
}
void U(vector<vector<vector<char>>> &a){
    vector<vector<char>> temp = a[0];
    a[0] = a[4];
    a[4] = a[5];
    a[5] = a[2];
    a[2] = temp;
    clockwise(a[4]); clockwise(a[4]);
    clockwise(a[5]); clockwise(a[5]);
    clockwise(a[1]);
    clockwise(a[3]); clockwise(a[3]); clockwise(a[3]);
}

void printColor(vector<vector<vector<char>>> a){

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << a[0][i][j];
        }
        cout << "\n";
    }
}
vector<vector<vector<char>>> setInit(){
    vector<vector<vector<char>>> in(6, vector<vector<char>>(3, vector<char>(3)));
    for(int i=0; i<6; i++){
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                in[i][j][k] = color[i];
            }
        }
    }
    return in;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t_case;
    cin >> t_case;

    while(t_case--){
        vector<vector<vector<char>>> q = setInit();
        int n;
        cin >> n;
        string in;
        for(int i=0; i<n; i++){
            cin >> in;
            int k = (in[1] == '-'? 3:1);            
            if(in[0] == 'R'){
                for(int r=0; r<k; r++)R(q);
            }else if(in[0] == 'L'){
                for(int r=0; r<k; r++)L(q);
            }else if(in[0] == 'F'){
                F(q); // 오른쪽으로 큐빅 회전
                for(int r=0; r<k; r++)R(q);
                for(int w=0; w<3; w++)F(q); // 원상복귀
            }else if(in[0] == 'B'){
                F(q);
                for(int r=0; r<k; r++)L(q);
                for(int w=0; w<3; w++)F(q);
            }else if(in[0] == 'U'){
                U(q); // 오른쪽으로 큐빅 굴리기
                for(int r=0; r<k; r++)R(q);
                for(int w=0; w<3; w++)U(q);
            }else if(in[0] == 'D'){
                U(q);
                for(int r=0; r<k; r++)L(q);
                for(int w=0; w<3; w++)U(q);
            }
        }
        printColor(q);
    }
    return 0;
}