#include "../etc/utils.h"

/*=======================================================================================
    公共子字符串substring与公共子序列subsequence的区别：
    子字符串要求连续，而子序列不
*/

/*
    leetcode 5 Longest_Palindromic_Substring
    回文串总数  Manacher算法
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
    leetcode 5 Longest_Palindromic_Substring
    回文串总数 O(n^2) O(n)
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

/*
    leetcode 5 Longest_Palindromic_Substring
    回文串总数  滚动数组
*/
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

void code5() {
  string s = "acabddbacaa";
  longestPalindrome(s);
}
/*=======================================================================================
    公共子字符串substring与公共子序列subsequence的区别：
    子字符串要求连续，而子序列不
    可以用memset初始化 int数组值为0，-1，不要赋具体的值
*/
/*
    最长公共子字符串 Longest Common substring
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
    最长公共子字符串 Longest Common SubString LCS
    枚举子字符串的起点与终点
    dp[i][j]表示 以s1[i]与s2[j]结尾的最长公共子串的长度

    if s1[i]==s2[j]
        dp[i][j]=dp[i-1][j-1]+1
    else
        dp[i][j]=0
    m,n
*/

int lengthLCS(string s1, string s2) {
  int m = s1.length();
  int n = s2.length();
  int dp[m][n];
  memset(dp, 0, sizeof(dp));
  int ans = 0;
  for (int i = 0; i < m; i++)
    if (s1[i] == s2[0]) dp[i][0] = 1;
  for (int j = 0; j < n; j++)
    if (s1[0] == s2[j]) dp[0][j] = 1;
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (s1[i] == s2[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if (dp[i][j] > ans) ans = dp[i][j];
      } else
        dp[i][j] = 0;
    }
  }
  return ans;
}
string LCS(string s1, string s2) {
  int m = s1.length();
  int n = s2.length();
  int dp[m][n];
  memset(dp, 0, sizeof(dp));
  int endPos = 0, maxLength = 0;
  for (int i = 0; i < m; i++)
    if (s1[i] == s2[0]) dp[i][0] = 1;
  for (int j = 0; j < n; j++)
    if (s1[0] == s2[j]) dp[0][j] = 1;
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      if (s1[i] == s2[j]) {
        dp[i][j] = dp[i - 1][j - 1] + 1;
        if (dp[i][j] > maxLength) {
          maxLength = dp[i][j];
          endPos = i;
        }
      } else
        dp[i][j] = 0;
    }
  }

  string ans = s1.substr(endPos + 1 - maxLength, maxLength);
  return ans;
}
void code22() {
  vector<string> lcs_answer = getStringAnswerFromTxt();
  vector<vector<string> > stringPairs = getStringPairsFromTxt();
  string s1, s2, res, ans;
  int n = lcs_answer.size();
  for (int i = 0; i < n; i++) {
    s1 = stringPairs[i][0];
    s2 = stringPairs[i][1];
    res = LCS(s1, s2);
    ans = lcs_answer[i];
    if (ans.length() != res.length())
      cout << "ans : " << ans << " ,res " << res << endl;
  }
}

/*
    最长递增子字符串 Longest Increasing SubString LIS
    
    枚举子串终点
    l
*/
int lengthOfLIS(string s){
  int n=s.length();
  int ans=1;
  for(int i=1;i<n;i++){
    int j=i,tempMax=1;
    while(j>=1){
      if(s[j-1]<s[j]){
        tempMax++;
        j--;
      }
      else break;
    }
    if(tempMax>ans){
      ans=tempMax;
    }
  }
  
  return ans;
}
string LIS(string s){
  int n=s.length();
  int ans=1;
  int endPos=0;
  for(int i=1;i<n;i++){
    int j=i,tempMax=1;
    while(j>=1){
      if(s[j-1]<s[j]){
        tempMax++;
        j--;
      }
      else break;
    }
    if(tempMax>ans){
      ans=tempMax;
      endPos=i;
    }
  }
  return s.substr(endPos-ans+1,ans);
}
void codeLIS(){
  string ans=LIS("12345678901234567890");
  cout << ans<<endl;
}


//=======================================================================================
/*
    最长公共子序列 Largest Common SubSequence
    dp[i][j]表示字符串s1[0],s1[1]......s1[i]与字符串s2[0],s2[1]......s2[j]的LCS
    m,nl
*/
int SubSequence(string s1, string s2) {
  if (s1.length() > s2.length()) swap(s1, s2);
  int m = s1.length();
  int n = s2.length();
  int ans = 0;
  return ans;
}

string SubSequenceLength(string s1, string s2) { return s1; }

/*
    leetcode 32. Longest Valid Parentheses
    ) ((()())())(()()) ))) ((()())()) (( (()())
    枚举子串起点
*/

int longestValidParentheses(string s) {
  int ans=0;
  int n=s.length();
  stack<char> brac_stack;
  for(int i=0;i<n;i++){
    string p=s.substr(i,n);
    int subMax=0;
    // 清空栈
    stack<char>empty;
    swap(brac_stack,empty);
    for(char c:p){
      if(c==')'){
        if(brac_stack.empty())break;
        subMax+=2;
        brac_stack.pop();
        
      }
      else{
        brac_stack.push(c);
      }
    }
    if(brac_stack.empty()&&subMax>ans)ans=subMax;
  }
  return ans;
}

