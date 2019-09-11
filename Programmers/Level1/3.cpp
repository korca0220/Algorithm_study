#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer; 
    vector<int> temp;
    for(int i=0; i<commands.size(); i++){
        temp.clear();
        int x,y,z;
        x = commands[i][0]; y = commands[i][1]; z = commands[i][2]-1;
        temp.assign(array.begin()+x, array.begin()+y); 
        sort(temp.begin(), temp.end());
        answer.push_back(temp[z]);
    }
    return answer;
}