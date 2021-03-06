/*
Name : Shourya Srivastava 
University Roll NO : 2017377
Section : CE
Problem Statement :  . Given an unsorted array of positive integers, design an algorithm and implement it using a
program to find whether there are any duplicate elements in the array or not. (use sorting) (Time
Complexity = O(n log n))

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void mergeSort(vector<int>&nums, int, int);
void merge(vector<int>&nums, int , int , int);

bool checkDuplicate(vector<int>&nums){
    mergeSort(nums, 0 , nums.size()-1);
    for(int i=1;i<nums.size();i++){
        if(nums[i-1]==nums[i]) return true;
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter the number of testcase : ";
    cin>>n;
    while(n--){
        int size;
        cout<<"Enter the size of array : ";
        cin>>size;
        vector<int> arr(size);
        for(int i=0; i<size; i++) cin>>arr[i];
        
        if(checkDuplicate(arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}

void merge(vector<int>&a,int lb,int mid,int up ){
   int n1 = mid - lb + 1, n2 = up - mid;
   int i = 0, j = 0, k = lb;
   vector<int> left(n1), right(n2);
   for(i=0; i<n1; i++) left[i]= a[i+lb];
   for(i=0; i<n2; i++) right[i]= a[i+mid+1];

   i = 0;
   j = 0;
   while(i<n1 && j<n2){
       if(left[i]<=right[j]) a[k++] = left[i++];
       else a[k++] = right[j++];
            

   }
   while(i<n1) a[k++] = left[i++];
   while(j<n2) a[k++] = right[j++];

   
}

void mergeSort(vector<int>&a,int lb,int up){
    int mid=(lb+up)/2;
    if(lb<up){
        mergeSort(a,lb,mid);
        mergeSort(a,mid+1,up);
        merge(a,lb,mid,up);
    }
}