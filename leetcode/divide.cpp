#include "../etc/utils.h"

/* 
    return 第k大的数
    ====  快排的思想  分治=====
*/
int partition(vector<int> &array, int lo, int hi)
{
    int j = lo - 1;
    while (lo < hi)
    {
        if (array[lo] < array[hi])
        {
            j++;
            swap(array[j], array[lo]);
        }
        lo++;
    }
    j++;
    swap(array[j], array[hi]);
    return j;
}
int quickKSelect(vector<int> &array, int lo, int hi, int k)
{
    int p = partition(array, lo, hi);
    if (k == p + 1)
        return array[p];
    if (k < p + 1)
        return quickKSelect(array, lo, p - 1, k);
    else
        return quickKSelect(array, p + 1, hi, k);
}
int quickKSelect(vector<int> &array, int k)
{
    return quickKSelect(array, 0, array.size() - 1, k);
}

void code_quickKSelect()
{
    srand(time(nullptr));
    // vector<int> a{4, 4, 4, 4, 4};
    vector<int> a(ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        a[i] = rand() % ARRAY_SIZE;
    }
    printVector(a);
    for (int i = 1; i <= ARRAY_SIZE; i++)
    {
        // printVector(a);
        int p = quickKSelect(a, i);
        cout << p << " ";
    }
    cout << endl;
    sort(a.begin(), a.begin() + a.size());
    printVector(a);
}
int main()
{
    code_quickKSelect();
    return 0;
}