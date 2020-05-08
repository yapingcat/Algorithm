////leetcode 221题

//丑陋的实现
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        if(matrix.size() == 1)
        {
            for(auto&& c : matrix[0])
            {
                if(c == '1')
                    return 1;
            }
            return 0;
        }
        vector<vector<char>> subMatrix(matrix.begin() + 1,matrix.end());
        int max = maximalSquare(subMatrix);
        int left = -1;
        int right = -1;
        for(int i = 0; i < matrix[0].size(); i++)
        {
            if(matrix[0][i] == '1')
            {
                if(left == -1) left = i;
                right = i;
                if((right - left + 1) * (right - left + 1) > max && (right - left <  matrix.size()))
                {
                    int j = 0;
                    for(j = left; j <= right; j++)
                    {
                        int k = 0;
                        for(k = 0; k <= right - left; k++)
                        {
                            if(matrix[k][j] == '0')
                                break;
                        }
                        if(k <= right - left)
                            break;
                    }
                    if(j <= right)
                    {
                        if(++left > right)
                            left = -1;
                    }
                    else 
                    {
                        max  = (right - left + 1) * (right - left + 1);
                    }
                }  
            }
            else
            {
                left = -1;
                right = -1;
            }
        }
        return max;
    }
};