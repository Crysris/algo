#include "utils.h"

// '(', ')', '{', '}', '[' and ']'
// c{[]})
bool code20_isValid(string s)
{
    if ((s.length() & 1) == 1)
        return false;
    stack<string> str_stack;
    string temp, pstr;
    for (char c : s)
    {
        pstr = c;
        if (pstr == "[" || pstr == "(" || pstr == "{")
        {
            str_stack.push(pstr);
        }
        else if (pstr == "]" || pstr == ")" || pstr == "}")
        {
            if (str_stack.empty())
                return false;
            temp = str_stack.top();
            if (pstr == ")")
            {
                if (temp != "(")
                    return false;
            }
            else if (pstr == "]")
            {
                if (temp != "[")
                    return false;
            }
            else
            {
                if (temp != "{")
                    return false;
            }
            str_stack.pop();
        }
    }
    if (str_stack.size() != 0)
        return false;
    return true;
}
void code20_Valid_Parentheses()
{
    bool ans = code20_isValid(")");
    cout << ans << endl;
}
int code7_reverse(int x)
{
    if (x == 0)
        return 0;
    bool flag;
    if (x < 0)
        flag = true;
    else
        flag = false;
    x = abs(x);
    int temp = 0, ans = 0;
    while (x != 0)
    {
        if (10 * ans + temp > INT_MAX)
            return 0;
        ans = 10 * ans + temp;
        temp = x % 10;
        x = x / 10;
    }
    if (10 * ans + temp > INT_MAX)
        return 0;
    ans = 10 * ans + temp;
    if (flag)
        return (-1) * ans;
    return ans;
}
void code7_Reverse_Integer()
{
    int ans = code7_reverse(1534236469);
    cout << ans;
}
int main()
{
    code7_Reverse_Integer();
}