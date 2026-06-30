# Creating Strings

## Problem Information

- **Problem:** Creating Strings
- **Category:** Introductory Problems
- **Difficulty:** Easy
- **Language:** C++17

---

## Problem Overview

Given a string containing lowercase English letters, generate **all distinct permutations** of the string.

The permutations must be printed in **lexicographical order**, and the total number of distinct permutations must be printed first.

Since duplicate characters may exist, duplicate permutations must not be generated.

---

## Approach

The solution consists of two independent parts.

### Step 1: Count the number of distinct permutations

If all characters were unique, there would be:

n!

permutations.

When characters repeat, duplicate permutations occur.

The number of unique permutations is

n! / (f₁! × f₂! × ... × fₖ!)

where fᵢ is the frequency of each character.

Since **n ≤ 8**, factorial values are very small and can be computed directly.

---

### Step 2: Generate permutations

1. Sort the string.
2. The sorted string is the smallest lexicographical permutation.
3. Use `next_permutation()` repeatedly.
4. Continue until no further permutation exists.

Because the sequence starts sorted, `next_permutation()` naturally generates every **distinct** permutation exactly once and in lexicographical order.

---

## Algorithm

1. Read the string.
2. Sort the characters.
3. Count the frequency of every character.
4. Compute

   Unique permutations = n! / Π(freq!)

5. Print the count.
6. Print the current permutation.
7. Repeatedly call `next_permutation()` until it returns `false`.

---

## Correctness

- Sorting ensures the first permutation is the lexicographically smallest.
- `next_permutation()` visits every lexicographically larger arrangement exactly once.
- Equal characters never create duplicate outputs.
- The combinatorial formula correctly counts the number of distinct permutations.

Thus the algorithm prints every distinct permutation exactly once in sorted order.

---

## Complexity Analysis

### Time Complexity

- Sorting: **O(n log n)**
- Generating permutations:

  **O(k × n)**

where

- n = string length
- k = number of distinct permutations

Since n ≤ 8, this easily fits within limits.

---

### Space Complexity

**O(1)** (excluding the output)

Only a frequency table and a few variables are used.

---

## STL Used

- `sort()`
- `next_permutation()`
- `unordered_map`

---

## Solution

The complete implementation is available here:

**[Solution.cpp](./Solution.cpp)**
