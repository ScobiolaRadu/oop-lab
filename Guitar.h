#ifndef _GUITAR_H_
#define _GUITAR_H_
#include "Instrument.h"
#include <iostream>

class Guitar : public Instrument
{
private:
    char *brand;
    char *body;
    int stringsnr;

public:
    // constr & destruct
    Guitar();
    Guitar(int price, int stock, const char *category, const char *brand, const char *body, int stringsnr);
    Guitar(const Instrument &instr, const Guitar &guitar);
    ~Guitar();

    // setters & getters
    int getStringsNr() const;
    void setStringsNr(const int stringsnr_);
    char *getBrand() const;
    void setBrand(const char *brand_);
    char *getBody() const;
    void setBody(const char *body_);

    // operators
    Guitar &operator=(const Guitar &rhs);
    bool operator==(const Guitar &rhs) const;
    bool operator!=(const Guitar &rhs) const;
    friend std::istream &operator>>(std::istream &is, Guitar &g);
    friend std::ostream &operator<<(std::ostream &os, const Guitar &g);

    // virtual function
    virtual const char *Accessories() const override;

    friend class InteractiveMenu;
};

#endif // _GUITAR_H_