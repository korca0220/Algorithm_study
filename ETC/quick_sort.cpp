#include <iostream>
using namespace std;

int partition(int arr[], int start, int end){

    int p = arr[(start+end) / 2];
    while(start <= end){
        while(arr[start] < p)start++;
        while(arr[end] > p)end--;
        if(start <= end){
            swap(arr[start], arr[end]);
            start++; end--;
        }
    } 
    return start;
}
void quickSort(int arr[], int start, int end){

    int part = partition(arr, start, end);
    if(start < part -1){
        quickSort(arr, start, part-1);
    }
    if(part < end){
        quickSort(arr, part, end);
    }
}

void bubbleSort(int arr[], int size){

    int len = size;
    for(int i=0; i<len-1; i++){
        for(int j=0; j<len-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
}
int main(){

    int arr[8] = {5,7,1,2,3,4,5,8};
    // quickSort(arr, 0, 7);
    bubbleSort(arr, 8);
    for(int i : arr){
        cout << i << " ";
    }

    return 0;
}