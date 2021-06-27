#include <sys/time.h>  //clock, gettimeofday, time

#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define ARRAY_SIZE 1000

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};
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