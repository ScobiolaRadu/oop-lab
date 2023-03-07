#include <iostream>
#include <string.h>

using namespace std;

class Instrument
{
    int price;
    int stock;
    char *category;

public:
    //constructor fara argumente
    Instrument()
    {
        this -> price = 0;
        this -> stock = 0;
        this -> category = strdup("");
    }

    //constructor cu argumente
    Instrument(int price, int stock, const char* category)
    {
        this->price = price;
        this -> stock = stock;
        size_t len = strlen(category);
        this->category = new char[len + 1];
        strcpy(this->category, category);
    }

    //copy constructor
    Instrument(const Instrument &instr)
    {
        price = instr.price;
        stock = instr.stock;
        size_t len = strlen(instr.category);
        category = new char[len + 1];
        strcpy(category, instr.category);
    }

    //destructor
    ~Instrument()
    {
        delete[] category;
    }


    //get si set//
    int getPrice() const
    {
        return price;
    }
    void setPrice(int price)
    {
        this->price = price;
    }


    char *getCategory() const
    {
        return category;
    }
    void setCategory(const char* category_)
    {
        delete[] category;

        size_t len = strlen(category_);
        category = new char[len + 1];
        strcpy(category, category_);
    }


    int getStock() const
    {
        return stock;
    }
    void setStock(int stock)
    {
        this->stock = stock;
    }
    //////////////////////////

    //operator atribuire
    Instrument& operator=(const Instrument &rhs)
    {

        this->price = rhs.price;
        this->stock = rhs.stock;
        if (this != &rhs)
            setCategory(rhs.category);


        return *this;
    }

    //operator ==
    bool operator==(const Instrument &rhs) const
    {
        return this->price == rhs.price && this->stock == rhs.stock && !strcmp(this->category, rhs.category);
    }

    //operator !=
    bool operator!=(const Instrument &rhs) const
    {
        return !(rhs == *this);
    }

    //operator >>
    friend std::istream& operator>>(std::istream &is, Instrument &instr)
    {
        int x;
        cout<<"Insert price: ";
        is>>x;
        instr.setPrice(x);
        cout<<endl;
        cout<<"Insert amount in stock: ";
        is>>x;
        instr.setStock(x);
        cout<<endl;

        char buf[100];
        cout<<"Insert category name: ";
        is >> buf;
        instr.setCategory(buf);
        cout<<endl;

        return is;
    }

    //operator <<
    friend std::ostream& operator<<(std::ostream &os, const Instrument &instr)
    {
        os<<"Price: "<<instr.getPrice()<<" "<<"Amount in stock: "<<instr.getStock()<<" "<<"Category: "<<instr.getCategory()<<endl;
        return os;
    }

    //clasele friend
    friend class Guitar;
    friend class Drums;
    friend class Keyboard;
    friend class InteractiveMenu;

};


class Guitar
{
    char* brand;
    char* body;
    int stringsnr;

public:
    //constructor fara argumente

    Guitar()
    {
        this -> brand = strdup("");
        this -> body = strdup("");
        this -> stringsnr = 0;
    }

    //constructor cu argumente
    Guitar(const char* brand, const char* body, int stringsnr)
    {
        size_t len = strlen(brand);
        this->brand = new char[len + 1];
        strcpy(this->brand, brand);

        size_t len2 = strlen(body);
        this->body = new char[len2 + 1];
        strcpy(this->body, body);

        this->stringsnr = stringsnr;

    }

    //copy constructor
    Guitar(const Guitar &g)
    {
        size_t len = strlen(g.brand);
        brand = new char[len + 1];
        strcpy(brand, g.brand);

        size_t len2 = strlen(g.body);
        body = new char[len2 + 1];
        strcpy(body, g.body);

        stringsnr = g.stringsnr;
    }

    //destructor
    ~Guitar()
    {
        delete[] brand;
        delete[] body;
    }


    //get si set//
    int getStringsnr() const
    {
        return stringsnr;
    }
    void setStringsnr(int stringsnr)
    {
        this->stringsnr = stringsnr;
    }


    char *getBrand() const
    {
        return brand;
    }
    void setBrand(const char* brand_)
    {
        delete[] brand;

        size_t len = strlen(brand_);
        brand = new char[len + 1];
        strcpy(brand, brand_);
    }


    char *getbody() const
    {
        return body;
    }
    void setbody(const char* body_)
    {
        delete[] body;

        size_t len = strlen(body_);
        body = new char[len + 1];
        strcpy(body, body_);
    }

