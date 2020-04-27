/////leetcode 第12题 整数转罗马数字

///索引查表法
class Solution {
public:
    std::vector<std::vector<std::string>> romanMap = {
        {"I","II","III","IV","V","VI","VII","VIII","IX"},
        {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
        {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"},
        {"M","MM","MMM"}, 
    };
    string intToRoman(int num) {
        std::deque<string> roman;
        int i = 0;
        while(num)
        {
            auto single = num % 10;
            if(single != 0)
                roman.push_front(romanMap[i][single - 1]);
            num = num / 10;
            i++;
        }
        std::string result;
        for(auto& it: roman)
        {
            result.append(it);
        }
        return result;
    }
};

//第二种解法
class Solution {
public:
    string intToRoman(int num) {
        char romanMap[4][2] = { {'I','V'},{'X','L'},{'C','D'},{'M'}}; 
        std::deque<char> roman;
        int i = 0;
        while(num)
        {
            auto single = num % 10;
            auto h = single / 5;
            auto l = single % 5;
            if(h == 1)
            {
                if(l == 4)
                {
                    roman.push_front(romanMap[i+1][0]);
                    roman.push_front(romanMap[i][0]);
                }
                else
                {
                    for(int j = 0; j < l;j++)
                    {
                        roman.push_front(romanMap[i][0]);
                    }
                    roman.push_front(romanMap[i][1]);
                }
            }
            else
            {
                if(l == 4)
                {
                    roman.push_front(romanMap[i][1]);
                    roman.push_front(romanMap[i][0]);
                }
                else
                {
                    for(int j = 0; j < l;j++)
                    {
                        roman.push_front(romanMap[i][0]);
                    }
                } 
            }

            num = num / 10;
            i++;
        }
        
        return std::string(roman.begin(),roman.end());
    }
};