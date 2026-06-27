# Repetitions

## Problem Overview

Given a DNA sequence consisting of the characters **A**, **C**, **G**, and **T**, determine the length of the longest contiguous substring containing only one type of character.

---

## Approach

Traverse the string from left to right while counting the length of the current consecutive sequence of identical characters.

- If the current character matches the previous one, increment the current count.
- Otherwise, reset the count to 1 since a new sequence begins.
- Continuously update the maximum repetition length encountered during the traversal.

Since every character is processed exactly once, this approach is highly efficient.

---

## Algorithm

1. Read the input string.
2. Initialize:
   - `currentCount = 1`
   - `maxCount = 1`
3. Traverse the string starting from the second character.
4. If the current character is the same as the previous character:
   - Increment `currentCount`.
5. Otherwise:
   - Reset `currentCount` to 1.
6. Update `maxCount` after every iteration.
7. Print `maxCount`.

---

## Dry Run

### Input

```
ATTCGGGA
```

### Execution

| Character | Current Count | Maximum Count |
|-----------|--------------:|--------------:|
| A | 1 | 1 |
| T | 1 | 1 |
| T | 2 | 2 |
| C | 1 | 2 |
| G | 1 | 2 |
| G | 2 | 2 |
| G | 3 | 3 |
| A | 1 | 3 |

### Output

```
3
```

---

## Correctness

The algorithm maintains the length of the current consecutive sequence of identical characters.

- Whenever two adjacent characters are equal, the current sequence length increases.
- Whenever they differ, a new sequence starts, and the counter is reset.
- The maximum sequence length found during traversal is stored in `maxCount`.

Since every maximal repetition is examined exactly once, the algorithm always returns the length of the longest repetition.

---

## Complexity Analysis

### Time Complexity

**O(n)**

Each character is visited exactly once.

### Space Complexity

**O(1)**

Only a few integer variables are used regardless of the input size.

---

## Edge Cases

- Single character string.
- All characters are identical.
- No two adjacent characters are the same.
- Longest repetition occurs at the beginning.
- Longest repetition occurs at the end.
- Multiple repetitions of the same maximum length.
- Maximum input size (`n = 10^6`).

---

## STL Used

- `string`
- `algorithm` (`max`)

---

## Key Takeaways

- Consecutive character problems are often solved using a simple linear scan.
- Only the current sequence length and the maximum sequence length need to be tracked.
- The solution runs in linear time with constant extra space.
- This is a classic example of maintaining a running answer while traversing a string.

---

---

## Solution

The complete C++ implementation can be found here:

➡️ **[Solution.cpp](./Solution.cpp)**
