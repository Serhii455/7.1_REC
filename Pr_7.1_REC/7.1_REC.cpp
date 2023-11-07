#include <iostream>
#include <iomanip>

using namespace std;

void PrintZ(int** Z, const int rowCount, const int colCount, int i = 0, int j = 0) {
    if (i >= rowCount) {
        cout << endl;
        return;
    }

    cout << setw(4) << Z[i][j];

    if (j < colCount - 1) {
        PrintZ(Z, rowCount, colCount, i, j + 1);
    }
    else {
        cout << endl;
        PrintZ(Z, rowCount, colCount, i + 1, 0);
    }
}

void ValueZ(int** Z, const int rowCount, const int colCount, const int Low, const int High, int i = 0, int j = 0) {
    if (i >= rowCount) {
        return;
    }

    Z[i][j] = Low + rand() % (High - Low + 1);

    if (j < colCount - 1) {
        ValueZ(Z, rowCount, colCount, Low, High, i, j + 1);
    }
    else {
        ValueZ(Z, rowCount, colCount, Low, High, i + 1, 0);
    }
}

int Numerosity(int** Z, const int rowCount, const int colCount, int i = 0, int j = 0) {
    if (i >= rowCount) {
        return 0;
    }

    int count = 0;
    if (Z[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0)) {
        count = 1;
    }

    if (j < colCount - 1) {
        count += Numerosity(Z, rowCount, colCount, i, j + 1);
    }
    else {
        count += Numerosity(Z, rowCount, colCount, i + 1, 0);
    }

    return count;
}

int Sum(int** Z, const int rowCount, const int colCount, int i = 0, int j = 0) {
    if (i >= rowCount) {
        return 0;
    }

    int sum = 0;
    if (Z[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0)) {
        sum = Z[i][j];
    }

    if (j < colCount - 1) {
        sum += Sum(Z, rowCount, colCount, i, j + 1);
    }
    else {
        sum += Sum(Z, rowCount, colCount, i + 1, 0);
    }

    return sum;
}

void Change(int** Z, const int col1, const int col2, const int rowCount, int j = 0) {
    if (j >= rowCount) {
        return;
    }

    int tmp = Z[j][col1];
    Z[j][col1] = Z[j][col2];
    Z[j][col2] = tmp;

    Change(Z, col1, col2, rowCount, j + 1);
}

void Sort(int** Z, const int rowCount, const int colCount, int j0 = 0) {
    if (j0 >= colCount - 1) {
        return;
    }

    for (int j1 = 0; j1 < colCount - j0 - 1; j1++) {
        if (Z[0][j1] < Z[0][j1 + 1]
            || (Z[0][j1] == Z[0][j1 + 1] && Z[1][j1] + Z[1][j1] < Z[1][j1 + 1])) {
            Change(Z, j1, j1 + 1, rowCount);
        }
    }

    Sort(Z, rowCount, colCount, j0 + 1);
}

void PrintZ_Modificated(int** Z, const int rowCount, const int colCount, int i = 0, int j = 0) {
    if (i >= rowCount) {
        cout << endl;
        return;
    }

    if (Z[i][j] % 2 == 0 && !(i % 2 != 0 || j % 2 != 0)) {
        Z[i][j] = 0;
    }
    cout << setw(4) << Z[i][j];

    if (j < colCount - 1) {
        PrintZ_Modificated(Z, rowCount, colCount, i, j + 1);
    }
    else {
        cout << endl;
        PrintZ_Modificated(Z, rowCount, colCount, i + 1, 0);
    }
}

void PrintSortMatrix(int** Z, const int rowCount, const int colCount, int i = 0, int j = 0) {
    if (i >= rowCount) {
        cout << endl;
        return;
    }

    cout << setw(4) << Z[i][j];

    if (j < colCount - 1) {
        PrintSortMatrix(Z, rowCount, colCount, i, j + 1);
    }
    else {
        cout << endl;
        PrintSortMatrix(Z, rowCount, colCount, i + 1, 0);
    }
}

int main() {
    const int rowCount = 9;
    const int colCount = 7;

    int Low = 4;
    int High = 45;
    int col1 = 0;
    int col2 = 1;

    int** Z = new int* [rowCount];
    for (int i = 0; i < rowCount; i++)
        Z[i] = new int[colCount];

    ValueZ(Z, rowCount, colCount, Low, High);

    cout << "Matrix:" << endl;
    PrintZ(Z, rowCount, colCount);
    cout << setw(4) << endl;

    int numerosityResult = Numerosity(Z, rowCount, colCount);
    cout << "Numerosity = " << numerosityResult << endl;

    int sumResult = Sum(Z, rowCount, colCount);
    cout << "Sum = " << sumResult << endl;
    cout << setw(4) << endl;
    cout << setw(4) << endl;

    cout << "Sort Matrix: " << endl;
    PrintSortMatrix(Z, rowCount, colCount);
    cout << setw(4) << endl;

    cout << "Modificated Matrix: " << endl;
    PrintZ_Modificated(Z, rowCount, colCount);
    cout << setw(4) << endl;

    Sort(Z, rowCount, colCount);

    for (int i = 0; i < rowCount; i++)
        delete[] Z[i];
    delete[] Z;
    return 0;
}
