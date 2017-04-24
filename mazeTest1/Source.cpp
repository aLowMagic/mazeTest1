//走迷宫算法之显示所有可能路径
#include<iostream>
using namespace std;
void visit(int, int);
int maze[7][7] = { { 2,2,2,2,2,2,2 },
{ 2,0,0,0,0,2,2 },
{ 2,0,2,2,0,2,2 },
{ 2,0,0,0,0,2,2 },
{ 2,0,2,2,0,2,2 },
{ 2,0,2,2,0,0,2 },
{ 2,2,2,2,2,2,2 } };
int endli = 5, endlj = 5;
int main() {
	cout << "显示迷宫：\n";
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			if (maze[i][j] == 2) {
				cout << "□" << '\t';
			}
			else {
				cout << "　" << '\t';
			}
		}
		cout << endl;
	}
	system("pause");
	visit(1, 1);
	system("pause");
}
void visit(int i, int j) {
	maze[i][j] = 1;
	if (i == endli && j == endlj) {
		cout << "显示路径" << endl;
		for (int m = 0; m < 7; m++) {
			for (int n = 0; n < 7; n++) {
				if (maze[m][n] == 2) {
					cout << "□" << '\t';
				}
				else if (maze[m][n] == 1) {
					cout << "◇" << '\t';
				}
				else {
					cout << " " << '\t';
				}
			}
			cout << endl;
		}
	}
	if (maze[i + 1][j] == 0) visit(i + 1, j);
	if (maze[i][j + 1] == 0) visit(i, j + 1);
	if (maze[i][j - 1] == 0) visit(i, j - 1);
	if (maze[i - 1][j] == 0) visit(i - 1, j);
	maze[i][j] = 0;
}