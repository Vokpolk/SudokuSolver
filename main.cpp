#include <iostream>
#include <vector>
using namespace std;

bool isNumFreeInRow(int& num, int arr[9][9], int row) {
	for (int i = 0; i < 9; i++) {
		if (arr[row][i] == num) {
			return false;
		}
	}
	return true;
}

bool isNumFreeInCol(int& num, int arr[9][9], int col) {
	for (int i = 0; i < 9; i++) {
		if (arr[i][col] == num) {
			return false;
		}
	}
	return true;
}

bool isNumFreeInBox(int& num, int arr[9][9], int row, int col) {
	int tempRow, tempCol = 0;

	if (row < 3)		tempRow = 0;
	else if (row < 6)	tempRow = 1;
	else				tempRow = 2;

	if (col < 3)		tempCol = 0;
	else if (col < 6)	tempCol = 1;
	else				tempCol = 2;

	for (int i = 0 + 3 * tempRow; i < 3 + 3 * tempRow; i++)
		for (int j = 0 + 3 * tempCol; j < 3 + 3 * tempCol; j++)
			if (arr[i][j] == num)
				return false;
	return true;
}


int main()
{
	int sudoku[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
						{6, 0, 0, 1, 9, 5, 0, 0, 0},
						{0, 9, 8, 0, 0, 0, 0, 6, 0},
						{8, 0, 0, 0, 6, 0, 0, 0, 3},
						{4, 0, 0, 8, 0, 3, 0, 0, 1},
						{7, 0, 0, 0, 2, 0, 0, 0, 6},
						{0, 6, 0, 0, 0, 0, 2, 8, 0},
						{0, 0, 0, 4, 1, 9, 0, 0, 5},
						{0, 0, 0, 0, 8, 0, 0, 7, 9}};

	int a = 7;
	cout << isNumFreeInRow(a, sudoku, 0) << endl;
	cout << isNumFreeInCol(a, sudoku, 0) << endl;
	cout << isNumFreeInBox(a, sudoku, 0, 0) << endl;

	return 0;
}