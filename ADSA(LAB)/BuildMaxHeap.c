#include<stdio.h>
void swap(int*a,int*b){
  int temp=0;
  temp=*a;
  *a=*b;
  *b=temp;
};
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    };
    if(right<n && arr[right]>arr[largest])
    {
          largest=right;
               };
    if(largest!=i){
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    };
    
};
void BuildMaxHeap(int arr[],int n){
     for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
     };
};
void PrintArray(int arr[],int n){
    
    for(int i=0;i<n;i++){
        printf("%d:\n",arr[i]);
    };
};
int main()
{
    int arr[] = {10, 20, 15, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    PrintArray(arr, n);

    BuildMaxHeap(arr, n);

    printf("Max Heap: ");
    PrintArray(arr, n);

    return 0;
}