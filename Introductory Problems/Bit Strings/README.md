# Bit Strings

## 📌 Problem Information

- **Problem:** Bit Strings
- **Topic:** Introductory Problems
- **Difficulty:** Easy
- **Language:** C++

---

## 📖 Problem Overview

Given an integer `n`, determine how many different bit strings of length `n` exist.

A bit string contains only the characters:

- `0`
- `1`

Since the answer can become very large, print it modulo:

10^9 + 7

---

## 💡 Key Observation

For every position in the string, there are exactly **2 choices**:

- Place `0`
- Place `1`

Therefore,

Total bit strings =

2 × 2 × 2 × ... × 2 (n times)

= **2ⁿ**

The task simply becomes computing:

2ⁿ mod (10⁹+7)

---

## 🚀 Approach

Instead of calculating `2ⁿ` directly (which quickly overflows), compute the answer while taking modulo at every multiplication.

Initialize:

- answer = 1

Repeat `n` times:

- answer = (answer × 2) % MOD

Finally print the answer.

---

## 📊 Algorithm

1. Read `n`.
2. Initialize `answer = 1`.
3. Repeat `n` times:
   - Multiply answer by `2`.
   - Take modulo `10⁹+7`.
4. Print the final answer.

---

## ⏱ Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(n)** |
| Space | **O(1)** |

---

## ⚠ Edge Cases

- `n = 1`
- Very large `n` (`10⁶`)
- Modulo prevents integer overflow.

---

## 🧠 Key Takeaways

- Every independent binary choice doubles the number of possibilities.
- Compute powers under modulo to avoid overflow.
- Applying modulo after every multiplication keeps numbers within range.

---

## 📚 STL Used

- None

---

## 💻 C++ Implementation

The complete solution is available in:

**[`Solution.cpp`](./Solution.cpp)**