    //////////////////////////

    //operator atribuire
    Guitar& operator=(const Guitar &rhs)
    {
        this->stringsnr = rhs.stringsnr;
        if (this != &rhs)
        {
            setbody(rhs.body);
            setBrand(rhs.brand);
        }

        return *this;
    }

    //operator ==
    bool operator==(const Guitar &rhs) const
    {
        return this->stringsnr == rhs.stringsnr && !strcmp(this->brand, rhs.brand) && !strcmp(this->body, rhs.body);
    }

    //operator !=
    bool operator!=(const Guitar &rhs) const
    {
        return !(rhs == *this);
    }

    //operator >>
    friend std::istream& operator>>(std::istream &is, Guitar &g)
    {
        char buf[100];
        cout<<"Insert brand: ";
        is>>buf;
        g.setBrand(buf);
        cout<<endl;

        char buf2[100];
        cout<<"Insert body: ";
        is>>buf2;
        g.setbody(buf2);
        cout<<endl;

        int x;
        cout<<"Insert number of strings: ";
        is >> x;
        g.setStringsnr(x);
        cout<<endl;

        return is;
    }

    //operator <<
    friend std::ostream& operator<<(std::ostream &os, const Guitar &g)
    {
        os<<"Brand: "<<g.getBrand()<<" "<<"body: "<<g.getbody()<<" "<<"Number of strings: "<<g.getStringsnr()<<endl;
        return os;
    }

    friend class InteractiveMenu;

};

class Drums
{
    char* brand;
    int drumsnr;

public:
    //constructor fara argumente

    Drums()
    {
        this -> brand = strdup("");
        this -> drumsnr = 0;
    }

    //constructor cu argumente
    Drums(const char* brand, int drumsnr)
    {
        size_t len = strlen(brand);
        this->brand = new char[len + 1];
        strcpy(this->brand, brand);

        this->drumsnr = drumsnr;

    }

    //copy constructor
    Drums(const Drums &g)
    {
        size_t len = strlen(g.brand);
        brand = new char[len + 1];
        strcpy(brand, g.brand);

        drumsnr = g.drumsnr;
    }

    //destructor
    ~Drums()
    {
        delete[] brand;
    }


    //get si set//
    int getDrumsnr() const
    {
        return drumsnr;
    }
    void setDrumsnr(int drumsnr)
    {
        this->drumsnr = drumsnr;
    }


    char *getBrand() const
    {
        return brand;
    }
    void setBrand(const char* brand_)
    {
        delete[] brand;

        size_t len = strlen(brand_);
        brand = new char[len + 1];
        strcpy(brand, brand_);
    }

    //////////////////////////

    //operator atribuire
    Drums& operator=(const Drums &rhs)
    {
        this->drumsnr = rhs.drumsnr;
        if (this != &rhs)
        {
            setBrand(rhs.brand);
        }

        return *this;
    }

    //operator ==
    bool operator==(const Drums &rhs) const
    {
        return this->drumsnr == rhs.drumsnr && !strcmp(this->brand, rhs.brand);
    }

    //operator !=
    bool operator!=(const Drums &rhs) const
    {
        return !(rhs == *this);
    }

    //operator >>
    friend std::istream& operator>>(std::istream &is, Drums &g)
    {
        char buf[100];
        cout<<"Insert brand: ";
        is>>buf;
        g.setBrand(buf);
        cout<<endl;

        int x;
        cout<<"Insert number of drums: ";
        is >> x;
        g.setDrumsnr(x);
        cout<<endl;

        return is;
    }

    //operator <<
    friend std::ostream& operator<<(std::ostream &os, const Drums &g)
    {
        os<<"Brand: "<<g.getBrand()<<" "<<"Number of drums: "<<g.getDrumsnr()<<endl;
        return os;

    }

    friend class InteractiveMenu;
};

class Keyboard
{
    char* brand;
    char* key;

public:
    //constructor fara argumente

    Keyboard()
    {
        this -> brand = strdup("");
        this -> key = strdup("");
    }

    //constructor cu argumente
    Keyboard(const char* brand, const char* key)
    {
        size_t len = strlen(brand);
        this->brand = new char[len + 1];
        strcpy(this->brand, brand);

        size_t len2 = strlen(key);
        this->key = new char[len2 + 1];
        strcpy(this->key, key);

    }

