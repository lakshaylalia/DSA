# Dynamic Programming (DP)

This folder contains solutions and explanations for various problems solved using Dynamic Programming (DP). DP is a powerful technique used to solve problems by breaking them into smaller overlapping subproblems and solving each subproblem only once, storing the results for future use.

---

## Contents

### 1D Dynamic Programming (1D_DP)
#### 1. **Climbing Stairs** ([Climbing-Stairs.cpp](1D_DP/Climbing-Stairs.cpp))
- **Problem**: You are climbing a staircase. It takes `n` steps to reach the top. Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

- **Approaches**:
  1. **Recursive Approach**:
     **Pseudocode**:
     ```
     function climbStairs(n):
         if n == 0 or n == 1:
             return 1
         return climbStairs(n-1) + climbStairs(n-2)
     ```

  2. **Memoization (Top-Down)**:
     **Pseudocode**:
     ```
     function climbStairs(n, dp):
         if n == 0 or n == 1:
             return 1
         if dp[n] != -1:
             return dp[n]
         dp[n] = climbStairs(n-1, dp) + climbStairs(n-2, dp)
         return dp[n]
     ```

  3. **Tabulation (Bottom-Up)**:
     **Pseudocode**:
     ```
     function climbStairs(n):
         dp = array of size (n+1)
         dp[0] = 1
         dp[1] = 1
         for i from 2 to n:
             dp[i] = dp[i-1] + dp[i-2]
         return dp[n]
     ```

  4. **Space Optimization**:
     **Pseudocode**:
     ```
     function climbStairs(n):
         prev2 = 1
         prev1 = 1
         for i from 2 to n:
             current = prev1 + prev2
             prev2 = prev1
             prev1 = current
         return prev1
     ```

---

#### 2. **Frog Jump** ([Frog-Jump.cpp](1D_DP/Frog-Jump.cpp))
- **Problem**: A frog is at the first stone of a river and wants to reach the last stone. The frog can jump either 1 or 2 steps forward. Each stone has a height, and the energy required to jump is the absolute difference in heights. Find the minimum energy required to reach the last stone.

- **Approaches**:
  1. **Recursive Approach**:
     **Pseudocode**:
     ```
     function frogJump(idx, heights):
         if idx == 0:
             return 0
         left = frogJump(idx-1, heights) + abs(heights[idx] - heights[idx-1])
         right = INT_MAX
         if idx > 1:
             right = frogJump(idx-2, heights) + abs(heights[idx] - heights[idx-2])
         return min(left, right)
     ```

  2. **Memoization (Top-Down)**:
     **Pseudocode**:
     ```
     function frogJump(idx, heights, dp):
         if idx == 0:
             return 0
         if dp[idx] != -1:
             return dp[idx]
         left = frogJump(idx-1, heights, dp) + abs(heights[idx] - heights[idx-1])
         right = INT_MAX
         if idx > 1:
             right = frogJump(idx-2, heights, dp) + abs(heights[idx] - heights[idx-2])
         dp[idx] = min(left, right)
         return dp[idx]
     ```

  3. **Tabulation (Bottom-Up)**:
     **Pseudocode**:
     ```
     function frogJump(n, heights):
         dp = array of size n
         dp[0] = 0
         for i from 1 to n-1:
             left = dp[i-1] + abs(heights[i] - heights[i-1])
             right = INT_MAX
             if i > 1:
                 right = dp[i-2] + abs(heights[i] - heights[i-2])
             dp[i] = min(left, right)
         return dp[n-1]
     ```

  4. **Space Optimization**:
     **Pseudocode**:
     ```
     function frogJump(n, heights):
         prev2 = 0
         prev1 = 0
         for i from 1 to n-1:
             left = prev1 + abs(heights[i] - heights[i-1])
             right = INT_MAX
             if i > 1:
                 right = prev2 + abs(heights[i] - heights[i-2])
             current = min(left, right)
             prev2 = prev1
             prev1 = current
         return prev1
     ```

---

### 2D Dynamic Programming (2D_DP)
#### 1. **Ninja Training** ([Ninja-Training.cpp](2D_DP/Ninja-Training.cpp))
- **Problem**: A ninja has to train in three activities daily, but cannot perform the same activity on consecutive days. Find the maximum points the ninja can earn in `n` days.

