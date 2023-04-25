#include "Instrument.h"
#include <iostream>
#include <string.h>

// constr & destruct
Instrument::Instrument()
{
    this->price = 0;
    this->stock = 0;
    size_t len = strlen("none");
    this->category = new char[len + 1];
    strcpy(this->category, "none");
}

Instrument::Instrument(int price, int stock, const char *category)
{
    this->price = price;
    this->stock = stock;
    size_t len = strlen(category);
    this->category = new char[len + 1];
    strcpy(this->category, category);
}

Instrument::Instrument(const Instrument &instr)
{
    price = instr.price;
    stock = instr.stock;
    size_t len = strlen(instr.category);
    category = new char[len + 1];
    strcpy(category, instr.category);
}

Instrument::~Instrument()
{
    delete[] category;
}

// setters & getters
int Instrument::getPrice() const
{
    return price;
}
void Instrument::setPrice(const int price_)
{
    price = price_;
}

char *Instrument::getCategory() const
{
    return category;
}

void Instrument::setCategory(const char *category_)
{
    if (strcmp(category, "") != 0)
        delete[] category;

    size_t len = strlen(category_);
    category = new char[len + 1];
    strcpy(category, category_);
}

int Instrument::getStock() const
{
    return stock;
}

void Instrument::setStock(const int stock_)
{
    stock = stock_;
}

// virtual functions
const char *Instrument::showAccessories() const
{
    std::cout << "For " << getCategory() << " the recommended accessories are: " << Accessories() << std::endl;
}
