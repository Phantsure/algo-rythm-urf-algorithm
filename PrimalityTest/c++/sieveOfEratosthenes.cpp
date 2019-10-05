#include <bits/stdc++.h>
using namespace std;

void sieveOfEratosthenes(int n, vector<int>& primes)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i < n; ++i)
    {
        if(isPrime[i])
        {
            primes.push_back(i);
            for(int j = i + i; j <= n; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main(void)
{
	int n; 
	cin >> n; 
	
    vector<int> primes;
    sieveOfEratosthenes(n, primes);

    cout << "List of prime numbers up to n:" << endl;
    for(int i=0; i < primes.size(); ++i)
    {
        cout << primes[i] << endl;
    }
	
	return 0;

}