- **Approaches**:
  1. **Recursive Approach**:
     **Pseudocode**:
     ```
     function ninjaTraining(day, last, points):
         if day == 0:
             return max(points[0][activity] for activity != last)
         maxPoints = 0
         for activity in range(3):
             if activity != last:
                 maxPoints = max(maxPoints, points[day][activity] + ninjaTraining(day-1, activity, points))
         return maxPoints
     ```

  2. **Memoization (Top-Down)**:
     **Pseudocode**:
     ```
     function ninjaTraining(day, last, points, dp):
         if day == 0:
             return max(points[0][activity] for activity != last)
         if dp[day][last] != -1:
             return dp[day][last]
         maxPoints = 0
         for activity in range(3):
             if activity != last:
                 maxPoints = max(maxPoints, points[day][activity] + ninjaTraining(day-1, activity, points, dp))
         dp[day][last] = maxPoints
         return dp[day][last]
     ```

  3. **Tabulation (Bottom-Up)**:
     **Pseudocode**:
     ```
     function ninjaTraining(n, points):
         dp = array of size (n x 3)
         dp[0][activity] = points[0][activity]
         for day in range(1, n):
             for activity in range(3):
                 dp[day][activity] = max(points[day][activity] + dp[day-1][prev] for prev != activity)
         return max(dp[n-1])
     ```

  4. **Space Optimization**:
     **Pseudocode**:
     ```
     function ninjaTraining(n, points):
         prev = array of size 3
         prev[activity] = points[0][activity]
         for day in range(1, n):
             curr = array of size 3
             for activity in range(3):
                 curr[activity] = max(points[day][activity] + prev[prevActivity] for prevActivity != activity)
             prev = curr
         return max(prev)
     ```

---

# Dynamic Programming (DP)

This folder contains solutions and explanations for various problems solved using Dynamic Programming (DP). DP is a powerful technique used to solve problems by breaking them into smaller overlapping subproblems and solving each subproblem only once, storing the results for future use.

---

## Contents

### 3D Dynamic Programming (3D_DP)
#### 1. **Cherry Pickup** ([Cherry-Pickup.cpp](3D_DP/Cherry-Pickup.cpp))
- **Problem**: Two robots start at the top-left and top-right corners of a grid. They move downwards and can collect cherries. Find the maximum cherries they can collect together.

- **Approaches**:
  1. **Recursive Approach**:
     **Pseudocode**:
     ```
     function cherryPickup(row, col1, col2, grid):
         if col1 < 0 or col1 >= m or col2 < 0 or col2 >= m:
             return -INF
         if row == n-1:
             return grid[row][col1] + (grid[row][col2] if col1 != col2 else 0)
         maxCherries = 0
         for d1 in [-1, 0, 1]:
             for d2 in [-1, 0, 1]:
                 maxCherries = max(maxCherries, cherryPickup(row+1, col1+d1, col2+d2, grid))
         return grid[row][col1] + (grid[row][col2] if col1 != col2 else 0) + maxCherries
     ```

  2. **Memoization (Top-Down)**:
     **Pseudocode**:
     ```
     function cherryPickup(row, col1, col2, grid, dp):
         if col1 < 0 or col1 >= m or col2 < 0 or col2 >= m:
             return -INF
         if row == n-1:
             return grid[row][col1] + (grid[row][col2] if col1 != col2 else 0)
         if dp[row][col1][col2] != -1:
             return dp[row][col1][col2]
         maxCherries = 0
         for d1 in [-1, 0, 1]:
             for d2 in [-1, 0, 1]:
                 maxCherries = max(maxCherries, cherryPickup(row+1, col1+d1, col2+d2, grid, dp))
         dp[row][col1][col2] = grid[row][col1] + (grid[row][col2] if col1 != col2 else 0) + maxCherries
         return dp[row][col1][col2]
     ```

  3. **Tabulation (Bottom-Up)**:
     **Pseudocode**:
     ```
     function cherryPickup(grid):
         dp = 3D array of size (n x m x m) initialized to -INF
         for row in range(n-1, -1, -1):
             for col1 in range(m):
                 for col2 in range(m):
                     maxCherries = 0
                     for d1 in [-1, 0, 1]:
                         for d2 in [-1, 0, 1]:
                             maxCherries = max(maxCherries, dp[row+1][col1+d1][col2+d2] if valid else 0)
                     dp[row][col1][col2] = grid[row][col1] + (grid[row][col2] if col1 != col2 else 0) + maxCherries
         return dp[0][0][m-1]
     ```

---

### DP on Grids (DP_GRIDS)
#### 1. **Unique Paths** ([Unique-Paths.cpp](DP_GRIDS/Unique-Paths.cpp))
- **Problem**: Find the number of unique paths in a grid from the top-left to the bottom-right corner. Obstacles may be present in the grid.

