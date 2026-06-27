/*
    Problem : Repetitions
    Platform: CSES

    Approach:
    Traverse the string once while maintaining the length of the
    current consecutive repetition.

    If the current character matches the previous character,
    extend the current repetition.

    Otherwise, start a new repetition.

    Keep updating the maximum repetition encountered.

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int longestRepetition(const string &dnaSequence)
    {
        // A single character always forms a repetition of length 1.
        int currentCount = 1;
        int maximumCount = 1;

        // Compare every character with its previous character.
        for (size_t index = 1; index < dnaSequence.length(); index++)
        {
            if (dnaSequence[index] == dnaSequence[index - 1])
            {
                // Same character -> extend current repetition.
                currentCount++;
            }
            else
            {
                // Different character -> start a new repetition.
                currentCount = 1;
            }

            // Update the answer if a longer repetition is found.
            maximumCount = max(maximumCount, currentCount);
        }

        return maximumCount;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string dnaSequence;
    cin >> dnaSequence;

    Solution solution;

    cout << solution.longestRepetition(dnaSequence);

    return 0;
}
