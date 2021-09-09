#include <sys/time.h>  //clock, gettimeofday, time

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

#define ARRAY_SIZE 1000

#define LIST_NODE_NUMBER 100
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
vector<int> randomNone0Array(){
    vector<int> array;
    srand(time(nullptr));
    int MAX_SIZE=30;
    int MAX_VALUE=10;
    int plus_minus;
    int value;
    for(int i=0;i<MAX_SIZE;i++){
        value=rand()%MAX_VALUE+1;//[1,10]
        if(value&1)plus_minus=1;
        else plus_minus=-1;
        value*=plus_minus;
        array.push_back(value);
    }
    return array;
}
void printVector(vector<int> array) {
  for (auto p : array) {
    cout << p << " ";
  }
  cout << endl;
}
void printVector(vector<string> array) {
  for (auto p : array) {
    cout << p << " ";
  }
  cout << endl;
}
void printArray(int *array, int n) {
  for (int i = 0; i < n; i++) cout << array[i] << " ";
  cout << endl;
}
void printMatrix(int **array, int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

/*
  枚举最长公共子串长度(m<n)
  i,j为子串的起点，k为长度l

*/
string getLCSAnswer(string s1, string s2) {
  if (s1.length() > s2.length()) swap(s1, s2);
  int m = s1.length();
  int n = s2.length();
  int start1, start2, count;
  for (int k = m; k > 0; k--) {
    for (int i = 0; i <= m - k; i++) {
      for (int j = 0; j <= n - k; j++) {
        start1 = i;
        start2 = j;
        count = 0;
        while (count < k) {
          if (s1[start1] != s2[start2]) {
            break;
          }
          start1++;
          start2++;
          count++;
        }
        if (count == k) {
          string ans = s1.substr(i, k);
          return ans;
        }
      }
    }
  }
  return nullptr;
}

/*
  根据测试用例中的字符串对生成LCS答案并储存在文本中

*/
void writeLCSAnswerToTxt() {
  string outPath = "../testcase/stringPairs.txt";
  string inPath = "../testcase/LCS_answer.txt";
  ifstream out(outPath.c_str());
  ofstream in(inPath.c_str());
  if (!out.is_open()) {
    cerr << "open file error!" << endl;
  }
  if (!in.is_open()) {
    cerr << "open file error!" << endl;
  }
  string s1 = "", s2 = "", ans = "";
  while (getline(out, s1, ' ')) {
    getline(out, s2);
    ans = getLCSAnswer(s1, s2);
    in << ans << endl;
    cout << s1 << " " << s2 << " " << ans << endl;
  }
}

/*
  从testcase文本中获取测试用例字符串对

*/
vector<vector<string>> getStringPairsFromTxt() {
  string path =
      "/Users/messi/Documents/MacBookAir/work/code/cpp/algo/testcase/"
      "stringPairs.txt";
  ifstream out(path.c_str());
  if (!out.is_open()) {
    cerr << ("open file error!") << endl;
    exit(-1);
  }
  vector<vector<string>> stringPairs;
  vector<string> strPair = {"", ""};
  string s1 = "", s2 = "";
  while (getline(out, s1, ' ')) {
    getline(out, s2);
    strPair[0] = s1;
    strPair[1] = s2;
    stringPairs.push_back(strPair);
    // cout << s1 << " " << s2 << endl;
  }
  return stringPairs;
}

vector<string> getStringAnswerFromTxt() {
  string path =
      "/Users/messi/Documents/MacBookAir/work/code/cpp/algo/testcase/"
      "LCS_answer.txt";
  ifstream out(path.c_str());
  if (!out.is_open()) {
    cerr << ("open file error!") << endl;
    exit(-1);
  }
  vector<string> lcs_answer;
  string s = "";
  while (getline(out, s)) {
    lcs_answer.push_back(s);
    // cout << s << endl;
  }
  return lcs_answer;
}
