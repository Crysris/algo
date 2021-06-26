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
#include <sys/time.h> //clock, gettimeofday, time
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

#define ARRAY_SIZE 1000

void printVector(vector<int> array)
{
    for (auto p : array)
    {
        cout << p << " ";
    }
    cout << endl;
}