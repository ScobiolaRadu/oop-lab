#ifndef _KEYBOARD_H_
#define _KEYBOARD_H_
#include "Instrument.h"
#include <iostream>

class Keyboard : public Instrument
{
private:
    char *brand;
    char *key;

public:
    // constr & destruct
    Keyboard();
    Keyboard(int price, int stock, const char *category, const char *brand, const char *key);
    Keyboard(const Instrument &instr, const Keyboard &g);
    ~Keyboard();

    // setters & getters
    char *getBrand() const;
    void setBrand(const char *brand_);
    char *getKey() const;
    void setKey(const char *key_);

    // operators
    Keyboard &operator=(const Keyboard &rhs);
    bool operator==(const Keyboard &rhs) const;
    bool operator!=(const Keyboard &rhs) const;
    friend std::istream &operator>>(std::istream &is, Keyboard &g);
    friend std::ostream &operator<<(std::ostream &os, const Keyboard &g);

    // virtual function
    virtual const char *Accessories() const override;

    friend class InteractiveMenu;
};

#endif // _KEYBOARD_H_