/////leetcode 第14题 最长公共前缀


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {

        if(strs.size() == 0)
            return "";
        auto miniStr = std::min_element(strs.begin(),strs.end(),[](const string& s1,const string& s2){ return s1.size() < s2.size();});
        auto minSize = miniStr->size();
        if(minSize == 0)
            return "";
        std::string maxPublicPreFix = "";
        for(size_t i = 0; i < minSize;i++)
        {
            auto guard = strs[0][i];
            for(auto& s : strs)
            {
                if(guard == s[i])
                    continue;
                else
                    return maxPublicPreFix;
            }
            maxPublicPreFix += guard;
        }
        return maxPublicPreFix;
    }
};