/*********************************
 * Автор:    Хан Кирилл           *
 * Задание:  Обработка массивов   *
 * Вариант:  26                   *
 *********************************/

#include <iostream>

using namespace std;

int main() {
  const int maxSize = 20;
  double matrix[maxSize][maxSize];
  int orderedRowIndexes[maxSize];
  int rowCount, columnCount, selectedRowIndex;
  int ascendingPairCount, descendingPairCount;
  int orderedRowCount = 0;
  double maximum = 0.0;

  cout << "Rows and columns (1-20): ";
  if (!(cin >> rowCount >> columnCount) || rowCount < 1 || rowCount > maxSize || columnCount < 1 || columnCount > maxSize) {
    cout << "INVALID";
    return 1;
  }
  cout << "Enter matrix row by row:" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
      if (!(cin >> matrix[rowIndex][columnIndex])) {
        cout << "INVALID";
        return 1;
      }
    }
  }

  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    ascendingPairCount = 0;
    descendingPairCount = 0;
    for (int columnIndex = 1; columnIndex < columnCount; ++columnIndex) {
      if (matrix[rowIndex][columnIndex] >= matrix[rowIndex][columnIndex - 1]) {
        ++ascendingPairCount;
      }
      if (matrix[rowIndex][columnIndex] <= matrix[rowIndex][columnIndex - 1]) {
        ++descendingPairCount;
      }
    }
    if (ascendingPairCount == columnCount - 1 || descendingPairCount == columnCount - 1) {
      if (orderedRowCount == 0) {
        maximum = matrix[rowIndex][0];
      }
      for (int columnIndex = 0; columnIndex < columnCount; ++columnIndex) {
        if (matrix[rowIndex][columnIndex] > maximum) {
          maximum = matrix[rowIndex][columnIndex];
        }
      }
      orderedRowIndexes[orderedRowCount] = rowIndex;
      ++orderedRowCount;
    }
  }

  cout << "Original matrix:" << endl;
  for (int rowIndex = 0; rowIndex < rowCount; ++rowIndex) {
    cout << matrix[rowIndex][0];
    for (int columnIndex = 1; columnIndex < columnCount; ++columnIndex) {
      cout << " " << matrix[rowIndex][columnIndex];
    }
    cout << endl;
  }
  cout << "Ordered rows:" << endl;
  for (int orderedRowIndex = 0; orderedRowIndex < orderedRowCount; ++orderedRowIndex) {
    selectedRowIndex = orderedRowIndexes[orderedRowIndex];
    cout << matrix[selectedRowIndex][0];
    for (int columnIndex = 1; columnIndex < columnCount; ++columnIndex) {
      cout << " " << matrix[selectedRowIndex][columnIndex];
    }
    cout << endl;
  }
  if (orderedRowCount > 0) {
    cout << "Maximum: " << maximum;
  } else {
    cout << "NONE" << endl << "Maximum: NONE";
  }

  return 0;
}
