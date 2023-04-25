#include "Keyboard.h"
#include "InvalidValueException.h"
#include <string.h>
#include <iostream>

// constr & destruct
Keyboard::Keyboard()
    : Instrument()
{
    size_t len = strlen("none");
    this->brand = new char[len + 1];
    strcpy(this->brand, "none");

    size_t len2 = strlen("none");
    this->key = new char[len2 + 1];
    strcpy(this->key, "none");
}

Keyboard::Keyboard(int price, int stock, const char *category, const char *brand, const char *key)
    : Instrument(price, stock, category)
{
    size_t len = strlen(brand);
    this->brand = new char[len + 1];
    strcpy(this->brand, brand);

    size_t len2 = strlen(key);
    this->key = new char[len2 + 1];
    strcpy(this->key, key);
}

Keyboard::Keyboard(const Instrument &instr, const Keyboard &g)
    : Instrument(instr)
{
    size_t len = strlen(g.brand);
    brand = new char[len + 1];
    strcpy(brand, g.brand);

    size_t len2 = strlen(g.key);
    key = new char[len2 + 1];
    strcpy(key, g.key);
}

Keyboard::~Keyboard()
{
    delete[] brand;
    delete[] key;
}

// setters & getters
char *Keyboard::getBrand() const
{
    return brand;
}

void Keyboard::setBrand(const char *brand_)
{
    if (strcmp(brand, "") != 0)
        delete[] brand;

    size_t len = strlen(brand_);
    brand = new char[len + 1];
    strcpy(brand, brand_);
}

char *Keyboard::getKey() const
{
    return key;
}

void Keyboard::setKey(const char *key_)
{
    if (strcmp(key, "") != 0)
        delete[] key;

    size_t len = strlen(key_);
    key = new char[len + 1];
    strcpy(key, key_);
}

// operators
Keyboard &Keyboard::operator=(const Keyboard &rhs)
{
    setPrice(rhs.getPrice());
    setStock(rhs.getStock());
    if (this != &rhs)
    {

        setKey(rhs.key);
        setBrand(rhs.brand);
    }

    return *this;
}

bool Keyboard::operator==(const Keyboard &rhs) const
{
    return !strcmp(this->brand, rhs.brand) && !strcmp(this->key, rhs.key);
}

bool Keyboard::operator!=(const Keyboard &rhs) const
{
    return !(rhs == *this);
}

std::istream &operator>>(std::istream &is, Keyboard &g)
{
    g.setCategory("Keyboards");

    int x;
    std::cout << "Insert price: ";
    is >> x;
    g.setPrice(x);
    std::cout << std::endl;

    std::cout << "Insert amount in stock: ";
    is >> x;
    g.setStock(x);
    std::cout << std::endl;

    char buf[100];
    std::cout << "Insert brand: ";
    is >> buf;
    g.setBrand(buf);
    std::cout << std::endl;

    char buf2[100];
    std::cout << "Insert key: ";
    is >> buf2;
    g.setKey(buf2);
    std::cout << std::endl;

    if (g.getPrice() <= 0 || g.getStock() <= 0)
        throw InvalidValueException();

    return is;
}

std::ostream &operator<<(std::ostream &os, const Keyboard &g)
{
    os << "Price: " << g.getPrice() << " "
       << "Stock: " << g.getStock() << " "
       << "Brand: " << g.getBrand() << " "
       << "key: " << g.getKey() << std::endl;
    return os;
}

// virtual function
const char *Keyboard::Accessories() const
{
    return "Adjustable stands, Covers";
}