#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		ll n,max=0;
		cin>>n;
		ll arr[n];
		for(ll i=0;i<n;i++)
			cin>>arr[i];
		if(n==1){
			cout<<arr[0]<<endl;
		}
		else{
			for(ll i=0;i<n-1;i++){
				for(ll j=i+1;j<n;j++){
					int h=arr[i]^arr[j];
					cout<<h<<endl;
					if(max<h){
						max=h;
					}
				}
			}
		cout<<max<<endl;
		}
	}
}