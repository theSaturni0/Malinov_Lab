#include "matrix.hpp"

int main() {
    saturnLib::Matrix Matrix_1;
    saturnLib::Matrix Matrix_2(2, 2);
    saturnLib::Matrix Matrix_3(-2,2);

    std::cout << Matrix_1 << std::endl;
    std::cout << Matrix_2 << std::endl;
    std::cout << Matrix_3 << std::endl;

    saturnLib::Matrix Matrix_4 = Matrix_2;
    std::cout << Matrix_4 << std::endl;
    Matrix_3 = Matrix_4;
    std::cout << Matrix_3 << std::endl;

    saturnLib::Matrix Custom_Matrix_1;
    saturnLib::Matrix Custom_Matrix_2;

    std::cin >> Custom_Matrix_1;
    std::cin >> Custom_Matrix_2;

    std::cout << (Custom_Matrix_1 + Custom_Matrix_2);
    std::cout << (Custom_Matrix_1 - Custom_Matrix_2);
    std::cout << (Custom_Matrix_1 * Custom_Matrix_2);
    std::cout << (Custom_Matrix_1 == Custom_Matrix_2) << std::endl;
    std::cout << (Custom_Matrix_1 != Custom_Matrix_2) << std::endl;

    std::cout << Custom_Matrix_1.determinant() << std::endl;
    std::cout << Custom_Matrix_2.determinant() << std::endl;

    Custom_Matrix_1.transpose();
    Custom_Matrix_2.transpose();

    std::cout << Custom_Matrix_1;
    std::cout << Custom_Matrix_2;
}