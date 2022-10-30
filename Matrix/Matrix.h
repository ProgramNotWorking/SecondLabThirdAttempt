#ifndef SECONDLABTHIRDATTEMPT_MATRIX_H
#define SECONDLABTHIRDATTEMPT_MATRIX_H

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Matrix {
private:
    int n;
    int m;
    int** array;
    string menuPoint;

public:
    Matrix(int n, int m, int** array);
    Matrix();
    ~Matrix();
    int getN();
    int getM();
    int** getArray();
    void showMatrix();
    void fillArray(bool isRandom);
    string getMenuPoint();
    void callMenu();
    Matrix& operator=(const Matrix&);
    friend Matrix operator+(Matrix, Matrix);
    friend Matrix operator-(Matrix, Matrix);
    friend Matrix operator*(Matrix, Matrix);

private:
    void doDynamicArray();
    void setMenuPoint();

};


#endif //SECONDLABTHIRDATTEMPT_MATRIX_H
