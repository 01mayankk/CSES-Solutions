# Increasing Array

> **Topic:** Introductory Problems
> **Difficulty:** Easy
> **Language:** C++17

---

# Problem Overview

You are given an array of **n** integers. In a single operation, you may increase the value of any element by **1**.

Your objective is to transform the array into a **non-decreasing** sequence, where every element is greater than or equal to its previous element, while performing the **minimum number of operations**.

---

# Constraints Analysis

| Constraint               | Impact                                                              |
| ------------------------ | ------------------------------------------------------------------- |
| `1 ≤ n ≤ 2 × 10⁵`        | Requires an efficient linear-time solution.                         |
| `1 ≤ xᵢ ≤ 10⁹`           | Values are large, but only comparisons and increments are required. |
| Time Limit: **1 sec**    | An **O(n²)** approach would exceed the time limit.                  |
| Memory Limit: **512 MB** | An **O(1)** extra-space solution is preferred.                      |

**Why Greedy?**

Since every element only depends on its immediate predecessor, processing the array once from left to right guarantees the minimum number of required increments.

---

# Key Observations

* Only **increment operations** are allowed.
* Decreasing any element is not permitted.
* Every element must be **greater than or equal to** its previous element.
* If the current element is smaller than its predecessor, increasing it exactly to the previous value is always optimal.
* Every element is processed exactly once.

---

# Intuition

Traverse the array from left to right while maintaining a valid non-decreasing prefix.

Whenever the current element violates the required order, increase it until it becomes equal to the previous element. Since any larger value would only increase the number of operations, matching the previous element is always the optimal choice.

---

# Approach

Maintain the array in a valid state throughout the traversal.

For each element:

* If the current element is already greater than or equal to the previous one, continue.
* Otherwise:

  * Calculate the required increment.
  * Add this value to the answer.
  * Update the current element to match the previous element.

By the time the traversal finishes, the entire array becomes non-decreasing using the minimum possible number of operations.

---

# Algorithm

1. Read the size of the array.
2. Store all elements.
3. Initialize the answer as `0`.
4. Traverse the array from index `1`.
5. If the current element is smaller than the previous element:

   * Add the difference to the answer.
   * Update the current element to the previous element.
6. Continue until all elements are processed.
7. Print the minimum number of moves.

---

# Dry Run

### Input

```text
3 2 5 1 7
```

| Step              | Description                              |
| ----------------- | ---------------------------------------- |
| Initial Array     | `3 2 5 1 7`                              |
| `i = 1`           | `2 < 3`, increase `2 → 3` (**+1 move**)  |
| Current Array     | `3 3 5 1 7`                              |
| `i = 2`           | `5 ≥ 3`, no operation required           |
| Current Array     | `3 3 5 1 7`                              |
| `i = 3`           | `1 < 5`, increase `1 → 5` (**+4 moves**) |
| Current Array     | `3 3 5 5 7`                              |
| `i = 4`           | `7 ≥ 5`, no operation required           |
| Final Array       | `3 3 5 5 7`                              |
| **Minimum Moves** | **5**                                    |

---

# Edge Cases

| Case                         | Expected Output                                       |
| ---------------------------- | ----------------------------------------------------- |
| Single element               | `0`                                                   |
| Already non-decreasing array | `0`                                                   |
| Strictly decreasing array    | Every element except the first requires modification. |
| Duplicate values             | Already satisfy the condition.                        |
| Large element values (`10⁹`) | Handled safely using `long long` for the answer.      |

---

# Special Cases

* All elements are identical.
* Every element requires an increment.
* No increment is required.
* Multiple consecutive elements need to be updated to the same value.

---

# Correctness Proof

The algorithm maintains the invariant that the processed portion of the array is always non-decreasing.

Whenever an element is smaller than its predecessor, increasing it exactly to the previous element is the smallest possible modification that satisfies the required condition.

Choosing any smaller value would still violate the constraint, while choosing any larger value would introduce unnecessary operations.

Since every required increment is counted exactly once and every element is processed only once, the algorithm always computes the minimum possible number of moves.

---

# Complexity Analysis

| Metric               | Complexity |
| -------------------- | ---------- |
| **Time Complexity**  | **O(n)**   |
| **Space Complexity** | **O(1)**   |

---

# STL Components Used

| STL Component       | Purpose                             |
| ------------------- | ----------------------------------- |
| `vector<long long>` | Stores the input array dynamically. |

---

# Key Takeaways

* Greedy algorithms are effective when local optimal decisions lead to a globally optimal solution.
* Processing the array from left to right naturally preserves the required ordering.
* Sometimes modifying the current element is always better than modifying previously processed elements.
* Choosing the minimum valid adjustment minimizes the total number of operations.

---

# Common Mistakes

* Using `int` instead of `long long` to store the total number of moves.
* Forgetting to update the current element after increasing it.
* Using `abs()` unnecessarily when the difference is already known to be positive.
* Attempting to modify previously processed elements.

---

# Related Topics

* Greedy Algorithms
* Arrays
* Simulation

---

# Similar Problems

* Missing Number
* Repetitions
* Array Description
* Array Division

---

# Solution

The complete C++ implementation is available here:

**➡️ [Solution.cpp](Solution.cpp)**
