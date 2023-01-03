#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n)
    {
        if (n < 4)
            return n;
        int prev1 = 2; int prev2 = 1;
        for (int i = 3; i <= n; i++)
        {
            int tmp = prev1;
            prev1 += prev2;
            prev2 = tmp;
        }
        return prev1;
    }
};

// Recursive alternative but timeout:

// class Solution {
// public:
//     int climbStairs(int n)
//     {
//         if (n < 4)
//             return n;
//         else
//             return climbStairs(n - 1) + climbStairs(n - 2);
//     }
// },
