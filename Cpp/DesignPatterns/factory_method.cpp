#include <iostream>
#include <vector>

using namespace std;

class Stooge {
public:
    virtual void slap_stick() = 0;
};

class Larry : public Stooge {
public:
    void slap_stick()
    {
        cout << "Larry: poke eyes" << endl;
    }
};
class Moe : public Stooge {
public:
    void slap_stick()
    {
        cout << "Moe: slap head" << endl;
    }
};
class Curly : public Stooge {
public:
    void slap_stick()
    {
        cout << "Curly: suffer abuse" << endl;
    }
};


namespace DP {
    namespace Creational{
        void factory_method() 
        {
            vector<Stooge *>roles;
            int choice;
            cout << endl;
            while (true) {
                cout << "Larry(1) Moe(2) Curly(3) Go(0): ";
                cin >> choice;
                if (choice == 0) break;
                else if (choice == 1) roles.push_back(new Larry);
                else if (choice == 2) roles.push_back(new Moe);
                else if (choice == 3) roles.push_back(new Curly);
            }

            for (int i = 0; i < roles.size(); i++) {
                roles[i]->slap_stick();
            }

            for (int i = 0; i < roles.size(); i++) {
                delete roles[i];
            }
        }
    }
}