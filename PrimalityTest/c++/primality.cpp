#include <iostream>
using namespace std;

bool isPrime(int n) 
{ 
    // Corner case 
    if (n <= 1)  return false; 
  
    // Check from 2 to n-1 
    for (int i=2; i<n; i++) 
        if (n%i == 0) 
            return false; 
  
    return true; 
}
 //Time complexity of this solution is O(n)
 
 bool isPrime(int n) 
{ 
    // Corner cases 
    if (n <= 1)  return false; 
    if (n <= 3)  return true; 
  
    // This is checked so that we can skip  
    // middle five numbers in below loop 
    if (n%2 == 0 || n%3 == 0) return false; 
  
    for (int i=5; i*i<=n; i=i+6) 
        if (n%i == 0 || n%(i+2) == 0) 
           return false; 
  
    return true; 
} 
//Time complexity of this solution is O(underroot n)

int main(void){
	// to check whether n is prime or not 
	int n ; 
	//taking input from the user 
	cin>>n; 
	
	isPrime(n) ? cout<<"The number is prime ":cout<<"Number is not prime ";		
	
	return 0;

}
