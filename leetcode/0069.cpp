////leetcode 第69题 x 的平方根

class Solution {
public:
    int mySqrt(int x) {
        int n = 0;
        for(; n <= x; n++)
        {
            if(n * n == x)
                break;
            if(x - n * n < 2 * n + 1)
            {
                break;
            }
        }
        return n;
    }
};