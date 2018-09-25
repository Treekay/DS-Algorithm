/* CCF201604-2 俄罗斯方块 */
 
#include <iostream>
 
const int ROW = 15;
const int COL = 10;
const int N = 4;
 
int board[ROW+1][COL];
int block[N][N];
struct {
    int row, col;
} coords[N];
 
using namespace std;
 
int main() {
    int row, col;
 
    // 输入数据
    for(int i=0; i<ROW; i++)
        for(int j=0; j<COL; j++)
            cin >> board[i][j];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> block[i][j];
    cin >> col;
 
    // 底边全放1
    for(int j=0; j<COL; j++)
        board[ROW][j] = 1;
 
    // 提取小方块坐标
    int k = 0;
    for(int i=N-1; i>=0; i--)
        for(int j=0; j<N; j++)
            if(block[i][j] == 1) {
                coords[k].row = i;
                coords[k].col = j;
                k++;
            }
 
    // 模拟小方块落下过程
    row = 1;
    col--;
    bool checkflag;
    for(;;) {
        checkflag = false;
 
        for(int i=0; i<N; i++)
            if(board[row + coords[i].row][col + coords[i].col] == 1) {
                checkflag = true;
                break;
            }
 
        if(checkflag)
            break;
 
        row++;
    }
    row--;
 
    // 合并小方块到方格
    for(int i=0; i<N; i++)
        board[row + coords[i].row][col + coords[i].col] = 1;
 
    // 输出结果
    for(int i=0; i<ROW; i++) {
        for(int j=0; j<COL; j++) {
            if(j != 0)
                cout << " ";
            cout << board[i][j];
        }
        cout << endl;
    }
 
    return 0;
}
