#include "../etc/utils.h"

/*
公共子字符串substring与公共子序列subsequence的区别：
子字符串要求连续，而子序列不
*/

/*
    Manacher算法
    填充*符号使字符串为奇数串
    枚举对称中心
*/
string longestPalindrome(string s)
{
    int len = s.length();
    string p = "*";
    for (char c : s)
    {
        p.push_back(c);
        p.push_back('*');
    }
    int maxLength = 1, startPos, temp;

    for (int k = 1; k < 2 * len; k++)
    {
        int i = k - 1, j = k + 1;
        temp = 1;
        while (i >= 0 && j < 2 * len + 1)
        {
            if (p[i] != p[j])
                break;
            temp += 2;
            i--;
            j++;
        }
        if (temp > maxLength)
        {
            startPos = i + 1;
            maxLength = temp;
        }
    }
    s = p.substr(startPos, maxLength);
    p = "";
    for (int i = 0; i < maxLength; i++)
    {
        if (s[i] != '*')
            p.push_back(s[i]);
    }
    return p;
}
/*
O(n^2) O(n)
dp[i][j]表示以s[i]开头，s[j]结尾的最长Palindrome长度
if s[i]=s[j]
    dp[i][j]=dp[i+1][j-1]+2
else 
    dp[i][j]=1
*/
string longestPalindrome_3(string s)
{
    int len = s.length();
    if (len == 0)
        return nullptr;
    int dp[len][len];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < len; i++)
        dp[i][i] = 1;
    int low = 0, hi = 0, maxLength = 1;
    for (int j = 1; j < len; j++)
    {
        for (int i = j - 1; i >= 0; i--)
        {
            if (s[i] == s[j])
            {
                if (i + 1 == j)
                    dp[i][j] = 2;
                else
                {
                    if (dp[i + 1][j - 1] > 0)
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            }
            if (dp[i][j] > maxLength)
            {
                maxLength = dp[i][j];
                low = i;
                hi = j;
            }
        }
    }
    return s.substr(low, maxLength);
}

// 滚动数组
string longestPalindrome_4(string s)
{
    int len = s.length();
    if (len == 0)
        return nullptr;
    int dp[len][2];
    memset(dp, 0, sizeof(dp));
    int low = 0, hi = 0, maxLength = 1;
    for (int j = 1; j < len; j++)
    {
        dp[j][j % 2] = 1;
        for (int i = j - 1; i >= 0; i--)
        {
            if (s[i] == s[j])
            {
                if (i + 1 == j)
                    dp[i][j % 2] = 2;
                else
                {
                    if (dp[i + 1][(j - 1) % 2] > 0)
                        dp[i][j % 2] = dp[i + 1][(j - 1) % 2] + 2;
                    else
                        dp[i][j % 2] = 0;
                }
            }
            else
                dp[i][j % 2] = 0;
            if (dp[i][j % 2] > maxLength)
            {
                maxLength = dp[i][j % 2];
                low = i;
                hi = j;
            }
        }
    }
    string ans = s.substr(low, maxLength);
    return ans;
}
void code5_Longest_Palindromic_Substring()
{
    string s = "acabddbacaa";
    longestPalindrome(s);
}
//  回文串总数
int countSubstrings(string s)
{
    int len = s.length();
    int dp[len][2];
    memset(dp, 0, sizeof(dp));
    int ans = len;

    for (int j = 1; j < len; j++)
    {
        dp[j][j % 2] = 1;
        for (int i = j - 1; i >= 0; i--)
        {
            if (s[i] == s[j])
            {
                if (i + 1 == j)
                    dp[i][j % 2] = 2;
                else
                {
                    if (dp[i + 1][(j - 1) % 2] > 0)
                        dp[i][j % 2] = dp[i + 1][(j - 1) % 2] + 2;
                    else
                        dp[i][j % 2] = 0;
                }
            }
            else
                dp[i][j % 2] = 0;
            if (dp[i][j % 2] > 0)
                ans++;
        }
    }
    return ans;
}
void code647_Palindromic_Substrings()
{
    string s = "acabddbacaa";
    countSubstrings(s);
}

int main()
{
    code647_Palindromic_Substrings();
    return 0;
}
