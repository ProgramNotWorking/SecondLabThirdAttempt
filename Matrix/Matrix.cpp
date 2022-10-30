#include "Matrix.h"

Matrix::Matrix(int n, int m, int **array) {
    this->n = n;
    this->m = m;
    this->array = array;
}

Matrix::Matrix() = default;

Matrix::~Matrix() = default;

int Matrix::getN() { return n; }

int Matrix::getM() { return m; }

string Matrix::getMenuPoint() { return menuPoint; }

int** Matrix::getArray() { return array; }

void Matrix::doDynamicArray() {
    array = new int*[n];
    for (int i = 0; i < n; i++) {
        array[i] = new int[m];
    }
}

void Matrix::fillArray(bool isRandom) {
    doDynamicArray();

    srand(time(nullptr));
    if (isRandom) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                array[i][j] = -10 + rand() % 21;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> array[i][j];
            }
        }
    }
}

void Matrix::showMatrix() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}

void Matrix::setMenuPoint() { getline(cin, menuPoint); }

void Matrix::callMenu() {
    cout << "What u want to do?" << endl;
    cout << "+: add matrix" << endl
         << "-: subtract one matrix from another" << endl
         << "*: multiply matrices" << endl
         << "number: multiply a matrix by a number" << endl;
    setMenuPoint();
}

Matrix &Matrix::operator=(const Matrix &someObj) {
    n = someObj.n;
    m = someObj.m;
    array = someObj.array;

    return *this;
}

Matrix operator+(Matrix firstObj, Matrix secondObj) {
    Matrix temp;

    for (int i = 0; i < firstObj.n; i++) {
        for (int j = 0; j < firstObj.m; j++) {
            temp.array[i][j] = firstObj.array[i][j] + secondObj.array[i][j];
        }
    }

    return temp;
}

Matrix operator-(Matrix firstObj, Matrix secondObj) {
    Matrix temp;

    for (int i = 0; i < firstObj.n; i++) {
        for (int j = 0; j < firstObj.m; j++) {
            temp.array[i][j] = firstObj.array[i][j] - secondObj.array[i][j];
        }
    }

    return temp;
}

Matrix operator*(Matrix firstObj, Matrix secondObj) {
    Matrix temp;

    for (int i = 0; i < firstObj.n; i++) {
        for (int j = 0; j < firstObj.m; j++) {
            for (int k = 0; k < firstObj.n; k++) {
                temp.array[i][j] += firstObj.array[i][k] * secondObj.array[k][j];
            }
        }
    }

    return temp;
}
