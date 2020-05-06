////leetcode 17题 电话号码的字母组合


class Solution {
public:
    std::unordered_map<char,std::vector<char>> charmap {

        {'2',{'a','b','c'}},
        {'3',{'d','e','f'}},
        {'4',{'g','h','i'}},
        {'5',{'j','k','l'}},
        {'6',{'m','n','o'}},
        {'7',{'p','q','r','s'}},
        {'8',{'t','u','v'}},
        {'9',{'w','x','y','z'}},
    };
    vector<string> letterCombinations(string digits) {
        std::unordered_set<std::string> charSet;
        for(auto&& c : digits)
        {
            std::unordered_set<std::string> charSet2;
            if(charSet.empty())
            {
                for(auto&& c2 : charmap[c])
                {
                    charSet.insert({c2});
                }
            }
            else
            {
                for(auto s : charSet)
                {
                    for(auto&& c2 : charmap[c])
                    {
                        charSet2.emplace(s + c2);
                    }
                }
                charSet = std::move(charSet2);
            }
        }
        std::vector<std::string> result(charSet.begin(),charSet.end());
        return result;
    }
};