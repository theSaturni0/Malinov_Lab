#pragma once

#include <string>
#include <iostream>

namespace saturnLib {
class product {

private:
    std::string name_;
    double price_;
    int quantity_;
    std::string category_;

public:
    //конструктор
    product() :
        name_("Placeholder"), price_(0.0), quantity_(0), category_("Default") {
        std::cout << "Placeholder product created" << std::endl;
    }
    //параметризированный конструктор
    product(const std::string &name, const double &price, const int &quantity, const std::string &category) :
        name_("Placeholder"), price_(0.0), quantity_(0), category_("Default") {
        setName(name);
        setPrice(price);
        setQuantity(quantity);
        setCategory(category);
        std::cout << "Product \"" << name_ << "\" created" << std::endl;
        if (name_ != name || price_ != price || quantity_ != quantity || category_ != category) {
            std::cout << "Product values changed due to invalid input data" << std::endl;
        }

    }
    //деструктор
    ~product() {
        std::cout << "Product \"" << name_ << "\" deleted" << std::endl;
    }
    //геттеры
    std::string getName() const { return name_; }
    double getPrice() const { return price_; }
    int getQuantity() const { return quantity_; }
    std::string getCategory() const { return category_; }

    //сеттеры
    void setName(const std::string &name) {
        if (!name.empty()) name_ = name;
    }
    void setPrice(const double &price) {
        if (price>0) price_ = price;
    }
    void setQuantity(const int &quantity) {
        if (quantity>=0) quantity_ = quantity;
    }
    void setCategory(const std::string &category) {
        if (!category.empty()) category_ = category;
    }

    //методы
    void changePrice(double const &percentage);
    bool isAvailable() const;
    bool sellProduct(int const &quantity);
    void printInfo() const;
};
}