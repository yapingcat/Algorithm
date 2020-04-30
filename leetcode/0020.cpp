////leetcode 第19题 删除链表的倒数第N个节点


class Solution {
public:
    bool isValid(string s) {
        auto leftBrackets = [](const char& rightBrackets){
            if(rightBrackets == ')') return '(';
            else if(rightBrackets == '}') return '{';
            else if(rightBrackets == ']') return '[';
            else return '$';
        };
        auto isrightBrackets = [](const char& leftBrackets){
            if(leftBrackets == ')' || leftBrackets == '}' || leftBrackets == ']') 
                return true;
            else
                return false;
        };
        std::stack<char> bracketsStack;
        bracketsStack.push('#');
        for(auto&& c : s)
        {
            if(leftBrackets(c) == bracketsStack.top())
            {
                bracketsStack.pop();
            }
            else if(isrightBrackets(c))
            {
                bracketsStack.push(c);
                break;
            }
            else
            {
                bracketsStack.push(c);
            }
        }
        if(bracketsStack.top() == '#')
            return true;
        else
            return false;
    }
};