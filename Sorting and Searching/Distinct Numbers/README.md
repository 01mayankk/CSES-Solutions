# Distinct Numbers

| Category | Details |
|----------|----------|
| **Problem** | Distinct Numbers |
| **Topic** | Sorting, Searching |
| **Difficulty** | Easy |
| **Language** | C++ |

---

## Problem Overview

Given a list of `n` integers, determine how many **distinct** values are present in the list.

---

## Approach

The simplest way to count distinct values is:

1. Store all numbers in a vector.
2. Sort the vector.
3. Traverse the sorted vector.
4. Count every element that differs from its previous element.

Since duplicate values become adjacent after sorting, each new value indicates a distinct number.

---

## Algorithm

1. Read `n`.
2. Store all numbers in a vector.
3. Sort the vector.
4. Initialize the answer as `1` (if the array is not empty).
5. Traverse from index `1`.
6. Whenever `v[i] != v[i-1]`, increment the answer.
7. Print the answer.

---

## Dry Run

### Input

```
5
2 3 2 2 3
```

### After Sorting

```
2 2 2 3 3
```

Traversal:

| Index | Value | Previous | Distinct Count |
|------|------|---------|---------------|
|0|2|-|1|
|1|2|2|1|
|2|2|2|1|
|3|3|2|2|
|4|3|3|2|

Output

```
2
```

---

## Correctness

Sorting places equal values together.

Every time the current element differs from the previous one, we have encountered a new distinct value.

Thus, every unique number is counted exactly once.

---

## Complexity Analysis

### Time Complexity

- Sorting: **O(n log n)**
- Traversal: **O(n)**

Overall:

> **O(n log n)**

### Space Complexity

- Vector storage:

> **O(n)**

---

## Edge Cases Considered

- Only one element.
- All elements are identical.
- All elements are unique.
- Very large values (`10^9`).
- Maximum input size (`2 × 10^5`).

---

## STL Used

- `vector`
- `sort`

---

## Key Takeaways

- Sorting is an easy way to group duplicates.
- Adjacent comparison efficiently counts unique values.
- A single linear scan after sorting solves the problem.
