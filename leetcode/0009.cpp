//leetcode 第9题  回文数

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) 
            return false;
        if(x / 10  == 0)
            return true;
        if(x % 10 == 0 && x / 10)
            return false;
        int newx = 0;
        while(x)
        {
            auto siglenum = x % 10;
            x = x / 10;
            if(x == newx && x != 0)
                return true;
            newx = newx * 10 + siglenum;
            if(newx == x)
                return true;
            else if(newx > x)
                return false;
        }
        return false;
    }
};