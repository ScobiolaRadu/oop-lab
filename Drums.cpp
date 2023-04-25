#include "Drums.h"
#include "InvalidValueException.h"
#include <string.h>
#include <iostream>

// constr & destruct
Drums::Drums() : Instrument()
{
    size_t len = strlen("none");
    this->brand = new char[len + 1];
    strcpy(this->brand, "none");

    this->drumsnr = 0;
}

Drums::Drums(int price, int stock, const char *category, const char *brand, int drumsnr)
    : Instrument(price, stock, category)
{
    size_t len = strlen(brand);
    this->brand = new char[len + 1];
    strcpy(this->brand, brand);

    this->drumsnr = drumsnr;
}

Drums::Drums(const Instrument &instr, const Drums &g)
    : Instrument(instr)
{
    size_t len = strlen(g.brand);
    brand = new char[len + 1];
    strcpy(brand, g.brand);

    drumsnr = g.drumsnr;
}

Drums::~Drums()
{
    delete[] brand;
}

// setters & getters
int Drums::getDrumsNr() const
{
    return drumsnr;
}

void Drums::setDrumsNr(const int drumsnr_)
{
    drumsnr = drumsnr_;
}

char *Drums::getBrand() const
{
    return brand;
}

void Drums::setBrand(const char *brand_)
{
    if (strcmp(brand, "") != 0)
        delete[] brand;

    size_t len = strlen(brand_);
    brand = new char[len + 1];
    strcpy(brand, brand_);
}

// operators
Drums &Drums::operator=(const Drums &rhs)
{
    this->drumsnr = rhs.drumsnr;
    setPrice(rhs.getPrice());
    setStock(rhs.getStock());
    if (this != &rhs)
    {

        setBrand(rhs.brand);
    }

    return *this;
}

bool Drums::operator==(const Drums &rhs) const
{
    return this->drumsnr == rhs.drumsnr && !strcmp(this->brand, rhs.brand);
}

bool Drums::operator!=(const Drums &rhs) const
{
    return !(rhs == *this);
}

std::istream &operator>>(std::istream &is, Drums &g)
{
    g.setCategory("Drums");

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

    std::cout << "Insert number of drums: ";
    is >> x;
    g.setDrumsNr(x);
    std::cout << std::endl;

    if (g.getPrice() <= 0 || g.getStock() <= 0 || g.getDrumsNr() <= 0)
        throw InvalidValueException();

    return is;
}

std::ostream &operator<<(std::ostream &os, const Drums &g)
{
    os << "Price: " << g.getPrice() << " "
       << "Stock: " << g.getStock() << " "
       << "Brand: " << g.getBrand() << " "
       << "Number of drums: " << g.getDrumsNr() << std::endl;
    return os;
}

// virtual function
const char *Drums::Accessories() const
{
    return "Drum sticks, Drum heads";
}