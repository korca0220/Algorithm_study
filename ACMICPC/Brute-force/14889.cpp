#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int MAX = 20;
int min_score = 987654321;
int n_input;
int synergy[MAX][MAX];
bool selected[MAX] = {false,};

void calculator(){


    int sum_a=0, sum_b=0;
    vector<int> a;
    vector<int> b;

    for(int i=0; i<n_input; i++){
        if(selected[i]) a.push_back(i);
        else b.push_back(i);
    }

    for(int i=0; i<a.size(); i++){
        for(int j=0; j<a.size(); j++){
            if(i != j){
                sum_a += synergy[a[i]][a[j]];
                sum_b += synergy[b[i]][b[j]];
            }
        }
    }

    if (min_score > abs(sum_a-sum_b)) min_score = abs(sum_a-sum_b);

}


void findGoodMin(int to_pick, int index){

    if(to_pick == 0) {
        calculator();    
        return ;
    }
 
    selected[0] = true;    

    for(int start = index; start<n_input; start++){
        if (selected[start] != true){
            selected[start] = true;
            findGoodMin(to_pick-1, start+1);
            selected[start] = false;

        }
    }

}

int main(){

    scanf("%d", &n_input);

    for(int i=0; i<n_input; i++){
        for(int j=0; j<n_input; j++){
            scanf("%d", &synergy[i][j]);
        }
    }
    findGoodMin((n_input/2)-1, 1);
    printf("%d", min_score);

    return 0;
}