#ifndef _DRUMS_H_
#define _DRUMS_H_
#include "Instrument.h"
#include <iostream>

class Drums : public Instrument
{
private:
    char *brand;
    int drumsnr;

public:
    // constr & destruct
    Drums();
    Drums(int price, int stock, const char *category, const char *brand, int drumsnr);
    Drums(const Instrument &instr, const Drums &drums);
    ~Drums();

    // setters & getters
    int getDrumsNr() const;
    void setDrumsNr(const int drumsnr_);
    char *getBrand() const;
    void setBrand(const char *brand_);

    // operators
    Drums &operator=(const Drums &rhs);
    bool operator==(const Drums &rhs) const;
    bool operator!=(const Drums &rhs) const;
    friend std::istream &operator>>(std::istream &is, Drums &d);
    friend std::ostream &operator<<(std::ostream &os, const Drums &d);

    // virtual function
    virtual const char *Accessories() const override;

    friend class InteractiveMenu;
};

#endif // _DRUMS_H_