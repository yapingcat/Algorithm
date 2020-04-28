/////leetcode 第13题 罗马数字转整数

class Solution {
public:
    int romanToInt(string s) {
        
        int result = 0;
        auto now = s.cbegin();
        auto pre = now;
        for(; now != s.cend(); now++)
        {
            switch(*now)
            {
            case 'I': result += 1; pre = now; break;
            case 'V': *pre == 'I'? result += 3 : result+=5; pre = now; break;
            case 'X': *pre == 'I'? result += 8 : result+=10; pre = now; break;
            case 'L': *pre == 'X'? result += 30 : result+=50; pre = now; break;
            case 'C': *pre == 'X'? result += 80 : result+=100; pre = now; break;
            case 'D': *pre == 'C'? result += 300 : result+=500; pre = now; break; 
            case 'M': *pre == 'C'? result += 800 : result+=1000; pre = now; break; 
            default:
                break;
            }
        }
        return result;
    }
};