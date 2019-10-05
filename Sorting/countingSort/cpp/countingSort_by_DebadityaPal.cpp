#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cout<<"Enter Number of elements: "<<endl;
	cin>>n;
	int a[n];
	cout<<"Enter elements: "<<endl;
	for(int i=0;i <n; i++)
		cin>>a[i];
	int mx = a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>mx)	mx = a[i];
	}
	
	int count[mx+1] = {0};
	for(int i=0;i<n;i++)
		count[a[i]]++;
	for(int i=0;i<=mx;i++)
	{
		while(count[i]!=0)
		{
			cout<<i<<" ";
			count[i]--;
		}
	}
	return 0;
}
