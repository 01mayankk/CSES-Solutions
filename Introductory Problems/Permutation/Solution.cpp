/*
    Problem: Permutations
    Platform: CSES Problem Set
    Topic: Introductory Problems

    Approach:
    A beautiful permutation can be constructed by printing all
    even numbers first, followed by all odd numbers.

    This arrangement ensures that the absolute difference between
    any two adjacent numbers is never equal to 1.

    Special Cases:
    - n = 1  -> 1
    - n = 2 or n = 3 -> NO SOLUTION

    Time Complexity : O(n)
    Space Complexity: O(1)
*/

#include <iostream>

using namespace std;

class Solution
{
public:
    void generateBeautifulPermutation()
    {
        long long numberOfElements;
        cin >> numberOfElements;

        // A single element is always a valid permutation.
        if (numberOfElements == 1)
        {
            cout << 1;
            return;
        }

        // No valid permutation exists for n = 2 or n = 3.
        if (numberOfElements == 2 || numberOfElements == 3)
        {
            cout << "NO SOLUTION";
            return;
        }

        // Print all even numbers first.
        for (long long currentNumber = 2; currentNumber <= numberOfElements; currentNumber += 2)
        {
            cout << currentNumber << " ";
        }

        // Print all odd numbers afterwards.
        for (long long currentNumber = 1; currentNumber <= numberOfElements; currentNumber += 2)
        {
            cout << currentNumber << " ";
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution solver;
    solver.generateBeautifulPermutation();

    return 0;
}
