# Increasing Array

> **Topic:** Introductory Problems
> **Difficulty:** Easy
> **Language:** C++17

---

# Problem Overview

You are given an array of **n** integers. In one operation, you may increase the value of any element by **1**.

Your objective is to transform the array into a **non-decreasing** sequence, where every element is greater than or equal to its previous element, while performing the minimum possible number of operations.

---

# Key Observations

* Only **increment operations** are allowed.
* Decreasing an element is not permitted.
* Every element must be at least equal to its previous element.
* If an element is smaller than its predecessor, increasing it exactly to the previous element is always optimal.
* A single left-to-right traversal is sufficient to solve the problem.

---

# Intuition

While traversing the array from left to right, every element depends only on its immediate predecessor.

Whenever the current element is smaller than the previous one, it violates the required ordering. The minimum correction is to increase it until it becomes equal to the previous element. Any additional increase would only add unnecessary operations.

---

# Approach

Maintain the array in a valid state while traversing it.

For each element:

* If it is already greater than or equal to the previous element, move to the next element.
* Otherwise:

  * Calculate the difference between the previous and current element.
  * Add this difference to the answer.
  * Update the current element to match the previous element.

Since each element is processed exactly once, the algorithm runs efficiently in linear time.

---

# Algorithm

1. Read the input array.
2. Initialize `moves = 0`.
3. Traverse the array from index `1`.
4. If `arr[i] < arr[i-1]`:

   * Add `arr[i-1] - arr[i]` to `moves`.
   * Set `arr[i] = arr[i-1]`.
5. Continue until all elements have been processed.
6. Print `moves`.

---

# Dry Run

### Input

```text
3 2 5 1 7
```

| Step          | Description                              |
| ------------- | ---------------------------------------- |
| Initial Array | `3 2 5 1 7`                              |
| i = 1         | `2 < 3`, increase `2 → 3` (**+1 move**)  |
| Current Array | `3 3 5 1 7`                              |
| i = 2         | `5 ≥ 3`, no operation required           |
| Current Array | `3 3 5 1 7`                              |
| i = 3         | `1 < 5`, increase `1 → 5` (**+4 moves**) |
| Current Array | `3 3 5 5 7`                              |
| i = 4         | `7 ≥ 5`, no operation required           |
| Final Array   | `3 3 5 5 7`                              |
| Total Moves   | **5**                                    |

---

# Edge Cases

| Case                            | Expected Behavior                                                                             |
| ------------------------------- | --------------------------------------------------------------------------------------------- |
| Array contains only one element | Answer is `0`.                                                                                |
| Array is already non-decreasing | No operations are required.                                                                   |
| Array is strictly decreasing    | Every element except the first must be increased.                                             |
| Array contains duplicate values | Duplicates are already valid in a non-decreasing sequence.                                    |
| Large values (`10^9`)           | The algorithm still works efficiently without overflow when using `long long` for the answer. |

---

# Special Cases

* All elements are equal.
* Every element requires modification.
* No element requires modification.
* Multiple consecutive elements need to be increased to the same value.

---

# Correctness Proof

The algorithm processes the array from left to right while maintaining the invariant that every processed prefix is already non-decreasing.

Whenever an element is smaller than its previous element, increasing it exactly to the previous element is the minimum adjustment that satisfies the required condition.

Any smaller increase would still violate the ordering, while any larger increase would only add unnecessary operations.

Since every increment performed is necessary and every element is processed exactly once, the algorithm always computes the minimum number of moves.

---

# Complexity Analysis

| Metric               | Complexity |
| -------------------- | ---------- |
| **Time Complexity**  | **O(n)**   |
| **Space Complexity** | **O(1)**   |

---

# Key Takeaways

* Greedy algorithms often work when each decision affects only future elements.
* Processing the array from left to right naturally maintains the required invariant.
* Sometimes modifying the current element is always better than modifying previously processed elements.
* Always choose the minimum adjustment that satisfies the problem's constraints.

---

# Common Mistakes

* Using `int` instead of `long long` for the answer.
* Forgetting to update the current element after increasing it.
* Using `abs()` instead of directly computing `arr[i-1] - arr[i]`.
* Trying to modify previous elements instead of the current one.

---

# Related Topics

* Greedy Algorithms
* Arrays
* Simulation

---

# Similar Problems

* Missing Number
* Repetitions
* Weird Algorithm
* Array Description
* Array Division

---

# Solution

The complete C++ implementation can be found here.

➡️ **[Solution.cpp](Solution.cpp)**
