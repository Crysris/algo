#include "../etc/utils.h"

/*
    快速排序
    划分 点
    a[0],a[1]...a[p-1],a[p],a[p+1]....a[len-1]
    if i<p,a[i]<[p]

    j左边的数都比array[j]小
*/
int partition(vector<int> &array, int lo, int hi) {
  int j = lo - 1;
  while (lo < hi) {
    if (array[lo] < array[hi]) {
      j++;
      swap(array[j], array[lo]);
    }
    lo++;
  }
  j++;
  swap(array[j], array[hi]);
  return j;
}
void quickSort(vector<int> &array, int lo, int hi) {
  if (lo >= hi) return;
  int p = partition(array, lo, hi);
  quickSort(array, lo, p - 1);
  quickSort(array, p + 1, hi);
}
void quickSort(vector<int> &array) { quickSort(array, 0, array.size() - 1); }

void code_qucikSort() {
  srand(time(nullptr));
  vector<int> a(ARRAY_SIZE);
  for (int i = 0; i < ARRAY_SIZE; i++) {
    a[i] = rand() % ARRAY_SIZE;
  }
  printVector(a);
  quickSort(a);
  printVector(a);
}

void testArrayPointer(int *a, int n) {
  for (int i = 0; i < n; i++) {
    a[i] = n - i;
  }
}

int main() {
  int n = 10;
  int a[n];
  for (int i = 0; i < n; i++) a[i] = i + 1;
  printArray(a, n);
  testArrayPointer(a, n);
  printArray(a, n);
  return 0;
}