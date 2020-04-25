///leetcode 第8题 字符串转换整数 (atoi)


class Solution {
public:
    int myAtoi(string str) {
        if(str.size() == 0 || (str[0] != '-' && !isdigit(str[0])))
             return 0;

        std::vector<char> numbers;
        std::deque<char> maxint;
        std::deque<char> minint;
        int max = 0x7FFFFFFF;
        int min = 0x80000000;
        while(max)
        {
            maxint.push_front(max % 10);
            max = max / 10;
        }
        while(min)
        {
            minint.push_front((min % 10) * -1);
            min = min / 10;
        }

        std::string::size_type idx = 0;
        if(str[idx] == '-')
            idx++;
        for(;idx < str.size();idx++)
        {
            if(!isdigit(str[idx]))
                break;
            numbers.push_back(str[idx]);
        }
        if(numbers.size() == 0)
            return 0;
        decltype(minint) tmp;
        if(str[0] == '-')
        {
            if(numbers.size() > minint.size())
                return 0x80000000;
            if(numbers.size() == minint.size())
                tmp = std::move(minint);
        }
        else
        {
            if(numbers.size() > maxint.size())
                return 0x7FFFFFFF;
            if(numbers.size() == maxint.size())
                tmp = std::move(maxint);
        }
        if(tmp.size() > 0)
        {
            for(size_t i = 0; i <  tmp.size();i++)
            {
                if(tmp[i] < numbers[i])
                    return 0;
                else if(tmp[i] > numbers[i])
                    break;
            }
        }
        int result = 0;
        for(auto& c : numbers)
        {
            result = result * 10 + c;
        }
        return str[0] == '-' ? result * -1: result;
    }
};