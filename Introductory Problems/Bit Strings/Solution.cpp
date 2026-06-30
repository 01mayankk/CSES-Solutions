#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Modulo value specified in the problem statement.
    const long long MOD = 1000000007;

    // Computes (base^power) % MOD using Binary Exponentiation.
    // Time Complexity: O(log power)
    long long binaryExponentiation(long long base, long long power)
    {
        // Stores the final value of (base^power) % MOD.
        long long result = 1;

        // Continue until all bits of the exponent are processed.
        while (power > 0)
        {
            // If the current least significant bit is 1,
            // multiply the current base into the answer.
            if (power & 1)
            {
                result = (result * base) % MOD;
            }

            // Square the base so it represents the next power of two.
            base = (base * base) % MOD;

            // Remove the least significant bit of the exponent
            // and process the next bit.
            power >>= 1;
        }

        return result;
    }

public:
    void countBitStrings()
    {
        long long n;
        cin >> n;

        // Number of bit strings of length n is 2^n.
        // Compute it efficiently using Binary Exponentiation.
        cout << binaryExponentiation(2, n) << '\n';
    }
};

int main()
{
    // Fast input/output.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution solver;
    solver.countBitStrings();

    return 0;
}
