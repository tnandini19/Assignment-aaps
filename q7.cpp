/* The sliding window technique is a method used to reduce the time complexity of problems involving arrays or strings. Instead of checking all possible subarrays or substrings (which is often brute force and slow), we slide a window (a range of elements) across the data to find a solution efficiently.

1) You define a window using two pointers (usually start and end).
2) Expand the window by moving the end pointer.
3) If a condition is violated (like repeating characters), shrink the window by moving the start pointer.
4) While moving the window, track the result (like max length, sum, etc.).

*/