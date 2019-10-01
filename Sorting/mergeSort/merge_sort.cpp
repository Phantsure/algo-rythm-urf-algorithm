#include<bits/stdc++.h>
using namespace std;
void merge(int A[],int l,int mid,int h)
{
    int len1=mid-l+1;
    int len2=h-mid;
    int temp1[len1],temp2[len2];
    for(int i=0;i<len1;i++)
    {
        temp1[i]=A[l+i];
    }
    for(int j=0;j<len2;j++)
    {
        temp2[j]=A[mid+1+j];
    }
    int p = 0; 
    int q = 0; 
    int k = l;
    while (p < len1 && q < len2) 
    { 
        if (temp1[p] <= temp2[p]) 
        { 
            A[k] = temp1[p]; 
            p++; 
        } 
        else
        { 
            A[k] = temp2[q]; 
            q++; 
        } 
        k++; 
    } 
    while (p < len1) 
    { 
        A[k] = temp1[p]; 
        p++; 
        k++; 
    } 
    while (q < len2) 
    { 
        A[k] = temp2[q]; 
        q++; 
        k++; 
    } 
}

void mergeSort(int A[], int low, int high){
    if(low<high){
        int m=low+(high-low)/2;
        mergeSort(A,low,m);
        mergeSort(A,m+1,high);
        merge(A,low,m,high);
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    mergeSort(arr,0,n-1);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;
}