///leetcode 第6题 Z形变换

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 0)
            return "";
        else if(numRows == 1)
            return s;
        std::string strs[numRows];
        int witchRow = 0;
        int addtionnal = 1;
        for(auto& c: s)
        {
            strs[witchRow].push_back(c);
            if(witchRow == 0)
                addtionnal = 1;
            else if(witchRow == numRows - 1)
                addtionnal = -1;
            witchRow += addtionnal;
        }
        std::string result = "";
        for(auto&& c : strs)
        {
            result += c;
        }
        return result;
    }
};