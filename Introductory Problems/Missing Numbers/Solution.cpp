#include <iostream>
using namespace std;

class Solution
{
public:
    // Returns the missing number from the range [1, n].
    long long findMissingNumber(long long n)
    {
        // Calculate the expected sum of numbers from 1 to n.
        long long expectedSum = n * (n + 1) / 2;

        // Store the sum of the given numbers.
        long long actualSum = 0;

        // Read each number and update the running sum.
        for (long long i = 0; i < n - 1; i++)
        {
            long long number;
            cin >> number;
            actualSum += number;
        }

        // The difference gives the missing number.
        return expectedSum - actualSum;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    Solution solver;
    cout << solver.findMissingNumber(n);

    return 0;
}
