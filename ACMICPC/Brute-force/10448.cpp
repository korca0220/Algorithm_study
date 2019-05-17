#include <iostream>
#include <vector>
using namespace std;

const int MAX = 50;
vector<int> triple_sum;
int t_input;
int result;
int k_number;

void findSum(int index, int count, int find_number){

    
    if (result == 1) return ;
    if(index ==3) {                
        if(count == find_number){            
            result = 1;
            return ; 
        }
        return ;
    }
    if (count > find_number) return ;
    else{
        for(int i=0; i<triple_sum.size(); i++){     
            findSum(index+1, count+triple_sum[i], find_number);            
        }
    }    
}


int main(){

    cin.sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    for(int i=1; i<MAX; i++){
        if (((i * (i+1)) / 2) > 1000 ) break;
        triple_sum.push_back((i * (i+1)) / 2);
    }

    cin >> t_input;
    

    while(t_input--){
        cin >> k_number;
        result = 0;        

        findSum(0, 0, k_number);

        cout << result << "\n";

    }



    return 0;
}