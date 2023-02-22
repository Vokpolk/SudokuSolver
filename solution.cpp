#include "solution.h"

void CSudoku::extractSudokuFile() {
	ifstream in("sud.txt");

	if (in.is_open()) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				in >> arr[i][j];
			}
		}
		in.close();
	} else {
		cout << "File is missing." << endl;
	}
}

void CSudoku::createSudokuFile() {
	ofstream out("res.txt");

	if (out.is_open()) {
		out << "Result:\n\n";
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				out << arr[i][j] << " ";
			}
			out << endl;
		}
		out.close();
	}
}

bool CSudoku::isNumFreeInRow(int num, int row) {
    for (int i = 0; i < 9; i++) {
        if (arr[row][i] == num) {
            return false;
        }
    }
    return true;
}

bool CSudoku::isNumFreeInCol(int num, int col) {
    for (int i = 0; i < 9; i++) {
        if (arr[i][col] == num) {
            return false;
        }
    }
    return true;
}

bool CSudoku::isNumFreeInBox(int num, int row, int col) {
    int tempRow, tempCol = 0;

    if (row < 3)        tempRow = 0;
    else if (row < 6)    tempRow = 1;
    else                tempRow = 2;

    if (col < 3)        tempCol = 0;
    else if (col < 6)    tempCol = 1;
    else                tempCol = 2;

    for (int i = 0 + 3 * tempRow; i < 3 + 3 * tempRow; i++)
        for (int j = 0 + 3 * tempCol; j < 3 + 3 * tempCol; j++)
            if (arr[i][j] == num)
                return false;
    return true;
}

bool CSudoku::isNumMissing(int& row, int& col) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] == 0) {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool CSudoku::isNumFits(int num, int row, int col) {
 	return (isNumFreeInRow(num, row) && isNumFreeInCol(num, col) && isNumFreeInBox(num, row, col));
}


bool CSudoku::solution() {
    int row, col;

    if (!isNumMissing(row, col)) {
        return true;
    }

    for (int i = 1; i <= 9; i++) {
        if (isNumFits(i, row, col)) {
            arr[row][col] = i;
            if (solution()) {
                return true;
            }
            arr[row][col] = 0;
        }
    }
    return false;
}

/*int main()
{
	extractSudokuFile();
    if (solution()) {
        cout << "Solution is in \"res.txt\" file" << endl;
        createSudokuFile();
    } else {
        cout << "No solution!" << endl;
    }

    return 0;
}*/
