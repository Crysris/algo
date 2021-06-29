#include "../etc/utils.h"

/*=======================================================================================
    Manacher算法
    填充*符号使字符串为奇数串
    枚举对称中心
*/
string longestPalindrome(string s) {
  int len = s.length();
  string p = "*";
  for (char c : s) {
    p.push_back(c);
    p.push_back('*');
  }
  int maxLength = 1, startPos, temp;

  for (int k = 1; k < 2 * len; k++) {
    int i = k - 1, j = k + 1;
    temp = 1;
    while (i >= 0 && j < 2 * len + 1) {
      if (p[i] != p[j]) break;
      temp += 2;
      i--;
      j++;
    }
    if (temp > maxLength) {
      startPos = i + 1;
      maxLength = temp;
    }
  }
  s = p.substr(startPos, maxLength);
  p = "";
  for (int i = 0; i < maxLength; i++) {
    if (s[i] != '*') p.push_back(s[i]);
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
string longestPalindrome_3(string s) {
  int len = s.length();
  if (len == 0) return nullptr;
  int dp[len][len];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < len; i++) dp[i][i] = 1;
  int low = 0, hi = 0, maxLength = 1;
  for (int j = 1; j < len; j++) {
    for (int i = j - 1; i >= 0; i--) {
      if (s[i] == s[j]) {
        if (i + 1 == j)
          dp[i][j] = 2;
        else {
          if (dp[i + 1][j - 1] > 0) dp[i][j] = dp[i + 1][j - 1] + 2;
        }
      }
      if (dp[i][j] > maxLength) {
        maxLength = dp[i][j];
        low = i;
        hi = j;
      }
    }
  }
  return s.substr(low, maxLength);
}

// 滚动数组
string longestPalindrome_4(string s) {
  int len = s.length();
  if (len == 0) return nullptr;
  int dp[len][2];
  memset(dp, 0, sizeof(dp));
  int low = 0, hi = 0, maxLength = 1;
  for (int j = 1; j < len; j++) {
    dp[j][j % 2] = 1;
    for (int i = j - 1; i >= 0; i--) {
      if (s[i] == s[j]) {
        if (i + 1 == j)
          dp[i][j % 2] = 2;
        else {
          if (dp[i + 1][(j - 1) % 2] > 0)
            dp[i][j % 2] = dp[i + 1][(j - 1) % 2] + 2;
          else
            dp[i][j % 2] = 0;
        }
      } else
        dp[i][j % 2] = 0;
      if (dp[i][j % 2] > maxLength) {
        maxLength = dp[i][j % 2];
        low = i;
        hi = j;
      }
    }
  }
  string ans = s.substr(low, maxLength);
  return ans;
}
void code5_Longest_Palindromic_Substring() {
  string s = "acabddbacaa";
  longestPalindrome(s);
}
//  回文串总数
int countSubstrings(string s) {
  int len = s.length();
  int dp[len][2];
  memset(dp, 0, sizeof(dp));
  int ans = len;

  for (int j = 1; j < len; j++) {
    dp[j][j % 2] = 1;
    for (int i = j - 1; i >= 0; i--) {
      if (s[i] == s[j]) {
        if (i + 1 == j)
          dp[i][j % 2] = 2;
        else {
          if (dp[i + 1][(j - 1) % 2] > 0)
            dp[i][j % 2] = dp[i + 1][(j - 1) % 2] + 2;
          else
            dp[i][j % 2] = 0;
        }
      } else
        dp[i][j % 2] = 0;
      if (dp[i][j % 2] > 0) ans++;
    }
  }
  return ans;
}
/*=======================================================================================
    公共子字符串substring与公共子序列subsequence的区别：
    子字符串要求连续，而子序列不
    可以用memset初始化 int数组值为0，-1，不要赋具体的值
*/
/*
    最长公共子字符串 Longest Common Subsequence
    枚举子字符串的起点与终点
    n==m
*/
string LCS_1(string s1, string s2) {
  int n = s2.length();
  int maxx = 0, startx = 0;

  int dp[n][2];
  memset(dp, 0, sizeof(dp));
  for (int j = 0; j < n; j++) {
    if (s1[j] == s2[j]) dp[j][j % 2] = 1;
    for (int i = j - 1; i >= 0; i--) {
      if (dp[i + 1][j % 2] == 0)
        dp[i][j % 2] = 0;
      else {
        if (s1[i] == s2[i]) {
          dp[i][j % 2] = dp[i + 1][j % 2] + 1;
        } else {
          dp[i][j % 2] = 0;
        }
      }
      if (maxx < dp[i][j % 2]) {
        maxx = dp[i][j % 2];
        startx = i;
      }
    }
  }
  string ans = s1.substr(startx, maxx);
  return ans;
}
int length_LCS_1(string s1, string s2) {
  int n = s2.length();
  int ans = 0;
  int dp[n][2];
  memset(dp, 0, sizeof(dp));
  for (int j = 0; j < n; j++) {
    if (s1[j] == s2[j]) dp[j][j % 2] = 1;
    for (int i = j - 1; i >= 0; i--) {
      if (dp[i + 1][j % 2] == 0)
        dp[i][j % 2] = 0;
      else {
        if (s1[i] == s2[i]) {
          dp[i][j % 2] = dp[i + 1][j % 2] + 1;
        } else {
          dp[i][j % 2] = 0;
        }
      }
      if (ans < dp[i][j % 2]) ans = dp[i][j % 2];
    }
  }
  return ans;
}

/*
    最长公共子字符串 Longest Common Subsequence LCS
    枚举子字符串的起点与终点
    dp[i][j]表示字符串s1[0],s1[1]......s1[i]与字符串s2[0],s2[1]......s2[j]的LCS
    m,n
*/
int lengthLCS(string s1, string s2) {
  int m = s1.length();
  int n = s2.length();
  int dp[m][n];
  memset(dp, 0, sizeof(dp));
  int ans = 0;
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (s1[i] == s2[j]) {
        if (i == 0 && j == 0)
          dp[i][j] = 1;
        else if (i == 0)
          dp[]
      }
    }
  }
  return ans;
}
string LCS(string s1, string s2) { return s1; }
void code22() {
  string s1 = "abdbacefg";
  string s2 = "bgfedecdbacaefg";
  lengthLCS(s1, s2);
}

//=======================================================================================
/*
    最长公共子序列

*/
int SubSequence(string s1, string s2) {
  int n = s1.length();
  int ans = 0;
  return ans;
}

string SubSequenceLength(string s1, string s2) { return s1; }

/*
    leetcode152. Maximum Product Subarray
    记录最大及最小连续子数组乘积
    [2,3,-2,4] return 6
    [2,0,-3,3,-2,4,-5,-1]
*/
int maxProduct(vector<int>& nums) {
  int len = nums.size();
  int ans = nums[0], res, pre = -1;
  vector<int> zeroPos;
  for (int i = 0; i < len; i++) {
    if (nums[i] == 0) {
      res = 1;
      pre = -1;
      if (ans < 0) ans = 0;
      continue;
    }
    if (pre == -1) {
      pre = i;
      res = nums[i];
    } else
      res *= nums[i];
    if (ans < res) ans = res;
  }
  return ans;
}
void code152() {
  //   vector<int> nums{2, 0, -3, 3, -2, 4, -5, -1};
  vector<int> nums{3, -1, 4};
  int ans = maxProduct(nums);
}

void code647_Palindromic_Substrings() {
  string s = "acabddbacaa";
  countSubstrings(s);
}

int main() {
  code22();
  return 0;
}
