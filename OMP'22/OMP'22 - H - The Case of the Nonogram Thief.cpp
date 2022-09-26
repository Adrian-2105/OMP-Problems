#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> rows;
vector<vector<int>> cols;
vector<vector<bool>> M;
bool finish = false;

bool checkColumn(int maxRow, int j) {
    int i = 0;
    for (int k = 0; k < cols[j].size(); k++) {
        // skip white spaces before the start of the "object"
        for (; i < maxRow && M[i][j] == false; i++);
        // because it's only partial checking, if we reach now the end it's okay
        if (i == maxRow && maxRow != n) 
            return true;

        // count how many boxes has the current object
        int cont = 0;
        for (; i < maxRow && M[i][j] == true; i++, cont++);
        if (not ((cont <= cols[j][k] && i == maxRow && maxRow != n) || (cont == cols[j][k])))
            return false;
    }

    // after finishing iterate all objects, remaining boxes should be blank
    for (; i < n; i++) {
        if (M[i][j] == true)
            return false;
    }

    return true;
}

void setRow(int row, int start, int len, bool val) {
    for (int j = start; j < start + len && j < n; j++) {
        M[row][j] = val;
    }
}

void printSol() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!M[i][j]) cout << ".";
            else cout << "X";
        }
        cout << endl;
    }
}

void backtracking(int row, int col, int k) {
    // if reached outside the matrix, then all values has been
    // probeb that are okay
    if (row >= n) {
        printSol();
        finish = true;
        return;
    }
    // if all elements of this row are set, then go to the next row
    if (k >= rows[row].size()) {
        backtracking(row+1, 0, 0);
        return;
    }

    // calculate the minimum boxes do you need to put the remaining values of this row
    int remaining = rows[row].size() - (k+1);
    for (int l = k; l < rows[row].size(); l++)
        remaining += rows[row][l];

    // try to put the current "object" starting in every column
    for (int j = col; j < n; j++) {
        // if there is no enough space for the rest of the "objects" of the row,
        // then just give up
        if (remaining + j > n)
            break;

        // set boxes of the current object on the matrix
        setRow(row, j, rows[row][k], true);

        // check for every changed column if the new value is okay
        // if not, then just go to the next iteration
        bool good = true;
        for (int checkJ = j; checkJ < j + rows[row][k] && good; checkJ++) {
            if (checkColumn(row+1, checkJ) == false) {
                good = false;
            }
        }

        // advance to put the next element on the row
        if (good) {
            backtracking(row, j + rows[row][k] + 1, k + 1);
            if (finish) return;
        }

        // clean the boxes of this iteration to prepare it for the next one
        setRow(row, j, rows[row][k], false);
    }
}

int main() {
    // read input
    cin >> n;
    // rows
    for (int i = 0; i < n; i++) {
        int k, x;
        cin >> k;
        rows.push_back(vector<int>());
        for (int j = 0; j < k; j++) {
            cin >> x;
            if (x != 0)
                rows[i].push_back(x);
        }
    }
    // columns
    for (int i = 0; i < n; i++) {
        int k, x;
        cin >> k;
        cols.push_back(vector<int>());
        for (int j = 0; j < k; j++) {
            cin >> x;
            if (x != 0)
                cols[i].push_back(x);
        }
    }

    // initialize matrix
    for (int i = 0; i < n; i++) {
        M.push_back(vector<bool>(n, false));
    }

    backtracking(0, 0, 0);
}