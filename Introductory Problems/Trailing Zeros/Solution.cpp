#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Counts the number of trailing zeros in n!
    void solve(long long n)
    {
        long long count = 0;

        // Every multiple of 5 contributes at least one factor of 5.
        // Multiples of 25 contribute an extra factor of 5,
        // multiples of 125 contribute yet another, and so on.
        while (n >= 5)
        {
            count += n / 5;

            // Move to the next power of 5.
            n /= 5;
        }

        cout << count;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n;

    if (cin >> n)
    {
        Solution solver;
        solver.solve(n);
    }

    return 0;
}
