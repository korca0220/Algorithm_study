#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dwarf[9];
int selected[9];
vector<int> r_dwarf;

void printDwarf(int index, int count){

    if(count==7){
        int sum = 0;
        for(int i=0; i<r_dwarf.size(); i++){
            sum += r_dwarf[i];
        }
        if(sum == 100){
            sort(r_dwarf.begin(), r_dwarf.end());
            for(int i=0; i<r_dwarf.size(); i++)cout << r_dwarf[i]  << "\n";
        }
        return ;
    }
        
    for(int i=index; i<9; i++){
        r_dwarf.push_back(dwarf[i]);
        printDwarf(i+1, count+1);
        r_dwarf.pop_back();
    }

}

int main(){
    
    cin.sync_with_stdio(false);
    cin.tie(NULL);

    for(int i=0; i<9; i++){
        cin >> dwarf[i];
    }
    printDwarf(0, 0);

    return 0;
}