#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int lcd[10][7] = {
    {1,1,1,0,1,1,1},
    {0,0,1,0,0,1,0},
    {1,0,1,1,1,0,1},
    {1,0,1,1,0,1,1},
    {0,1,1,1,0,1,0},
    {1,1,0,1,0,1,1},
    {1,1,0,1,1,1,1},
    {1,0,1,0,0,1,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,0,1,1}
};


int main(){
    
    ios::sync_with_stdio(false);
    int s;
    string number;
    cin >> s >> number;

    int len = number.length();
    for(int i=0; i<5; i++){
        if(i==0 || i==2 || i==4){
            for(int j=0; j<len; j++){
                int num = number[j] - '0';
                if(j != 0 )cout << " ";
                cout << " ";

                if((i==0 && lcd[num][0]) || (i==2 && lcd[num][3]) || (i==4 && lcd[num][6])){
                    for(int k=0; k<s; k++){
                        cout << "-";
                    }
                }else{
                    for(int k=0; k<s; k++){
                        cout << " ";
                    }
                }
                cout << " ";
            }
            cout << "\n";
        }else{
            for(int k=0; k<s; k++){
                for(int j=0; j<len; j++){
                    int num = number[j] - '0';
                    if(j != 0)cout << " ";

                    if((i==1 && lcd[num][1]) ||(i==3 && lcd[num][4]))cout << "|";
                    else cout << " ";

                    for(int h=0; h<s; h++)cout << " ";

                    if((i==1 && lcd[num][2]) ||(i==3 && lcd[num][5]))cout << "|";
                    else cout << " ";     
                }
                cout << "\n";
            }
        }
    }
    return 0;
}