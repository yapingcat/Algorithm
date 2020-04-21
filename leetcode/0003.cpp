///leetcode 第3题 无重复字符的最长子串
///算法原理：类似于弹性窗口，不断向前滑动，
///    起始弹性窗口为0，开始遍历字符串s,
///    若当前字符c不在窗口之中，则窗口右边界，往右移动，纳入字符C,若在窗口之中，弹性窗口左边界往左移动
///    移动至窗口中含有字符c的下一个位置
///    
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::string::size_type left = 0;
        std::string::size_type right = 0;
        int maxlen = 0;
        auto isBetweenLfetandRight = [&](const char &c){
            for(int i = left; i < right; i ++)
            {
                if(s[i] == c)
                {
                    return i; 
                }
            }
            return -1;
        };
        for(right = 0;right < s.size(); right++)
        {
            auto ret = isBetweenLfetandRight(s[right]);
            if(ret != -1)
            {
                if(maxlen < right - left)
                    maxlen = right - left;
                left = ret + 1;
            }
        }
        if(maxlen < right - left)
            maxlen = right - left;
        return maxlen;
    }
};