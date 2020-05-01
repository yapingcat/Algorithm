/////leetcode 22题 括号生成
////动态规划，解决子问题最优解

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if(n == 0)
        {
            result.push_back("");
            return result;
        }
        if(n == 1)
        {
            result.push_back("()");
            return result;
        }
        for(int i = 0; i < n; i ++)
        {
            auto ret1 = generateParenthesis(i);
            auto ret2 = generateParenthesis(n - i  - 1);
            if(ret1.size() == 0)
            {
                for(auto&& it : ret2)
                {
                    std::string bracket = "()" +  it;
                    result.push_back(bracket);
                }
            }
            else
            {
                for(auto && it : ret1)
                {
                    for(auto&& it1 : ret2)
                    {
                        std::string bracket = "(" +  it + ")";
                        bracket += it1;
                        result.push_back(bracket);
                    }
                }
            }
        }
        return result;   
    }
};