#include "Guitar.h"
#include "InvalidValueException.h"
#include <string.h>
#include <iostream>

// constr & destruct
Guitar::Guitar() : Instrument()
{
    size_t len = strlen("none");
    this->brand = new char[len + 1];
    strcpy(this->brand, "none");

    size_t len2 = strlen("none");
    this->body = new char[len2 + 1];
    strcpy(this->body, "none");

    this->stringsnr = 0;
}

Guitar::Guitar(int price, int stock, const char *category, const char *brand, const char *body, int stringsnr)

    : Instrument(price, stock, category)
{
    size_t len = strlen(brand);
    this->brand = new char[len + 1];
    strcpy(this->brand, brand);

    size_t len2 = strlen(body);
    this->body = new char[len2 + 1];
    strcpy(this->body, body);

    this->stringsnr = stringsnr;
}

Guitar::Guitar(const Instrument &instr, const Guitar &g)
    : Instrument(instr)
{
    size_t len = strlen(g.brand);
    brand = new char[len + 1];
    strcpy(brand, g.brand);

    size_t len2 = strlen(g.body);
    body = new char[len2 + 1];
    strcpy(body, g.body);

    stringsnr = g.stringsnr;
}

Guitar::~Guitar()
{
    delete[] brand;
    delete[] body;
}

// setters & getters
int Guitar::getStringsNr() const
{
    return stringsnr;
}

void Guitar::setStringsNr(const int stringsnr_)
{
    stringsnr = stringsnr_;
}

char *Guitar::getBrand() const
{
    return brand;
}

void Guitar::setBrand(const char *brand_)
{
    if (strcmp(brand, "") != 0)
        delete[] brand;

    size_t len = strlen(brand_);
    brand = new char[len + 1];
    strcpy(brand, brand_);
}

char *Guitar::getBody() const
{
    return body;
}

void Guitar::setBody(const char *body_)
{
    if (strcmp(body, "") != 0)
        delete[] body;

    size_t len = strlen(body_);
    body = new char[len + 1];
    strcpy(body, body_);
}

// operators
Guitar &Guitar::operator=(const Guitar &rhs)
{
    this->stringsnr = rhs.stringsnr;
    setPrice(rhs.getPrice());
    setStock(rhs.getStock());
    if (this != &rhs)
    {
        setBody(rhs.body);
        setBrand(rhs.brand);
    }

    return *this;
}

bool Guitar::operator==(const Guitar &rhs) const
{
    return this->stringsnr == rhs.stringsnr && !strcmp(this->brand, rhs.brand) && !strcmp(this->body, rhs.body);
}

bool Guitar::operator!=(const Guitar &rhs) const
{
    return !(rhs == *this);
}

std::istream &operator>>(std::istream &is, Guitar &g)
{
    g.setCategory("Guitars");

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
    std::cout << "Insert body: ";
    is >> buf2;
    g.setBody(buf2);
    std::cout << std::endl;

    std::cout << "Insert number of strings: ";
    is >> x;
    g.setStringsNr(x);
    std::cout << std::endl;

    if (g.getPrice() <= 0 || g.getStock() <= 0 || g.getStringsNr() <= 0)
        throw InvalidValueException();

    return is;
}

std::ostream &operator<<(std::ostream &os, const Guitar &g)
{
    os << "Price: " << g.getPrice() << " "
       << "Stock: " << g.getStock() << " "
       << "Brand: " << g.getBrand() << " "
       << "body: " << g.getBody() << " "
       << "Number of strings: " << g.getStringsNr() << std::endl;
    return os;
}

// virtual functions
const char *Guitar::Accessories() const
{
    return "Guitar picks, Capos, Slides, Cases";
}