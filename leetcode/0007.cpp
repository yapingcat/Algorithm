///leetcode 第7题 整数反转
///
///

class Solution {
public:
    int reverse(int x) {
        auto n = x;
        int maxPositive = 0x7FFFFFFF;
        int maxNegtive = 0x80000000;
        std::deque<int> positiveBignum;
        std::deque<int> negtiveBignum;
        std::deque<int> bignum;
        int result = 0;
        while(maxPositive != 0)
        {
            auto singleDigits = maxPositive % 10;
            positiveBignum.push_front(singleDigits);
            maxPositive = maxPositive / 10;
        }
        while(maxNegtive != 0)
        {
            auto singleDigits = maxNegtive % 10;
            negtiveBignum.push_front(singleDigits * -1);
            maxNegtive = maxNegtive / 10;
        }
        while(n != 0)
        {
            auto singleDigits = n % 10;
            bignum.push_front(singleDigits < 0 ?  singleDigits * -1 : singleDigits);
            n = n / 10;
        }
        std::deque<int> reverseBignum(bignum.rbegin(),bignum.rend());
        std::deque<int> tmp;
        if(x < 0)
        {
            tmp = std::move(negtiveBignum);
        }
        else
        {
            tmp = std::move(positiveBignum);
        }
        if(reverseBignum.size() ==  tmp.size())
        {
            for(int i = 0,j = 0; i <  reverseBignum.size() && j < tmp.size(); i++,j++)
            { 
                if(reverseBignum[i] > tmp[j])
                    return 0;
                else if(reverseBignum[i] < tmp[j])
                    break;
            }
        }
        for(auto it : reverseBignum)
        {
            result = 10 * result + it;
        }
        return x > 0? result : result * -1;
    }
};