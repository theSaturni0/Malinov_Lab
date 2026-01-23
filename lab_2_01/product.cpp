#include "product.hpp"

namespace saturnLib {

void product::changePrice(double const &percentage) {
    price_ = price_ * percentage;
}

bool product::isAvailable() const {
    return quantity_ > 0;
}

bool product::sellProduct(int const &quantity) {
    if (quantity > 0 && quantity <= quantity_) {
        quantity_ -= quantity;
        return true;
    }
    return false;
}

void product::printInfo() const {
    std::cout << "Product \"" << name_ << "\", category: \"" << category_ << "\""<< std::endl;
    std::cout << "Price: "<< price_ << ", quantity: " << quantity_ << std::endl;
}

}