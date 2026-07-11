#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Counts the number of distinct values in the given list.
    void countDistinctNumbers(int numberOfElements)
    {
        // Store all input numbers.
        vector<int> numbers(numberOfElements);

        for (int index = 0; index < numberOfElements; index++)
        {
            cin >> numbers[index];
        }

        // Sort the numbers so that duplicate values become adjacent.
        sort(numbers.begin(), numbers.end());

        // The first element is always distinct.
        int distinctCount = 1;

        // Count every value that differs from its previous value.
        for (int index = 1; index < numberOfElements; index++)
        {
            if (numbers[index] != numbers[index - 1])
            {
                distinctCount++;
            }
        }

        cout << distinctCount;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numberOfElements;
    cin >> numberOfElements;

    Solution solver;
    solver.countDistinctNumbers(numberOfElements);

    return 0;
}
