#include <iostream>
#include "Matrix.h"

int main() {
  
    Matrix mat1(2, 2);
    Matrix mat2(2, 2);

    mat1[0][0] = 1;
    mat1[0][1] = 2;
    mat1[1][0] = 3;
    mat1[1][1] = 4;

    mat2[0][0] = 4;
    mat2[0][1] = 3;
    mat2[1][0] = 2;
    mat2[1][1] = 1;

    std::cout << "Matrix 1:" << std::endl;
    mat1.print();

    std::cout << "Matrix 2:" << std::endl;
    mat2.print();

    Matrix resultAdd = mat1 + mat2;
    std::cout << "Addition (Matrix1 + Matrix2):" << std::endl;
    resultAdd.print();

    Matrix resultSub = mat1 - mat2;
    std::cout << "Subtraction (Matrix1 - Matrix2):" << std::endl;
    resultSub.print();

    try {
        Matrix resultMul = mat1 * mat2;
        std::cout << "Multiplication (Matrix1 * Matrix2):" << std::endl;
        resultMul.print();
    }
    catch (const std::exception& e) {
        std::cout << "Error during multiplication: " << e.what() << std::endl;
    }

    Matrix resultScalarMul = mat1 * 2.5;
    std::cout << "Scalar Multiplication (Matrix1 * 2.5):" << std::endl;
    resultScalarMul.print();

    std::cout << "Matrix1 == Matrix2? " << (mat1 == mat2 ? "Yes" : "No") << std::endl;
    std::cout << "Matrix1 != Matrix2? " << (mat1 != mat2 ? "Yes" : "No") << std::endl;

    std::cout << "Is Matrix1 non-zero? " << (mat1 ? "Yes" : "No") << std::endl;

    return 0;
}
