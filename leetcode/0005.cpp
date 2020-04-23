class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s == "" || s.size() == 1)
            return s;
        
        std::deque<char> max;
        for(size_t loc = 1 ; loc < s.size(); loc++)
        {
            auto searchPlalindrome = [&](const int midCharlength){
                std::deque<char> tmp;
                size_t loc1 = loc + 1;
                size_t loc2 = 0;
                tmp.push_back(s[loc]);
                if(midCharlength == 1)
                {
                    loc2 = loc - 1;
                }
                else
                {
                    loc2 = loc - 2;
                    tmp.push_back(s[loc - 1]);
                }
                while(loc1 < s.size())
                {
                    if(s[loc1] == s[loc2])
                    {
                        tmp.push_back(s[loc1]);
                        tmp.push_front(s[loc2]);
                    }
                    if(loc2 == 0 || s[loc1] != s[loc2])
                    {
                        break;
                    }
                    loc1++;
                    loc2--;
                }
                if(max.size() < tmp.size())
                {
                    max = std::move(tmp);
                }
            };
            searchPlalindrome(1);
            if(s[loc] == s[loc -1])
            {
                if(max.size() < 2)
                {
                    max.clear();
                    max.push_back(s[loc - 1]);
                    max.push_back(s[loc]);
                }
                if(loc - 1 > 0)
                {
                    searchPlalindrome(2);
                }
            }  
        }
        return std::string(max.begin(),max.end());
    }
};

