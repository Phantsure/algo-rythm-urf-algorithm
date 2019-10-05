#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cout<<"Enter Number of Entries: ";
	cin>>n;
	int a[n];
	cout<<"Enter entries: ";
	for(int i=0; i<n; i++)
		cin>>a[i];
	cout<<"Enter number to search: ";
	int search;
	cin>>search;
	for(int i=0;i<n;i++)
	{
		if(a[i]==search)
		{
			cout<<"Found at position "<<i+1<<endl;
			return 0;
		}
	}
	cout<<"Not Found"<<endl;
	return 0;
}