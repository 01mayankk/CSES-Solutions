/*
    Problem: Increasing Array
    Platform: CSES Problem Set
    Topic: Introductory Problems

    Approach:
    Traverse the array from left to right.
    If the current element is smaller than its previous element,
    increase it to match the previous element and count the
    required increments.

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void computeMinimumMoves()
    {
        // Read the size of the array.
        int arraySize;
        cin >> arraySize;

        // Store the input elements.
        vector<long long> numbers(arraySize);

        for (int index = 0; index < arraySize; index++)
        {
            cin >> numbers[index];
        }

        // Stores the minimum number of increment operations.
        long long minimumMoves = 0;

        // Process the array from left to right.
        for (int index = 1; index < arraySize; index++)
        {
            // If the current element violates the non-decreasing property,
            // increase it to match the previous element.
            if (numbers[index] < numbers[index - 1])
            {
                minimumMoves += numbers[index - 1] - numbers[index];
                numbers[index] = numbers[index - 1];
            }
        }

        // Output the minimum number of moves.
        cout << minimumMoves;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution solver;
    solver.computeMinimumMoves();

    return 0;
}
