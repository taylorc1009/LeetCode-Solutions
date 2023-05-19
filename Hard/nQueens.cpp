#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> getSolutionString(const std::vector<int>& __restrict gameBoard) {
    const int n = gameBoard.size();
    std::vector<std::string> solution(n, std::string(n, '.'));

    for (int i = 0; i < n; i++)
        solution[i][gameBoard[i]] = 'Q';

    return solution;
}

bool boardIsValidSoFar(int lastPlacedRow, const std::vector<int>& __restrict gameBoard) {
    const int lastPlacedColumn = gameBoard[lastPlacedRow];

    for (int row = 0; row < lastPlacedRow; row++)
        if (gameBoard[row] == lastPlacedColumn ||
            gameBoard[row] == lastPlacedColumn - (lastPlacedRow - row) ||
            gameBoard[row] == lastPlacedColumn + (lastPlacedRow - row))
            return false;

    return true;
}

void calculateSolutionsRecursive(int writeToRow, std::vector<int>& __restrict gameBoard, int n, std::vector<std::vector<std::string>>& __restrict solutions) {
    for (int i = 0; i < n; i++) {
        gameBoard[writeToRow] = i;

        if (boardIsValidSoFar(writeToRow, gameBoard)) {
            const int nextWriteToRow = writeToRow + 1;

            if (nextWriteToRow != n)
                calculateSolutionsRecursive(nextWriteToRow, gameBoard, n, solutions);
            else
                solutions.push_back(getSolutionString(gameBoard));
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::vector<std::vector<std::string>> solutions;
    std::vector<int> gameBoard(n, 0);

    calculateSolutionsRecursive(0, gameBoard, n, solutions);

    return solutions;
}

int main(int argc, char** argv) {
    int n = 4;

    std::vector<std::vector<std::string>> solutions = solveNQueens(n);

    std::cout << solutions.size() << std::endl << std::endl;
    for (std::vector<std::string> solution : solutions) {
        for (std::string str : solution)
            std::cout << str << std::endl;
        std::cout << std::endl;
    }
}