- **Approaches**:
  1. **Recursive Approach**:
     **Pseudocode**:
     ```
     function uniquePaths(row, col, grid):
         if row < 0 or col < 0 or grid[row][col] == 1:
             return 0
         if row == 0 and col == 0:
             return 1
         return uniquePaths(row-1, col, grid) + uniquePaths(row, col-1, grid)
     ```

  2. **Memoization (Top-Down)**:
     **Pseudocode**:
     ```
     function uniquePaths(row, col, grid, dp):
         if row < 0 or col < 0 or grid[row][col] == 1:
             return 0
         if row == 0 and col == 0:
             return 1
         if dp[row][col] != -1:
             return dp[row][col]
         dp[row][col] = uniquePaths(row-1, col, grid, dp) + uniquePaths(row, col-1, grid, dp)
         return dp[row][col]
     ```

  3. **Tabulation (Bottom-Up)**:
     **Pseudocode**:
     ```
     function uniquePaths(grid):
         dp = 2D array of size (n x m)
         dp[0][0] = 1
         for row in range(n):
             for col in range(m):
                 if grid[row][col] == 1:
                     dp[row][col] = 0
                 else:
                     dp[row][col] += dp[row-1][col] if row > 0 else 0
                     dp[row][col] += dp[row][col-1] if col > 0 else 0
         return dp[n-1][m-1]
     ```

---

### DP on Stocks (DP_STOCKS)
#### 1. **Buy and Sell Stocks I** ([BuySellStocks1.cpp](DP_STOCKS/BuySellStocks1.cpp))
- **Problem**: You can buy and sell a stock once. Find the maximum profit you can achieve.

- **Approaches**:
  1. **Recursive Approach**:
     **Pseudocode**:
     ```
     function maxProfit(idx, minPrice, prices):
         if idx == len(prices):
             return 0
         profit = prices[idx] - minPrice
         return max(profit, maxProfit(idx+1, min(minPrice, prices[idx]), prices))
     ```

  2. **Tabulation (Bottom-Up)**:
     **Pseudocode**:
     ```
     function maxProfit(prices):
         minPrice = INF
         maxProfit = 0
         for price in prices:
             minPrice = min(minPrice, price)
             maxProfit = max(maxProfit, price - minPrice)
         return maxProfit
     ```

---

#### 2. **Buy and Sell Stocks II** ([BuySellStocks2.cpp](DP_STOCKS/BuySellStocks2.cpp))
- **Problem**: You can buy and sell a stock multiple times. Find the maximum profit you can achieve.

- **Approaches**:
  1. **Recursive Approach**:
     **Pseudocode**:
     ```
     function maxProfit(idx, prices):
         if idx == len(prices)-1:
             return 0
         profit = max(0, prices[idx+1] - prices[idx])
         return profit + maxProfit(idx+1, prices)
     ```

  2. **Tabulation (Bottom-Up)**:
     **Pseudocode**:
     ```
     function maxProfit(prices):
         maxProfit = 0
         for i in range(1, len(prices)):
             if prices[i] > prices[i-1]:
                 maxProfit += prices[i] - prices[i-1]
         return maxProfit
     ```

---

#### 3. **Buy and Sell Stocks III** ([BuySellStocks3.cpp](DP_STOCKS/BuySellStocks3.cpp))
- **Problem**: You can buy and sell a stock at most twice. Find the maximum profit you can achieve.

- **Approaches**:
  1. **Recursive Approach**:
     **Pseudocode**:
     ```
     function maxProfit(idx, transactionsLeft, prices):
         if idx == len(prices) or transactionsLeft == 0:
             return 0
         profit = 0
         for nextIdx in range(idx+1, len(prices)):
             profit = max(profit, prices[nextIdx] - prices[idx] + maxProfit(nextIdx+1, transactionsLeft-1, prices))
         return max(profit, maxProfit(idx+1, transactionsLeft, prices))
     ```

  2. **Memoization (Top-Down)**:
     **Pseudocode**:
     ```
     function maxProfit(idx, transactionsLeft, prices, dp):
         if idx == len(prices) or transactionsLeft == 0:
             return 0
         if dp[idx][transactionsLeft] != -1:
             return dp[idx][transactionsLeft]
         profit = 0
         for nextIdx in range(idx+1, len(prices)):
             profit = max(profit, prices[nextIdx] - prices[idx] + maxProfit(nextIdx+1, transactionsLeft-1, prices, dp))
         dp[idx][transactionsLeft] = max(profit, maxProfit(idx+1, transactionsLeft, prices, dp))
         return dp[idx][transactionsLeft]
     ```