void code32(){
  string parenthesis="(())(";
  longestValidParentheses(parenthesis);
}

/*=======================================================================================
    leetcode152. Maximum Product Subarray
    记录最大及最小连续子数组乘积
    [2,3,-2,4] return 6
    [2,0,-3,3,-2,4,-5,-1]
*/
int maxProduct(vector<int> &nums) {
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
/*=======================================================================================
     leetcode62. Unique Paths
*/
int uniquePaths(int m, int n) {
  int **dp = new int *[m];
  for (int i = 0; i < m; i++) dp[i] = new int[n], dp[i][0] = 1;
  for (int j = 0; j < n; j++) dp[0][j] = 1;
  for (int i = 1; i < m; i++) {
    for (int j = 1; j < n; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    }
  }
  //   printMatrix(dp, m, n);
  return dp[m - 1][n - 1];
}
void code62() { uniquePaths(8, 8); }


/*=======================================================================================
     leetcode542. 01 Matrix
*/
vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
  int m=mat.size();
  int n=mat[0].size();
  int maxDis=m+n-1;
  int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
  vector<vector<int>>ans(m,vector<int>(n,maxDis));
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      if(mat[i][j]==0)
        ans[i][j]=0;
  int posX,posY;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      for(int k=0;k<4;k++){
        posX=i+dir[k][0];
        posY=j+dir[k][1];
        if(posX>=0&&posX<m&&posY>=0&&posY<n)
          if(ans[i][j]>ans[posX][posY]+1)
            ans[i][j]=ans[posX][posY]+1;
        
      }
    }
  }
  for(int i=m-1;i>=0;i--){
    for(int j=n-1;j>=0;j--){
      for(int k=0;k<4;k++){
        posX=i+dir[k][0];
        posY=j+dir[k][1];
        if(posX>=0&&posX<m&&posY>=0&&posY<n)
          if(ans[i][j]>ans[posX][posY]+1)
            ans[i][j]=ans[posX][posY]+1;
        
      }
    }
  }
  return ans;
}
void code52(){

}

/*=======================================================================================
     leetcode410. Split Array Largest Sum
     将数组分为m个连续子数组，使得所有子数组元素和的最大值最小
     1=<m<=min(50,length)*/

int splitArray(vector<int>& nums, int m) {

}
void code410(){

}
/*=======================================================================================
     leetcode410. maxSubArray
     最大子数组和，dp[i]以nums[i]结尾的最大子数组和
*/
int  maxSubArray(vector<int> nums){
    
    int n=nums.size();
    vector<int>dp(n);
    int ans=INT32_MIN;
    dp[0]=nums[0];
    cout<<dp[0]<<"  ";
    for(int i=1;i<n;i++){
        dp[i]=nums[i];
        if(dp[i-1]>0)dp[i]+=dp[i-1];
        if(ans<dp[i])ans=dp[i];
        cout<<dp[i]<<"  ";
    }
    return ans;
}
void maxSubArray(){
    vector<int> array=randomNone0Array();
    printVector(array);
    int ans=maxSubArray(array);
    cout<<endl<<ans;
}
/*=======================================================================================
     leetcode410. maxSubRectangle
     和最大的子矩形
     i为起点行，j为终点行，求出i~j行下，每一列的和即为dp[1],dp[2],dp[3]...dp[n]
*/
int  maxSubRec(vector<vector<int>> nums){
    int m=nums.size();
    int n=nums[0].size();
    vector<int>dp(n,0);
    int ans=INT32_MIN;
    int curMaxSum;
    for(int i=0;i<m;i++){
      // 初始行变化时重置dp
      fill(dp.begin(),dp.end(),0);
      for(int j=i;j<m;j++){
        //  curMaxSum表示以第i行开始~第j行结束，并以第k列结尾的子矩形最大和
        curMaxSum=nums[j][0];
        dp[0]=nums[j][0];
        cout<<curMaxSum<<" ";
        for(int k=1;k<n;k++){
          // 逐列更新每列和dp[k]
          dp[k]+=nums[j][k];
          if(curMaxSum>0)curMaxSum=curMaxSum+dp[k];
          else curMaxSum=dp[k];
          cout<<curMaxSum<<" ";
          if(curMaxSum>ans)ans=curMaxSum;
        }
        cout<<endl;
      }
    }
    return ans;
}
void maxSubRec(){
    int row=6;
    int col=5;
    vector<vector<int>> nums;
    vector<int>curRow;
    srand(time(nullptr));
    for(int i=0;i<row;i++){
      curRow=randomNone0Array(col);
      nums.push_back(curRow);
    }
    printVectorMatrix(nums,row,col);
    int ans=maxSubRec(nums);
    cout<<ans;
}
//=======================================================================================
int main() {
  // writeLCSAnswerToTxt();
  //   code22();
  maxSubRec();
  return 0;
}
