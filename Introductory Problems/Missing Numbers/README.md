# Missing Number

> **Topic:** Introductory Problems
> **Difficulty:** Easy
> **Language:** C++17

---

## Problem Overview

You are given all integers from **1** to **n**, except one. Your task is to determine the missing number.

---

# Approach 1: Using an Auxiliary Array

## Intuition

A simple way to solve the problem is to record which numbers appear in the input.

Create a boolean array (or vector) of size **n + 1**, where each index represents a number from **1** to **n**. As each number is read, mark it as present. After processing all numbers, the only index that remains unmarked is the missing number.

---

## Algorithm

1. Create a boolean vector of size **n + 1** initialized with `false`.
2. Read each of the **n - 1** numbers.
3. Mark every encountered number as present.
4. Traverse the vector from **1** to **n**.
5. Print the first unmarked index.

---

## C++ Implementation

```cpp
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void findMissingNumber(long long n)
    {
        // Stores whether each number is present.
        vector<bool> present(n + 1, false);

        // Mark every number that appears.
        for (long long i = 0; i < n - 1; i++)
        {
            long long number;
            cin >> number;
            present[number] = true;
        }

        // The first unmarked number is missing.
        for (long long i = 1; i <= n; i++)
        {
            if (!present[i])
            {
                cout << i;
                return;
            }
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
    solver.findMissingNumber(n);

    return 0;
}
```

### Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(n)`

### Limitation

Although this approach is accepted within the given constraints, it requires an additional array of size **n + 1** to keep track of the numbers that appear.

Since the problem only asks for one missing value, this extra memory can be avoided.

---

# Approach 2: Using the Sum Formula (Optimal)

> **Implementation:** See **`Solution.cpp`**

## Intuition

The sum of the first **n** natural numbers is known beforehand.

```
Sum = n × (n + 1) / 2
```

If we subtract the sum of the given **n − 1** numbers from this expected sum, the remaining value is the missing number.

This approach avoids storing the input and uses only constant extra memory.

---

## Algorithm

1. Compute the expected sum of numbers from **1** to **n**.
2. Read each number and maintain a running sum.
3. Subtract the actual sum from the expected sum.
4. Print the result.

---

## Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## Dry Run

### Input

```
5
2 3 1 5
```

### Expected Sum

```
1 + 2 + 3 + 4 + 5 = 15
```

### Actual Sum

```
2 + 3 + 1 + 5 = 11
```

### Missing Number

```
15 - 11 = 4
```

### Output

```
4
```

---

## Correctness

The expected sum contains every integer from **1** to **n** exactly once.

The input contains every number except one.

Subtracting the sum of the given numbers from the expected sum removes all common values, leaving only the missing number.

Hence, the algorithm always returns the correct answer.

---

## Edge Cases

* Missing number is **1**
* Missing number is **n**
* Minimum input (`n = 2`)
* Maximum input (`n = 2 × 10⁵`)

---

## Key Takeaways

* Mathematical Optimization
* Arithmetic Series Formula
* Space Optimization
* Single-Pass Traversal
* Constant Extra Space
