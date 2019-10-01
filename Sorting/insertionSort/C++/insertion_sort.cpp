#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int n,int A[])
{
    for(int i=1;i<n;i++)
    {
        int key=A[i];
        int j=i-1;
        while(j>=0&&A[j]>key)
        {
            A[j+1]=A[j];
            j=j-1;
            A[j+1]=key;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    insertion_sort(n,arr);
    cout<<"Sorted array:"<<endl;
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;
}