    //copy constructor
    Keyboard(const Keyboard &g)
    {
        size_t len = strlen(g.brand);
        brand = new char[len + 1];
        strcpy(brand, g.brand);

        size_t len2 = strlen(g.key);
        key = new char[len2 + 1];
        strcpy(key, g.key);
    }

    //destructor
    ~Keyboard()
    {
        delete[] brand;
        delete[] key;
    }


    //get si set//
    char *getBrand() const
    {
        return brand;
    }
    void setBrand(const char* brand_)
    {
        delete[] brand;

        size_t len = strlen(brand_);
        brand = new char[len + 1];
        strcpy(brand, brand_);
    }


    char *getKey() const
    {
        return key;
    }
    void setKey(const char* key_)
    {
        delete[] key;

        size_t len = strlen(key_);
        key = new char[len + 1];
        strcpy(key, key_);
    }

    //////////////////////////

    //operator atribuire
    Keyboard& operator=(const Keyboard &rhs)
    {
        if (this != &rhs)
        {
            setKey(rhs.key);
            setBrand(rhs.brand);
        }

        return *this;
    }

    //operator ==
    bool operator==(const Keyboard &rhs) const
    {
        return !strcmp(this->brand, rhs.brand) && !strcmp(this->key, rhs.key);
    }

    //operator !=
    bool operator!=(const Keyboard &rhs) const
    {
        return !(rhs == *this);
    }

    //operator >>
    friend std::istream& operator>>(std::istream &is, Keyboard &g)
    {
        char buf[100];
        cout<<"Insert brand: ";
        is>>buf;
        g.setBrand(buf);
        cout<<endl;

        char buf2[100];
        cout<<"Insert key: ";
        is>>buf2;
        g.setKey(buf2);
        cout<<endl;

        return is;
    }

    //operator <<
    friend std::ostream& operator<<(std::ostream &os, const Keyboard &g)
    {
        os<<"Brand: "<<g.getBrand()<<" "<<"key: "<<g.getKey()<<endl;
        return os;

    }

    friend class InteractiveMenu;
};

class InteractiveMenu
{
public:

    Instrument instr[100];
    Guitar g[100];
    Drums d[100];
    Keyboard k[100];

    int i=1, ok=1;
    void menu()
    {
        while(ok)
        {
            cout<<"Categories are guitar, drums, keyboard"<<endl;
            cout<<"1: Add instrument"<<endl;
            cout<<"2: See all instruments"<<endl;
            cout<<"3: See all guitars"<<endl;
            cout<<"4: See all drums"<<endl;
            cout<<"5: See all keyboards"<<endl;
            cout<<"6: Exit"<<endl;

            int com;
            cin>>com;

            switch(com)
            {

            case 1:
            {
                std::cin>>instr[i];
                if(!strcmp(instr[i].category, "guitar"))
                {
                    std::cin>>g[i];
                    i++;
                }
                else if(!strcmp(instr[i].category, "drums"))
                {
                    std::cin>>d[i];
                    i++;
                }

                else if(!strcmp(instr[i].category, "keyboard"))
                {
                    std::cin>>k[i];
                    i++;
                }

                else
                    cout<<"Inexistent category name. Check spelling."<<endl;

                break;
            }

            case 2:
            {

                for(int j=1; j<=i; j++)
                {
                    if(strcmp(instr[j].category, "")!=0)
                        std::cout<<instr[j]<<endl;
                    if(!strcmp(instr[j].category, "guitar"))
                        std::cout<<g[j]<<endl<<"-----"<<endl;
                    else if(!strcmp(instr[j].category, "drums"))
                        std::cout<<d[j]<<endl<<"-----"<<endl;
                    else if(!strcmp(instr[j].category, "keyboard"))
                        std::cout<<k[j]<<endl<<"-----"<<endl;
                }
                break;
            }

            case 3:
            {
                for(int j=1; j<=i; j++)
                    if(strcmp(g[j].brand, "")!=0)
                        std::cout<<g[j]<<endl;

                break;
            }

            case 4:
            {
                for(int j=1; j<=i; j++)
                    if(strcmp(d[j].brand, "")!=0)
                        std::cout<<d[j]<<endl;

                break;
            }

            case 5:
            {
                for(int j=1; j<=i; j++)
                    if(strcmp(k[j].brand, "")!=0)
                        std::cout<<k[j]<<endl;

                break;
            }

            case 6:
            {
                ok=0;
                break;
            }
            }
        }
    }

};

int main()
{
    InteractiveMenu menu;
    menu.menu();

    return 0;
}
