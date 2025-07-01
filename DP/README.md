# Dynamic Programming (DP)

This folder contains solutions and explanations for various problems solved using Dynamic Programming (DP). DP is a powerful technique used to solve problems by breaking them into smaller overlapping subproblems and solving each subproblem only once, storing the results for future use.

# 1D Dynamic Programming (1D_DP)

This folder contains solutions to problems that can be solved using 1D Dynamic Programming techniques. Each problem is solved using multiple approaches, including recursion, memoization, tabulation, and space optimization.

---

## Contents

### 1. **Climbing Stairs** ([Climbing-Stairs.cpp](Climbing-Stairs.cpp))
- **Problem**: You are climbing a staircase. It takes `n` steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
- **Approaches**:
  1. **Recursive Approach**:
     - Base case: If `n == 0` or `n == 1`, return `1`.
     - Recursive relation: `f(n) = f(n-1) + f(n-2)`.
  2. **Memoization (Top-Down)**:
     - Use an array `dp` to store results of subproblems.
     - Check if `dp[n]` is already computed; if not, compute it using the recursive relation.
  3. **Tabulation (Bottom-Up)**:
     - Use an array `dp` to iteratively compute results from `0` to `n`.
  4. **Space Optimization**:
     - Use two variables to store the last two results instead of an array.

---

### 2. **Frog Jump** ([Frog-Jump.cpp](Frog-Jump.cpp))
- **Problem**: A frog is at the first stone of a river and wants to reach the last stone. The frog can jump either 1 or 2 steps forward. Each stone has a height, and the energy required to jump is the absolute difference in heights. Find the minimum energy required to reach the last stone.
- **Approaches**:
  1. **Recursive Approach**:
     - Base case: If `idx == 0`, return `0`.
     - Recursive relation: `min(left_jump, right_jump)`.
  2. **Memoization (Top-Down)**:
     - Use an array `dp` to store results of subproblems.
     - Check if `dp[idx]` is already computed; if not, compute it using the recursive relation.
  3. **Tabulation (Bottom-Up)**:
     - Use an array `dp` to iteratively compute results from `0` to `n-1`.
  4. **Space Optimization**:
     - Use two variables to store the last two results instead of an array.

---

### 3. **Frog Jump with K Distance** ([Frog-Jump-K.cpp](Frog-Jump-K.cpp))
- **Problem**: Similar to the Frog Jump problem, but the frog can jump up to `k` steps forward. Find the minimum energy required to reach the last stone.
- **Approaches**:
  1. **Recursive Approach**:
     - Base case: If `idx <= 0`, return `0`.
     - Recursive relation: Iterate over all possible jumps from `1` to `k` and find the minimum energy.
  2. **Memoization (Top-Down)**:
     - Use an array `dp` to store results of subproblems.
     - Check if `dp[idx]` is already computed; if not, compute it using the recursive relation.
  3. **Tabulation (Bottom-Up)**:
     - Use an array `dp` to iteratively compute results from `0` to `n-1`.
  4. **Space Optimization**:
     - Use a sliding window of size `k` to optimize space usage.

---

### 4. **House Robber** ([House-Robber.cpp](House-Robber.cpp))
- **Problem**: You are a robber planning to rob houses along a street. Each house has a certain amount of money stashed. Adjacent houses cannot be robbed on the same night. Find the maximum amount of money you can rob without alerting the police.
- **Approaches**:
  1. **Recursive Approach**:
     - Base case: If `idx >= nums.size()`, return `0`.
     - Recursive relation: `max(rob_current, skip_current)`.
  2. **Memoization (Top-Down)**:
     - Use an array `dp` to store results of subproblems.
     - Check if `dp[idx]` is already computed; if not, compute it using the recursive relation.
  3. **Tabulation (Bottom-Up)**:
     - Use an array `dp` to iteratively compute results from `n-1` to `0`.
  4. **Space Optimization**:
     - Use two variables to store the last two results instead of an array.

---

### 5. **Maximum Non-Adjacent Sum** ([Mamimum-Adjacent-sum.cpp](Mamimum-Adjacent-sum.cpp))
- **Problem**: Given an array of integers, find the maximum sum of non-adjacent elements.
- **Approaches**:
  1. **Recursive Approach**:
     - Base case: If `idx >= nums.size()`, return `0`.
     - Recursive relation: `max(include_current, exclude_current)`.
  2. **Memoization (Top-Down)**:
     - Use an array `dp` to store results of subproblems.
     - Check if `dp[idx]` is already computed; if not, compute it using the recursive relation.
  3. **Tabulation (Bottom-Up)**:
     - Use an array `dp` to iteratively compute results from `n-1` to `0`.
  4. **Space Optimization**:
     - Use two variables to store the last two results instead of an array.

---


### Introduction
- **Fibonacci** ([Fibonacci.cpp](Introduction/Fibonacci.cpp))
  - **Converting Recursion to Memoization**:
    1. Declare a DP array of size `n+1` initialized with `-1`.
    2. Check if the value is already present in the DP array using `(dp[n] != -1)`.
    3. If not, compute the value and store it in the DP array before returning.
  - **Converting Memoization to Tabulation**:
    1. Declare a DP array of size `n+1`.
    2. Fill the base cases.
    3. Iterate from `2` to `n` and fill the DP array.
    4. Return the last element of the DP array.
  - **Converting Tabulation to Space Optimization**:
    1. Use two variables (`prev1` and `prev2`) to store the last two Fibonacci numbers.
    2. Iterate from `2` to `n`, computing the current Fibonacci number as the sum of the last two.
    3. Update the variables for the next iteration.
    4. Return the last computed Fibonacci number.

---

### General Notes
- Dynamic Programming involves solving problems by breaking them into smaller overlapping subproblems.
- It is often used in optimization problems where we aim to minimize or maximize a value.

---

## How to Use
1. Open the `.cpp` files in this folder to view the code and comments explaining the logic.
2. Compile and run the files to test the solutions.

---

## Additional Notes
- Dynamic Programming can be applied to a wide range of problems, including:
  - Optimization problems (e.g., finding the shortest path, minimizing cost).
  - Counting problems (e.g., counting the number of ways to achieve a target).
  - Sequence problems (e.g., finding the longest increasing subsequence).
- The key to mastering DP is practice and understanding how to break problems into subproblems.

Feel free to explore the code and comments for a deeper understanding of the concepts!