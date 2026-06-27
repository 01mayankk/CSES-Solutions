# Repetitions

> **Topic:** Introductory Problems
> **Difficulty:** Easy
> **Language:** C++17

---

## Problem Overview

You are given a DNA sequence consisting only of the characters **A**, **C**, **G**, and **T**.

Your task is to determine the length of the longest contiguous substring containing only one type of character.

---

# Approach 1: Using Individual Character Counters

## Intuition

Since the DNA sequence contains only four possible characters, we can maintain a separate counter for each character (`A`, `C`, `G`, and `T`).

Whenever two consecutive characters are identical, increment the corresponding counter while resetting the remaining counters. If the character changes, initialize the counter of the new character to **1**.

Throughout the traversal, maintain the maximum value among all four counters.

---

## Algorithm

1. Initialize four counters:

   * `countA`
   * `countC`
   * `countG`
   * `countT`
2. Initialize `maximumCount = 1`.
3. Set the counter corresponding to the first character.
4. Traverse the string from left to right.
5. If two consecutive characters are the same:

   * Increment the corresponding counter.
   * Reset the remaining three counters.
6. Otherwise:

   * Reset all counters.
   * Initialize the counter of the new character to `1`.
7. Update the maximum repetition after every iteration.

---

## C++ Implementation

```cpp
// This approach is accepted but intentionally omitted.
//
// It maintains four separate counters (A, C, G and T),
// making the implementation longer and less readable.
//
// The repository focuses on the cleaner optimal solution
// available in Solution.cpp.
```

### Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

### Limitation

Although this approach is accepted, it keeps track of four independent counters and contains several conditional branches.

The same problem can be solved using only two variables (`currentCount` and `maximumCount`), resulting in a shorter, cleaner, and easier-to-maintain implementation.

---

# Approach 2: Using a Single Counter (Optimal)

> **💻 Implementation:** [`Solution.cpp`](./Solution.cpp)

## Intuition

Instead of maintaining a separate counter for every possible character, we only need to know:

* the length of the current consecutive repetition, and
* the maximum repetition encountered so far.

If the current character matches the previous one, extend the current repetition by one.

Otherwise, start a new repetition with length **1**.

This approach is simpler, easier to understand, and still processes the string in a single traversal.

---

## Algorithm

1. Initialize:

   * `currentCount = 1`
   * `maximumCount = 1`
2. Traverse the string starting from the second character.
3. If the current character is the same as the previous character:

   * Increment `currentCount`.
4. Otherwise:

   * Reset `currentCount = 1`.
5. Update `maximumCount`.
6. Print `maximumCount`.

---

## Complexity Analysis

* **Time Complexity:** `O(n)`
* **Space Complexity:** `O(1)`

---

## Dry Run

### Input

```
ATTCGGGA
```

### Execution

| Index | Character | Current Count | Maximum Count |
| ----: | :-------: | ------------: | ------------: |
|     0 |     A     |             1 |             1 |
|     1 |     T     |             1 |             1 |
|     2 |     T     |             2 |             2 |
|     3 |     C     |             1 |             2 |
|     4 |     G     |             1 |             2 |
|     5 |     G     |             2 |             2 |
|     6 |     G     |             3 |             3 |
|     7 |     A     |             1 |             3 |

### Output

```
3
```

---

## Correctness

The algorithm always maintains the length of the current consecutive block of identical characters.

Whenever two adjacent characters are equal, the current repetition is extended.

Whenever they differ, the previous repetition ends and a new repetition begins.

Since every consecutive block is processed exactly once and the maximum repetition is updated throughout the traversal, the algorithm always returns the length of the longest repetition.

Hence, the algorithm is correct.

---

## Edge Cases

* String contains only one character.
* All characters in the string are identical.
* No two adjacent characters are the same.
* Longest repetition occurs at the beginning.
* Longest repetition occurs at the end.
* Multiple longest repetitions have the same length.
* Maximum input size (`10^6` characters).

---

## Key Takeaways

* Consecutive character problems are naturally solved using a linear scan.
* Only the current repetition length and the maximum repetition need to be maintained.
* Eliminating unnecessary state often leads to cleaner and more maintainable code.
* The optimal solution achieves linear time with constant extra space.

---
