////leetcode 第29题 两数相除

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        if(dividend == 0)
        {
            return 0;
        }
        if(divisor == 0x80000000)
        {
            if(dividend == 0x80000000)
                return 1;
            else 
                return 0;
        }
        if(dividend == 0x80000000 && divisor == -1)
        {
            return 0x7FFFFFFF;
        }
        if(dividend == 0x80000000 && divisor == 1)
        {
            return 0x80000000;
        }

        bool positive = true;
        if(dividend > 0 && divisor < 0)
        {
            positive = false;
            divisor *= -1;
        }   
        else if(dividend < 0 && divisor > 0)
        {
             positive = false;
             divisor *= -1;
        }
        
        int n = 0;
        int ret = 0;
        int tmpret = 1;
        int m = 0;  
        while(((unsigned int)divisor >> m) == 0 || ((unsigned int)divisor >> m) == -1) m++;
        for(;;)
        {
            while( (positive && ( dividend  > 0  && (dividend >=  ((unsigned int)divisor << n)) 
                            || (dividend < 0 && (dividend <= ((unsigned int)divisor<< n)))))
                            || (!positive && ((dividend < 0 && dividend <=  ((unsigned int)divisor << n))
                            || (dividend > 0 && dividend >= ((unsigned int)divisor << n)))))

            {
                n++;
                if(n > 30 - m)
                    break;
            }
            if(n == 0)
            {
                break;
            }
            dividend = dividend - ((unsigned int)divisor << --n);
            ret += tmpret << n;
            n = 0;
            tmpret = 1;
        }
        return positive ? ret : ret * - 1;
    }
};


