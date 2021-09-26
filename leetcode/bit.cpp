#include "../etc/utils.h"

/*
leetcode 191. Number of 1 Bits
lowbit(x)，返回二进制表达中最后一个1
x=4,  0110
-x,   1010
*/
int lowbit(int x) { return x & (-x); }
int countOfbit1(int x) {
  int count = 0;
  while (x) {
    x = x & (x - 1);
    count++;
  }
  return count;
}
int countOfbit1(uint32_t x)  // x 	 	1011
{                            // x-1	1010
  int count = 0;
  while (x) {
    x = x & (x - 1);
    count++;
  }
  return count;
}
int bitDis(int x) {
  int count = 0;
  while ((x & 1) == 0) {
    count++;
    x = x >> 1;
  }
  return count;
}

/*
leetcode 51
打印棋盘
n皇后 回溯法
第i行，第j列
col[j]=lCross[i+j]=rCross[n-j+i-1]=1
*/
void mapNQueens(int row, int *col, int *lCross, int *rCross, int n,
                vector<string> board, vector<vector<string>> &ans) {
  if (row == n) {
    ans.push_back(board);
    return;
  }
  for (int j = 0; j < n; j++) {
    if ((!col[j]) && (!lCross[row + j]) && (!rCross[n - j + row - 1])) {
      col[j] = lCross[row + j] = rCross[n - j + row - 1] = 1;
      board[row][j] = 'Q';
      mapNQueens(row + 1, col, lCross, rCross, n, board, ans);
      board[row][j] = '.';
      col[j] = lCross[row + j] = rCross[n - j + row - 1] = 0;
    }
  }
}
vector<vector<string>> mapNQueens(int n) {
  vector<vector<string>> ans;
  string s;
  for (int i = 0; i < n; i++) s.push_back('.');
  vector<string> board(n, s);
  int col[n], lCross[2 * n], rCross[2 * n];
  memset(col, 0, sizeof(col));
  memset(lCross, 0, sizeof(lCross));
  memset(rCross, 0, sizeof(rCross));
  mapNQueens(0, col, lCross, rCross, n, board, ans);
  return ans;
}
void printStringVectors(vector<vector<string>> ans, int n) {
  for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < n; j++) {
      cout << ans[i][j] << endl;
    }
    cout << endl;
  }
}
void code_solveNQueens() {
  int n = 8;
  vector<vector<string>> ans = mapNQueens(n);
  printStringVectors(ans, n);
}
/*
  leetcode 52
  n皇后 回溯法
  第i行，第j列
  col[j]=lCross[i+j]=rCross[n-j+i-1]=1

*/
void nQueen(int row, int *col, int *lCross, int *rCross, int n, int &ans) {
  if (row == n) {
    ans++;
    return;
  }
  for (int j = 0; j < n; j++) {
    if ((!col[j]) && (!lCross[row + j]) && (!rCross[n - j + row - 1])) {
      col[j] = lCross[row + j] = rCross[n - j + row - 1] = 1;
      nQueen(row + 1, col, lCross, rCross, n, ans);
      col[j] = lCross[row + j] = rCross[n - j + row - 1] = 0;
    }
  }
}
int nQueen(int n) {
  int col[n], lCross[2 * n], rCross[2 * n];
  memset(col, 0, sizeof(col));
  memset(lCross, 0, sizeof(lCross));
  memset(rCross, 0, sizeof(rCross));
  int ans = 0;
  nQueen(0, col, lCross, rCross, n, ans);
  return ans;
}

void code_nQueen_1() {
  clock_t startTime = clock();

  for (int i = 1; i <= 15; i++) {
    int ans = nQueen(i);
    cout << ans << " ";
  }
  cout << endl;
  clock_t endTime = clock();
  clock_t elapsed = endTime - startTime;
  double elapsed_time = double(elapsed / CLOCKS_PER_SEC);
  cout << "TIME cost : " << setprecision(6) << fixed << elapsed_time << "s"
       << endl;
}

