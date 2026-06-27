# Permutations

> **Topic:** Introductory Problems
> **Difficulty:** Easy
> **Language:** C++17

---

# Problem Overview

A permutation of the integers **1 to n** is considered **beautiful** if the absolute difference between every pair of adjacent elements is **not equal to 1**.

Your task is to construct any such permutation. If no valid permutation exists, print **"NO SOLUTION"**.

---

# Constraints Analysis

| Constraint               | Impact                                                          |
| ------------------------ | --------------------------------------------------------------- |
| `1 ≤ n ≤ 10⁶`            | Requires a linear-time solution.                                |
| Time Limit: **1 sec**    | Brute-force generation of permutations (`O(n!)`) is impossible. |
| Memory Limit: **512 MB** | The solution should use constant extra space whenever possible. |

**Why Greedy Construction?**

Instead of generating and checking every permutation, we can directly construct a valid one by carefully arranging the numbers. Printing all even numbers first, followed by all odd numbers, guarantees that adjacent elements never differ by `1` (except for the special cases `n = 2` and `n = 3`, where no valid permutation exists).

---

# Key Observations

* A brute-force approach is infeasible because there are `n!` possible permutations.
* Consecutive integers differ by exactly `1`, so they should not appear next to each other.
* Placing all **even numbers first**, followed by all **odd numbers**, naturally separates consecutive integers.
* No valid permutation exists for `n = 2` and `n = 3`.
* A single element (`n = 1`) is always a valid permutation.

---

# Intuition

The main challenge is preventing consecutive integers from becoming adjacent.

Notice that all even numbers differ from each other by at least `2`, and the same is true for odd numbers. Therefore, printing every even number first and every odd number afterwards avoids adjacent differences of `1`.

The only exception occurs when the total number of elements is too small (`2` or `3`), making such an arrangement impossible.

---

# Approach

Handle the special cases first:

* If `n = 1`, print `1`.
* If `n = 2` or `n = 3`, print `"NO SOLUTION"`.

Otherwise:

1. Print all even numbers in increasing order.
2. Print all odd numbers in increasing order.

This construction satisfies the required condition for every adjacent pair.

---

# Algorithm

1. Read the value of `n`.
2. If `n == 1`, print `1`.
3. If `n == 2` or `n == 3`, print `"NO SOLUTION"`.
4. Print all even numbers from `2` to `n`.
5. Print all odd numbers from `1` to `n`.
6. Terminate.

---

# Dry Run

### Input

```text
5
```

| Step               | Description                           |
| ------------------ | ------------------------------------- |
| Read `n`           | `5`                                   |
| Print even numbers | `2 4`                                 |
| Print odd numbers  | `1 3 5`                               |
| Final Permutation  | `2 4 1 3 5`                           |
| Verification       | Adjacent differences are `2, 3, 2, 2` |

---

### Input

```text
3
```

| Step         | Description                     |
| ------------ | ------------------------------- |
| Read `n`     | `3`                             |
| Special Case | No beautiful permutation exists |
| Output       | `NO SOLUTION`                   |

---

# Edge Cases

| Case               | Expected Output                       |
| ------------------ | ------------------------------------- |
| `n = 1`            | `1`                                   |
| `n = 2`            | `NO SOLUTION`                         |
| `n = 3`            | `NO SOLUTION`                         |
| `n = 4`            | A valid permutation such as `2 4 1 3` |
| Large value of `n` | Efficiently handled in linear time    |

---

# Special Cases

* The smallest valid permutation consists of a single element.
* No solution exists only for `n = 2` and `n = 3`.
* Multiple valid permutations may exist; any one of them is accepted.

---

# Correctness Proof

For every pair of adjacent even numbers, the difference is at least `2`.

Similarly, every pair of adjacent odd numbers also differs by at least `2`.

The only transition occurs between the last even number and the first odd number. This difference is also never equal to `1` for all valid values of `n ≥ 4`.

Therefore, every adjacent pair satisfies the required condition.

Since the algorithm correctly handles the exceptional cases (`n = 2` and `n = 3`), it always produces a valid beautiful permutation whenever one exists.

---

# Complexity Analysis

| Metric               | Complexity |
| -------------------- | ---------- |
| **Time Complexity**  | **O(n)**   |
| **Space Complexity** | **O(1)**   |

---

# STL Components Used

| STL Component | Purpose                                                       |
| ------------- | ------------------------------------------------------------- |
| None          | The solution only uses basic loops and standard input/output. |

---

# Key Takeaways

* Sometimes a constructive greedy approach is far more efficient than searching all possibilities.
* Recognizing patterns in even and odd numbers can simplify permutation problems.
* Always analyze small input values separately, as they often form special cases.
* Not every permutation problem requires backtracking or recursion.

---

# Common Mistakes

* Attempting to generate all permutations using recursion or `next_permutation()`.
* Forgetting to handle the special cases `n = 2` and `n = 3`.
* Printing odd numbers before even numbers without verifying adjacency.
* Assuming the permutation must be unique.

---

# Related Topics

* Greedy Algorithms
* Constructive Algorithms
* Mathematics
* Permutations

---

# Similar Problems

* Weird Algorithm
* Increasing Array
* Number Spiral
* Apple Division

---

# Solution

The complete C++ implementation is available here:

**➡️ [Solution.cpp](Solution.cpp)**
