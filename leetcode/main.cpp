#include "../etc/utils.h"

void swap(int *&p, int *&q)
{
    int *temp = p;
    p = q;
    q = temp;
}
/*=======================================================================================
     leetcode1. two sums
*/
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

/*=======================================================================================
     leetcode10. Regular Expression Matching
*/
bool isMatch(string s, string p) {
	stack<char> regex_stack;
	int i=0,j=0;
	char pre_char;
	int n=s.size(),m=p.size();
	while(true){
		if(p[j]=='.'){

		}
		else if(p[j]=='*'){

		}
		else{
			if(s[i]!=p[j])return false;
			i++;
			j++;
		}
		pre_char=p[j];
		
	}
}

void code10(){
	isMatch("aaabbabaa","a*b*.b*a*");
}



/*=======================================================================================
     leetcode15. three sums
*/
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> ans;
}
void code15()
{
}
/*=======================================================================================
     leetcode41. firstMissingPositive
*/
int firstMissingPositive(vector<int>& nums) {
    int MAX_SIZE=5e+5;
    vector<bool>mark(MAX_SIZE+1,false);
    for(auto p:nums){
        if(p<=MAX_SIZE&&p>0)mark[p]=true;
    }
    for(int i=1;i<=MAX_SIZE;i++){
        if(mark[i]==false)return i;
    }
    return MAX_SIZE+1;
}
void code41(){

}
/*
    欧拉线性筛法求素数个数
    将合数分解为 最小质因子*另一个数
    根据最小质因子来决定一个数有没有被筛过
*/

int primeNumber(int n){
    vector<int>prime(n+1,0);
    vector<bool>mark(n+1,false);
    int primeNum=0;
    for(int i=2;i<=n;i++){
        if(mark[i]==false){
            // 标记素数
            prime[primeNum++]=i;
        }
        for(int j=0;j<primeNum;j++){
            if(i*prime[j]>n)break;
            mark[i*prime[j]]=true;
            if(i%prime[j]==0)break;
        }
    }
    return primeNum;
}
void codeEuler(){
    cout<<primeNumber(10);
}



/*=======================================================================================
     leetcode442. Find All Duplicates in an Array
     每个数字出现1或2次，负号标记法 !!!!!!!!!!!
*/
vector<int> findDuplicates(vector<int>& nums) {
    vector<int>ans;
    int abs_p;
    for(auto p:nums){
        abs_p=abs(p);
        if(nums[abs_p-1]<0)
            ans.push_back(abs_p);
        else
            nums[abs_p-1]*=-1;
    }    
    
    return ans;
}
void code442(){
    vector<int> a={2,3,5,2,3,5,6,7,8,7,6,1,10,12,1};
    findDuplicates(a);
}

/*=======================================================================================
     leetcode448. Find All Numbers Disappeared in an Array
*/
// time:0(n) ,space:0(n)
vector<int> findDisappearedNumbers_2(vector<int>& nums) {
    int n=nums.size();
    vector<int>mark(n+1,0);
    vector<int>ans;
    for(auto p:nums){
        mark[p]=1;
    }
    for(int i=1;i<=n;i++){
        if(mark[i]==0)
            ans.push_back(i);
    }
    return ans;
}
// time:0(nlog(n)) ,space:0(1)
vector<int> findDisappearedNumbers_1(vector<int>& nums) {
    int n=nums.size();
    vector<int>ans;
    sort(nums.begin(),nums.end());
    int i=1,j=1;
    if(nums[0]>1){
        for(int k=1;k<nums[0];k++){
            ans.push_back(k);
        }
    }
    while(i<n){
        if(nums[i]==nums[i-1]){
            i++;
        }
        else{
            // if()
        }
    }
    return ans;
}
vector<int> findDisappearedNumbers(vector<int>& nums) {
    int ans=0;
    for(auto p:nums){

    }
}
void code448(){
    vector<int>a={1,2,3,3,2};
    findDisappearedNumbers_1(a);
}

int partition(vector<int> &nums,int lo,int hi){
	int j=lo-1;
	while(lo<hi){
		if(nums[lo]<=nums[hi]){
			j++;
			swap(nums[j],nums[lo]);
		}
		lo++;
	}
	j++;
	swap(nums[j],nums[hi]);
	return j;
}
void quickSort(vector<int> &nums,int lo,int hi){
	if(lo>=hi)return ;
	int p=partition(nums,lo,hi);
	quickSort(nums,lo,p-1);
	quickSort(nums,p+1,hi);
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
    // code442();
    vector<int> a={3,9,6,3,7,8,4,1,7,2,5,8};
    quickSort(a,0,a.size()-1);
    return 0;
}