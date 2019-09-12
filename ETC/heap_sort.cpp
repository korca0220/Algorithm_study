#include <iostream>
#define parent(x) (x-1)/2
using namespace std;

void heapSet(int arr[], int num){
    for(int i=1; i<num; i++){
        int child = i;
        while(child > 0){
            int root = parent(child);
            if(arr[root] < arr[child]) swap(arr[root], arr[child]);
            child = root;
        }
    }
}
void heapSort(int arr[], int num){
    heapSet(arr, num);
    for(int i=num-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapSet(arr, i);
    }
}

int main(){
    int arr[] = {15,4,8,11,6,3,1,6,5};
    heapSort(arr, 9);
    for(int i:arr)cout << i << " ";
    return 0;
}
