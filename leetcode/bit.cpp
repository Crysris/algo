#include "../etc/utils.h"

/*

位运算解决n皇后问题


*/
void foo(int col, int ld, int rd, int limit, int &ans)
{
    if (col == limit)
        ans++;
    else
    {
        int pos = limit & ~(col | ld | rd);
        while (pos)
        {
            int p = pos & (-pos);
            pos ^= p;
            foo(col | p, (ld | p) << 1, (rd | p) >> 1, limit, ans);
        }
    }
}
int totalNQueens(int n)
{
    int ans = 0;
    foo(0, 0, 0, (1 << n) - 1, ans);
    return ans;
}
void nQueen(int i, int col, int lCross, int rCross, int n)
{
}
int qQueen(int n)
{
    return 1;
}
void code_nQueen()
{
    int ans;
    for (int i = 2; i <= 16; i++)
    {
        clock_t startTime = clock();
        ans = totalNQueens(i);
        clock_t endTime = clock();
        clock_t elapsed = endTime - startTime;
        double elapsed_time = double(elapsed / CLOCKS_PER_SEC);
        cout << i << " queen : " << ans << " ,TIME cost : " << setprecision(6) << fixed << elapsed_time << "s" << endl;
    }
    clock_t startTime = clock();
    this_thread::sleep_for(chrono::milliseconds(1000));
    clock_t endTime = clock();
    clock_t elapsed = (endTime - startTime);
    double elapsed_time = double(elapsed / CLOCKS_PER_SEC);
    cout << "sleep TIME : " << setprecision(6) << fixed << elapsed_time << "s" << endl;
}
int countOfbit1(int x)
{
    int count = 0;
    while (x > 0)
    {
        count += x & 1;
        x >>= 1;
    }
    return count;
}

int main()
{
    // code_nQueen();
    countOfbit1(1024);
    return 0;
}
