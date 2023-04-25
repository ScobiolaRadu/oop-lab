#ifndef _INSTRUMENT_H_
#define _INSTRUMENT_H_

class Instrument
{
private:
    int price;
    int stock;
    char *category;

public:
    // constr & destruct
    Instrument();
    Instrument(int price, int stock, const char *category);
    Instrument(const Instrument &instr);
    ~Instrument();

    // setters & getters
    int getPrice() const;
    void setPrice(const int price_);
    char *getCategory() const;
    void setCategory(const char *category_);
    int getStock() const;
    void setStock(const int stock_);

    // virtual functions
    virtual const char *Accessories() const = 0;
    virtual const char *showAccessories() const;

    friend class InteractiveMenu;
};

#endif // _INSTRUMENT_H_