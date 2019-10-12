#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int brown, int red) {
    vector<int> answer;

    int x=(brown-2)/2;;
    int y=3;
    int red_x = x-2;
    int red_y = y-2;
    while(true){    
        if(red_x * red_y == red){
            break;
        }
        cout << red_x * red_y << " " << x << " " << y << "\n";
        red_x -= 1;
        red_y += 1;
    }
    answer.push_back(red_x+2);
    answer.push_back(red_y+2);
    return answer;
}