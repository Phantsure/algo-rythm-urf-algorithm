#include<bits/stdc++.h>

using namespace std;

const int BOUND = 50000000;

void countingSort(vector<int>& numbers)
{
    int n = numbers.size();
    int maxVal = numbers.back();

    for(int i=1; i < n; ++i)
    {
        maxVal = max(maxVal, numbers[i]);
    }

    assert(maxVal < BOUND);

    vector<int> freq(BOUND, 0);
    for(int i=0; i < n; ++i)
    {
        freq[ numbers[i] ]++;
    }

    int k =0;
    for(int i=0; i < BOUND; ++i)
    {
        while( freq[i] > 0 )
        {
            freq[i]--;
            numbers[ k++ ] = i;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> numbers(n);

    for(int i = 0; i < n; ++i)
    {
        cin >> numbers[i];
    }

    countingSort(numbers);

    cout << "Sorted vector:" << endl;

    for(int i = 0; i < n; ++i)
    {
        cout << numbers[i] << endl;
    }

    return 0;
}
