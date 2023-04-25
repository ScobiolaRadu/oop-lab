#include <iostream>
#include <string.h>
#include <vector>
#include <memory>
#include "Instrument.h"
#include "Guitar.h"
#include "Drums.h"
#include "Keyboard.h"
#include "InvalidValueException.h"
using namespace std;

class InteractiveMenu
{

public:
    vector<unique_ptr<Guitar>> g;
    vector<unique_ptr<Drums>> d;
    vector<unique_ptr<Keyboard>> k;

    int ok = 1;

    void menu()
    {
        while (ok)
        {
            cout << "1: Add guitar" << endl;
            cout << "2: Add drums" << endl;
            cout << "3: Add keyboard" << endl;
            cout << "4: See all instruments" << endl;
            cout << "5: See all guitars" << endl;
            cout << "6: See all drums" << endl;
            cout << "7: See all keyboards" << endl;
            cout << "8: See recommended accessories" << endl;
            cout << "9: Exit" << endl;

            int com;
            cin >> com;

            switch (com)
            {
            case 1:
            {
                try
                {
                    g.emplace_back(make_unique<Guitar>());
                    cin >> *g.back();

                    for (size_t i = 0; i < g.size() - 1; i++)
                        if (*g[i] == *g.back() && g.size() != 1)
                        {
                            cout << "-----" << endl
                                 << "Already existing item" << endl
                                 << "-----" << endl;
                            g.pop_back();
                            break;
                        }
                }
                catch (const InvalidValueException &e)
                {
                    std::cout << e.what() << endl;
                    g.pop_back();
                }
                break;
            }

            case 2:
            {
                try
                {
                    d.emplace_back(make_unique<Drums>());
                    cin >> *d.back();

                    for (size_t i = 0; i < d.size() - 1; i++)
                        if (*d[i] == *d.back() && d.size() != 1)
                        {
                            cout << "-----" << endl
                                 << "Already existing item" << endl
                                 << "-----" << endl;
                            d.pop_back();
                            break;
                        }
                }
                catch (const InvalidValueException &e)
                {
                    std::cout << e.what() << endl;
                    d.pop_back();
                }

                break;
            }

            case 3:
            {
                try
                {
                    k.emplace_back(make_unique<Keyboard>());
                    cin >> *k.back();

                    for (size_t i = 0; i < k.size() - 1; i++)
                        if (*k[i] == *k.back() && k.size() != 1)
                        {
                            cout << "-----" << endl
                                 << "Already existing item" << endl
                                 << "-----" << endl;
                            k.pop_back();
                            break;
                        }
                }
                catch (const InvalidValueException &e)
                {
                    std::cout << e.what() << endl;
                    k.pop_back();
                }
                break;
            }

            case 4:
            {
                cout << "-----" << endl
                     << "Guitars: " << endl
                     << "-----" << endl;
                for (const auto &ptr : g)
                {
                    std::cout << *ptr << endl;
                }
                cout << "-----" << endl
                     << "Drums: " << endl
                     << "-----" << endl;
                for (const auto &ptr : d)
                {
                    std::cout << *ptr << endl;
                }
                cout << "-----" << endl
                     << "Keyboards: " << endl
                     << "-----" << endl;
                for (const auto &ptr : k)
                {
                    std::cout << *ptr << endl;
                }
                break;
            }

            case 5:
            {
                for (const auto &ptr : g)
                    std::cout << *ptr << endl;
                break;
            }

            case 6:
            {
                for (const auto &ptr : d)
                    std::cout << *ptr << endl;
                break;
            }

            case 7:
            {
                for (const auto &ptr : k)
                    std::cout << *ptr << endl;
                break;
            }

            case 8:
            {
                Instrument *instr1 = new Guitar(0, 0, "Guitars", "", "", 0);
                Instrument *instr2 = new Drums(0, 0, "Drums", "", 0);
                Instrument *instr3 = new Keyboard(0, 0, "Keyboards", "", "");

                Guitar *newG = dynamic_cast<Guitar *>(instr1);
                Drums *newD = dynamic_cast<Drums *>(instr2);
                Keyboard *newK = dynamic_cast<Keyboard *>(instr3);

                newG->showAccessories();
                newD->showAccessories();
                newK->showAccessories();

                delete instr1;
                delete instr2;
                delete instr3;
                break;
            }

            case 9:
            {
                ok = 0;
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