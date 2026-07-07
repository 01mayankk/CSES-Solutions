# Trailing Zeros

## 📌 Problem Information

- **Problem:** Trailing Zeros
- **Topic:** Introductory Problems
- **Difficulty:** Easy
- **Language:** C++

---

## 📖 Problem Overview

Given an integer `n`, determine how many trailing zeros are present in `n!` (factorial of `n`).

A trailing zero is formed by a factor of **10**, and every **10 = 2 × 5**.

Since factorials always contain far more factors of **2** than **5**, the answer depends entirely on the number of factors of **5**.

---

## 💡 Approach

Instead of computing the factorial (which is impossible for large values of `n`), count how many multiples of:

- 5 contribute one factor of 5.
- 25 contribute one extra factor.
- 125 contribute another extra factor.
- and so on.

Therefore,

Trailing Zeros =

n/5 + n/25 + n/125 + ...

until the divisor becomes larger than `n`.

---

## 🧠 Algorithm

1. Initialize the answer as `0`.
2. While `n >= 5`:
   - Add `n / 5` to the answer.
   - Update `n = n / 5`.
3. Print the final answer.

---

## ⏱️ Complexity Analysis

| Complexity | Value |
|------------|-------|
| Time | **O(log₅ n)** |
| Space | **O(1)** |

---

## ⚠️ Edge Cases Considered

- Smallest value (`n = 1`)
- Values less than `5`
- Multiples of `25`
- Multiples of `125`
- Very large values (`n = 10^9`)

---

## 🔍 Key Observation

Every trailing zero requires one pair of `(2,5)`.

Since factorials contain significantly more factors of `2` than `5`, we only need to count the total number of factors of `5`.

---

## 🛠️ STL Used

- `iostream`

(No STL containers or algorithms are required.)

---

## 💻 C++ Implementation

The complete implementation is available here:

**➡️ [Solution.cpp](Solution.cpp)**