/*
位运算解决n皇后问题
*/
void bitNQueen(int col, int ld, int rd, int limit, int &ans) {
  if (col == limit)
    ans++;
  else {
    int pos = limit & ~(col | ld | rd);
    while (pos) {
      int p = pos & (-pos);
      pos ^= p;
      bitNQueen(col | p, (ld | p) << 1, (rd | p) >> 1, limit, ans);
    }
  }
}
int totalNQueens(int n) {
  int ans = 0;
  bitNQueen(0, 0, 0, (1 << n) - 1, ans);
  return ans;
}

void code_nQueen() {
  int ans;
  clock_t startTime = clock();

  for (int i = 1; i <= 15; i++) {
    ans = totalNQueens(i);
    cout << ans << " ";
  }
  cout << endl;
  // this_thread::sleep_for(chrono::milliseconds(1000));
  clock_t endTime = clock();
  clock_t elapsed = endTime - startTime;
  double elapsed_time = double(elapsed / CLOCKS_PER_SEC);
  cout << "TIME cost : " << setprecision(6) << fixed << elapsed_time << "s"
       << endl;
  // for (int i = 1; i <= 16; i++) {
  //   clock_t startTime = clock();
  //   ans = totalNQueens(i);
  //   clock_t endTime = clock();
  //   clock_t elapsed = endTime - startTime;
  //   double elapsed_time = double(elapsed / CLOCKS_PER_SEC);
  //   cout << i << " queen : " << ans << " ,TIME cost : " << setprecision(6)
  //        << fixed << elapsed_time << "s" << endl;
  // }
}

/*
leetcode 51
皇后 棋盘
*/
void bitMapNQueen(int n, int row, int col, int ld, int rd, int limit,
                  vector<vector<string>> &ans, vector<string> board) {
  if (col == limit)
    ans.push_back(board);
  else {
    int pos = limit & (~(col | ld | rd));
    while (pos) {
      int p = pos & (-pos);
      pos ^= p;
      int dis = bitDis(p);
      board[row][n - 1 - dis] = 'Q';
      bitMapNQueen(n, row + 1, col | p, (ld | p) << 1, (rd | p) >> 1, limit,
                   ans, board);
      board[row][n - 1 - dis] = '.';
    }
  }
}
vector<vector<string>> bitMapNQueen(int n) {
  vector<vector<string>> ans;
  string s;
  for (int i = 0; i < n; i++) s.push_back('.');
  vector<string> board(n, s);
  bitMapNQueen(n, 0, 0, 0, 0, (1 << n) - 1, ans, board);
  return ans;
}
void code_bitMapNQueen() {
  int n = 13;
  vector<vector<string>> ans = bitMapNQueen(n);
  printStringVectors(ans, n);
}

/*
  1000个瓶，1个装有毒，999个装有水，10只小白鼠，无限多试管，找出装有毒药那瓶
  1024= 1   0  0  0  0  0  0  0  0  0  0
       [10  9  8  7  6  5  4  3  2  1  0]
  1000 =0   1  1  1  1  1  0  1  0  0  0
       [10  9  8  7  6  5  4  3  2  1  0]
  #####设装有毒药的试管编号为X######
  轮数ROUND=1 ，每部分瓶子数M=500
  1.将待测所有瓶子编号，1-1000，并分成2部分 A:1-500，B:501-1000，
  2.取2支试管A1、B1，分别在A、B中所有瓶中取少量液体加入A1、B1中
  3.取一只小白鼠用A1进行实验，若小白鼠死亡则用A1进入下一轮,否则用B1进入下一轮
  4.若M=1，则找出装有毒药的试管
*/

int findPosion(vector<int>sample){
  
}

void codePoison(){
  vector<int> sample(1001,0);
  srand(time(nullptr));
  int X=rand()%1001+1;//[1,1000];
  sample[X]=1;

}



int main() {
  /*clock_t startTime = clock();

  //===== 计算时间
  code_nQueen();
  //=====
  clock_t endTime = clock();
  clock_t elapsed = endTime - startTime;
  double elapsed_time = double(elapsed / CLOCKS_PER_SEC);
  cout << "TIME cost : " << setprecision(6) << fixed << elapsed_time << "s"
       << endl;
  */
  uint64_t p = 1;
  p = (p << 32) - 1;
  cout << p;
  uint32_t n;
  return 0;
}