---

#### 4. **Buy and Sell Stocks IV** ([BuySellStocks4.cpp](DP_STOCKS/BuySellStocks4.cpp))
- **Problem**: You can buy and sell a stock at most `k` times. Find the maximum profit you can achieve.

- **Approaches**:
  1. **Recursive Approach**:
     **Pseudocode**:
     ```
     function maxProfit(idx, transactionsLeft, prices):
         if idx == len(prices) or transactionsLeft == 0:
             return 0
         profit = 0
         for nextIdx in range(idx+1, len(prices)):
             profit = max(profit, prices[nextIdx] - prices[idx] + maxProfit(nextIdx+1, transactionsLeft-1, prices))
         return max(profit, maxProfit(idx+1, transactionsLeft, prices))
     ```

  2. **Memoization (Top-Down)**:
     **Pseudocode**:
     ```
     function maxProfit(idx, transactionsLeft, prices, dp):
         if idx == len(prices) or transactionsLeft == 0:
             return 0
         if dp[idx][transactionsLeft] != -1:
             return dp[idx][transactionsLeft]
         profit = 0
         for nextIdx in range(idx+1, len(prices)):
             profit = max(profit, prices[nextIdx] - prices[idx] + maxProfit(nextIdx+1, transactionsLeft-1, prices, dp))
         dp[idx][transactionsLeft] = max(profit, maxProfit(idx+1, transactionsLeft, prices, dp))
         return dp[idx][transactionsLeft]
     ```

---

#### 5. **Buy and Sell Stocks with Cooldown** ([BuySellStocksCooldown.cpp](DP_STOCKS/BuySellStocksCooldown.cpp))
- **Problem**: You can buy and sell a stock multiple times, but after selling, you must wait for one day before buying again.

- **Approaches**:
  1. **Recursive Approach**:
     **Pseudocode**:
     ```
     function maxProfit(idx, canBuy, prices):
         if idx >= len(prices):
             return 0
         if canBuy:
             return max(-prices[idx] + maxProfit(idx+1, 0, prices), maxProfit(idx+1, 1, prices))
         else:
             return max(prices[idx] + maxProfit(idx+2, 1, prices), maxProfit(idx+1, 0, prices))
     ```

  2. **Memoization (Top-Down)**:
     **Pseudocode**:
     ```
     function maxProfit(idx, canBuy, prices, dp):
         if idx >= len(prices):
             return 0
         if dp[idx][canBuy] != -1:
             return dp[idx][canBuy]
         if canBuy:
             dp[idx][canBuy] = max(-prices[idx] + maxProfit(idx+1, 0, prices, dp), maxProfit(idx+1, 1, prices, dp))
         else:
             dp[idx][canBuy] = max(prices[idx] + maxProfit(idx+2, 1, prices, dp), maxProfit(idx+1, 0, prices, dp))
         return dp[idx][canBuy]
     ```

---

#### 6. **Buy and Sell Stocks with Transaction Fees** ([BuySellStocksFees.cpp](DP_STOCKS/BuySellStocksFees.cpp))
- **Problem**: You can buy and sell a stock multiple times, but each transaction incurs a fixed fee.

- **Approaches**:
  1. **Recursive Approach**:
     **Pseudocode**:
     ```
     function maxProfit(idx, canBuy, prices, fee):
         if idx == len(prices):
             return 0
         if canBuy:
             return max(-prices[idx] + maxProfit(idx+1, 0, prices, fee), maxProfit(idx+1, 1, prices, fee))
         else:
             return max(prices[idx] - fee + maxProfit(idx+1, 1, prices, fee), maxProfit(idx+1, 0, prices, fee))
     ```

  2. **Memoization (Top-Down)**:
     **Pseudocode**:
     ```
     function maxProfit(idx, canBuy, prices, fee, dp):
         if idx == len(prices):
             return 0
         if dp[idx][canBuy] != -1:
             return dp[idx][canBuy]
         if canBuy:
             dp[idx][canBuy] = max(-prices[idx] + maxProfit(idx+1, 0, prices, fee, dp), maxProfit(idx+1, 1, prices, fee, dp))
         else:
             dp[idx][canBuy] = max(prices[idx] - fee + maxProfit(idx+1, 1, prices, fee, dp), maxProfit(idx+1, 0, prices, fee, dp))
         return dp[idx][canBuy]
     ```

---
