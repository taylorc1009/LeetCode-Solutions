#include <iostream>
#include <vector>

bool boardIsValidSoFar(const int lastPlacedRow, const std::vector<int>& __restrict gameBoard) {
    const int lastPlacedColumn = gameBoard[lastPlacedRow];

    for (int row = 0; row < lastPlacedRow; row++)
        if (gameBoard[row] == lastPlacedColumn ||
            gameBoard[row] == lastPlacedColumn - (lastPlacedRow - row) ||
            gameBoard[row] == lastPlacedColumn + (lastPlacedRow - row))
            return false;

    return true;
}

void calculateSolutionsRecursive(const int writeToRow, std::vector<int>& __restrict gameBoard, const int n, int& __restrict solutions) {
    for (int i = 0; i < n; i++) {
        gameBoard[writeToRow] = i;

        if (boardIsValidSoFar(writeToRow, gameBoard)) {
            const int nextWriteToRow = writeToRow + 1;

            if (nextWriteToRow != n)
                calculateSolutionsRecursive(nextWriteToRow, gameBoard, n, solutions);
            else
                solutions++;
        }
    }
}

int totalNQueens(int n) {
    std::vector<int> gameBoard(n, 0);
    int solutions = 0;

    calculateSolutionsRecursive(0, gameBoard, n, solutions);

    return solutions;
}

int main(int argc, char** argv) {
    const int n = 4;

    std::cout << totalNQueens(n) << std::endl;
}