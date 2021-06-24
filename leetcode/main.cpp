#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

void swap(int *&p, int *&q)
{
    int *temp = p;
    p = q;
    q = temp;
}

vector<pair<int, int>> twoSums(vector<int> &nums, int target)
{
    vector<pair<int, int>> ans;
    unordered_map<int, int> index;
    int len = nums.size();
    for (int i = 0; i < len; i++)
        if (index.find(nums[i]) == index.end())
            index[nums[i]] = i;
    for (auto p : index)
    {
        if (p.first >= target / 2)
            continue;

        if (p.first < target / 2)
            if (index.find(target - p.first) != index.end())
                ans.push_back(make_pair(index[p.first], index[target - p.first]));
    }
    return ans;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ans;
    int len = nums.size();
    int flag = 0;
    for (int i = 0; i < len; i++)
    {
        if (nums[i] * 2 == target)
            flag = 1;
    }
    if (flag)
    {
        for (int i = 0; i < len; i++)
        {
            if (nums[i] * 2 == target)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
    unordered_map<int, int> index;
    for (int i = 0; i < len; i++)
        if (index.find(nums[i]) == index.end())
            index[nums[i]] = i;

    for (auto p : index)
    {
        int j = target - p.first;
        if (index.find(target - p.first) != index.end())
        {
            ans.push_back(p.second);
            ans.push_back(index[target - p.first]);
            return ans;
        }
    }
    return ans;
}

void code1()
{

    vector<int> v;
    // sort(v.begin(), v.end());
    unordered_map<int, int> index;
    unordered_map<int, int>::iterator iter;

    for (int i = 0; i < 10; i++)
    {
        v.push_back(i);
    }
    vector<int> ans = twoSum(v, 5);
    for (auto p : ans)
    {
        cout << p << " ";
    }
}

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
}
void code15()
{
}

int main()
{
    // int a = 101, b = 2;
    // int *p = &a, *q = &b;
    // cout << "a , b : " << a << " " << b << endl;

    // (*p)++;
    // cout << "a , b : " << a << " " << b << endl;
    // swap(a, b);
    // cout << "a , b : " << a << " " << b << endl;

    // for (int i = 0; i < 20; i++) {
    //   // iter = index.find(i);
    //   if (index.find(i) == index.end()) index[i] = 2 * i + 3;
    // }
    // for (auto p : index) {
    //   cout << p.first << " " << p.second << endl;
    // }
    return 0;
}