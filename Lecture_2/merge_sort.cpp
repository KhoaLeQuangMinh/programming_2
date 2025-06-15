#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end){
    int right = start;
    int left = mid+1;
    int temp[end-start+1];
    int i = 0;
    while(right <= mid && left <= end){
        if(arr[right] < arr[left]){
            temp[i] = arr[right];
            i++;
            right++;
        }
        else{
            temp[i] = arr[left];
            i++;
            left++;
        }
    }
    while(right <= mid){
        temp[i] =arr[right];
        i++;
        right++;
    }
    while(left <= end){
        temp[i] =arr[left];
        i++;
        left++;
    }
    for(int i = 0, j = start; i < end - start + 1; i++, j++) {
        arr[j] = temp[i];
    }
}

void merge_sort(int arr[], int start, int end){
    int mid = start + (end - start) / 2;
    if(start >= end){
        return;
    }
    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);
    merge(arr, start,mid, end);
    return;
}

int main(){
    int arr[7] = {-3,-5,10,8,5,6,12};
    // for(int i = 0; i < N; i++){
    //     cin>>arr[i];
    // }
    merge_sort(arr, 0, 7-1);
    for(int i = 0; i < 7; i++){
        cout<<arr[i]<<endl;
    }

}