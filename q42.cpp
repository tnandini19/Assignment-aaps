/*Dynamic Programming (DP) is a technique used to solve problems by breaking them down into overlapping subproblems and storing their solutions to avoid redundant work.
In the maximum subarray problem, DP involves creating a dp array where each element dp[i] stores the maximum subarray sum ending at index i.
The recurrence relation is dp[i] = max(nums[i], dp[i-1] + nums[i]).
The maximum subarray sum is the largest value in the dp array.
The time complexity of this approach is O(n) and the space complexity is O(n).
Kadane's algorithm is a space-optimized version of this, using only two variables (O(1) space) to achieve the same result.*/