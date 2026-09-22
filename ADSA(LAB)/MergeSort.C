#include<stdio.h>
void merge(int arr[],int low,int mid,int high){
    int i =low;
    int j=mid+1;
    int k=0;
    int temp[100];
    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j]){
            temp[k++]=arr[i];
            i++;
        }
        else{
            temp[k++]=arr[j];
            j++;
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=high){
        temp[k++]=arr[j++];
    }
    for(i=low,k=0;i<=high;k++,i++){
       arr[i]=temp[k];
    }
}
void merge_sort(int arr[],int low,int high){
    int mid;
 if(low<high){
    mid=low+(high-low)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
    
}}

int main(){
    int arr[100],n;
    printf("enter the number of arrays you want to store!");
    scanf("%d",&n);
    printf("enter the %d element:\n",n);
    for (int i=0; i<n;i++){
      scanf("%d",&arr[i]);
    };
   printf("these elements are before merge!\n");
   for(int i=0;i<n;i++){
    printf("%d",arr[i]);
   }
    merge_sort(arr,0,n-1);
   printf("these elements are after merge!\n");
   
  for(int i=0;i<n;i++){
    printf("%d",arr[i]);
   }
}
