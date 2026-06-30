#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    // Computes the factorial of a given number.
    long long factorial(int number)
    {
        long long result = 1;

        for (int i = 2; i <= number; i++)
        {
            result *= i;
        }

        return result;
    }

public:
    // Generates and prints all distinct permutations
    // of the given string in lexicographical order.
    void generateStrings(string &str)
    {
        // Sorting ensures that the first permutation is the
        // lexicographically smallest.
        sort(str.begin(), str.end());

        int n = str.size();

        // A fixed-size frequency array is more efficient than an unordered_map
        // because the input contains only lowercase English letters ('a' to 'z').
        vector<int> frequency(26, 0);

        // Count the frequency of each character.
        for (char ch : str)
        {
            frequency[ch - 'a']++;
        }

        // Total permutations assuming all characters are distinct.
        long long totalPermutations = factorial(n);

        // Divide by factorial of repeated character frequencies
        // to obtain the number of distinct permutations.
        for (int count : frequency)
        {
            if (count > 1)
            {
                totalPermutations /= factorial(count);
            }
        }

        // Print the total number of distinct permutations.
        cout << totalPermutations << '\n';

        // Generate every distinct permutation in lexicographical order.
        do
        {
            cout << str << '\n';
        } while (next_permutation(str.begin(), str.end()));
    }
};

int main()
{
    // Fast input/output.
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;

    Solution solver;
    solver.generateStrings(str);

    return 0;
}
