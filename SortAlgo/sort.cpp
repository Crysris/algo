//#include <cstdio>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

#define MAX_NUM 20

int partition(vector<int> &array, int low, int high) {
  int p = low;
  return p;
}
void print_vector(vector<int> array) {
  for (auto iter = array.begin(); iter != array.end(); iter++) {
    cout << *iter << " ";
  }
  cout << endl;
}
//int main() {
//  vector<int> array;
//  srand(time(nullptr));
//
//  for (int i = 0; i < MAX_NUM; i++) {
//    int j = rand() % MAX_NUM;
//    array.push_back(j);
//  }
//  print_vector(array);
//  return 0;
//}
