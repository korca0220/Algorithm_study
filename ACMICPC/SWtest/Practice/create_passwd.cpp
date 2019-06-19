#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int L,C;
vector<char> a;

bool getCheck(string str){

    int mo = 0;
    int ja = 0;
    for(int i=0; i<L; i++){
        if (str[i] == 'a' || str[i] == 'e' || str[i] =='i' || str[i] == 'o' || str[i] =='u'){
            mo++;
        }else ja++;
    }
    if(mo>=1 && ja>=2) return true;

    return false;

}

int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);

    cin >> L >> C;
    for(int i=0; i<C; i++){
        char temp;
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());

    vector<int> p;
    for(int i=0; i<L; i++)p.push_back(1);
    for(int i=0; i<C-L; i++)p.push_back(0);

    do{
        string str = "";
        for(int i=0; i<C; i++){
            if(p[i] != 0)str +=a[i];
        }
        if(getCheck(str))cout << str << "\n";            
    }while(prev_permutation(p.begin(), p.end()));


    return 0;
}