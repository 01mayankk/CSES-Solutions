#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(int numberOfElements)
    {
        // Calculate the sum of numbers from 1 to n.
        long long totalSum = (1LL * numberOfElements * (numberOfElements + 1)) / 2;

        // If the total sum is odd, it cannot be divided into two equal subsets.
        if (totalSum % 2 != 0)
        {
            cout << "NO\n";
            return;
        }

        cout << "YES\n";

        long long targetSum = totalSum / 2;

        // Stores the two required subsets.
        vector<int> firstSet;
        vector<int> secondSet;

        // Greedily pick the largest possible number that does not
        // exceed the remaining target sum.
        for (int currentNumber = numberOfElements; currentNumber >= 1; currentNumber--)
        {
            if (currentNumber <= targetSum)
            {
                firstSet.push_back(currentNumber);
                targetSum -= currentNumber;
            }
            else
            {
                secondSet.push_back(currentNumber);
            }
        }

        // Print the first subset.
        cout << firstSet.size() << "\n";
        for (int element : firstSet)
        {
            cout << element << " ";
        }
        cout << "\n";

        // Print the second subset.
        cout << secondSet.size() << "\n";
        for (int element : secondSet)
        {
            cout << element << " ";
        }
        cout << "\n";
    }
};

int main()
{
    // Speed up input and output operations.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfElements;
    cin >> numberOfElements;

    Solution solution;
    solution.solve(numberOfElements);

    return 0;
}
