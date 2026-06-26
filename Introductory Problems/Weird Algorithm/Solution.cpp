#include <iostream>
using namespace std;

class Solution
{
public:
    // Prints the Collatz sequence starting from n.
    void generateSequence(long long n)
    {
        // Print the current value.
        cout << n << " ";

        // Base case: stop when n becomes 1.
        if (n == 1)
        {
            return;
        }

        // If n is even, divide it by 2.
        if (n % 2 == 0)
        {
            generateSequence(n / 2);
        }
        // Otherwise, multiply by 3 and add 1.
        else
        {
            generateSequence(3 * n + 1);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    Solution solver;
    solver.generateSequence(n);

    return 0;
}
