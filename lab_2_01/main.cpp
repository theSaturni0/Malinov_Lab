#include "product.hpp"

int main() {

    //конструкторы

    saturnLib::product product_1;
    saturnLib::product product_2("Product 2", 44.40, 3, "Default");
    saturnLib::product product_3("", -44.40, -3, "");

    std::cout << "\n";

    product_1.printInfo();
    product_2.printInfo();
    product_3.printInfo();

    //сеттеры

    product_3.setName("Product 3");
    product_3.setPrice(26.03);
    product_3.setQuantity(12);
    product_3.setCategory("Special");
    product_3.printInfo();

    //методы

    std::cout << "\n";

    product_2.changePrice(1.2);
    product_2.printInfo();

    std::cout << "\n";

    std::cout << product_2.isAvailable() << std::endl; //UNOO !!

    std::cout << "\n";

    product_2.sellProduct(2);
    product_2.printInfo();

    std::cout << "\n";

    return 0;
}
