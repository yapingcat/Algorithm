/////leetcode 第15题 3数之和为0


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        std::unordered_set<int> sets;
        for(size_t i = 0; i <nums.size(); i++)
        {
            if(sets.count(nums[i]))
            {
                continue;
            }
            std::set<int> setss;
            for(size_t j = i + 1;j < nums.size();j++)
            {
                if(sets.count(nums[j]) 
                    || setss.count(nums[j]) || setss.count(0 - nums[i] - nums[j]))
                {
                    continue;
                }
                for(size_t k = j + 1;k < nums.size();k++)
                {
                    if(nums[i] + nums[j] + nums[k] == 0)
                    {
                        if(sets.count(nums[k]) || setss.count(nums[k]))
                        {
                            continue;
                        }
                        result.push_back({nums[i],nums[j],nums[k]});
                        break;
                    }
                }
                setss.emplace(nums[j]);
            }
            sets.emplace(nums[i]);
        }
        return result;
    }
};