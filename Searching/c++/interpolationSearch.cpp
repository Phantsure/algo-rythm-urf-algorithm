#include<bits/stdc++.h> 
using namespace std;
string interpolationSearch(vector<int> a, int l, int r, int num)
{
    r--; 
    while (l <= r && num >= a[l] && num <= a[r])
    {
        // Probing the position with keeping 
        // uniform distribution in mind.
        int pos = l + (((double)(r - l) / (a[r] - a[l])) * (num - a[l]));

        // Condition of target found
        if (a[pos] == num) return("Found");

        // If x is larger, x is in upper part
        if (a[pos] < num) l = pos + 1;

        // If x is smaller, x is in the lower part
        else r = pos - 1;
    }
    return("Not Found");
}

int main()
{
    int n;
    cout << "Enter total number of elements: ";
    cin >> n;
    cout << "Enter Elements";
    int i = n;
    vector<int> a;
    while (i--)
    {
        int t;
        cin >> t;
        a.push_back(t);
    }
    int num;
    cout << "enter number to search";
    cin >> num;
    cout << interpolationSearch(a, 0, n, num);
}