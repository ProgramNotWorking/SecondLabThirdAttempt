#include <iostream>
#include "Matrix/Matrix.h"

using namespace std;

void fillArray(int n, int m, int** array);
bool randomFilling();
void test(int n, int m, int** array);

int main() {
    int n, m;
    cout << "Enter number of columns: ";
    cin >> n;
    cout << "Enter number of lines: ";
    cin >> m;

    int** firstArray = new int* [n];
    int** secondArray = new int* [n];
    int** resultArray = new int* [n];
    for (int i =0 ; i < n; i++) {
        firstArray[i] = new int[m];
        secondArray[i] = new int[m];
        resultArray[i] = new int[m];
    }
    fillArray(n, m, firstArray);
    fillArray(n, m, secondArray);
    fillArray(n, m, resultArray);

    Matrix firstMatrix(n, m, firstArray);
    Matrix secondMatrix(n, m, secondArray);
    Matrix resultMatrix(n, m, resultArray);

    bool isRandom = randomFilling();
    firstMatrix.fillArray(isRandom);
//    firstMatrix.showMatrix();
    secondMatrix.fillArray(isRandom);
//    secondMatrix.showMatrix();

    firstMatrix.callMenu();
    if (firstMatrix.getMenuPoint() == "+") {
        resultMatrix = firstMatrix + secondMatrix;
        resultMatrix.showMatrix();
    } else if (firstMatrix.getMenuPoint() == "-") {
        resultMatrix = firstMatrix - secondMatrix;
        resultMatrix.showMatrix();
    } else if (firstMatrix.getMenuPoint() == "*") {
        resultMatrix = firstMatrix * secondMatrix;
        resultMatrix.showMatrix();
    } else {
        cout << "Incorrect input data" << endl;
    }

}

void fillArray(int n, int m, int** array) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            array[i][j] = 0;
        }
    }
}

bool randomFilling() {
    string tempString;

    cout << "Do u want fill ur matrix randomly?" << endl;
    getline(cin, tempString);

    if (tempString == "yes" || tempString == "Yes") {
        return true;
    } else {
        return false;
    }
}

void test(int n, int m, int** array) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}
