#include <iostream>
#include <vector>
using namespace std;

class CarModel {
protected:
    virtual void start() = 0;
    virtual void stop() = 0;
    virtual void alarm() = 0;
    virtual void engineBoom() = 0;
public:
    void run() 
    {
        for (int i = 0; i < seq.size(); i++) {
            string str = seq[i];
            if (str == string("start")) {
                this->start();
            } else if (str == string("stop")) {
                this->stop();
            } else if (str == string("alarm")) {
                this->alarm();
            } else if (str == string("engine boom")) {
                this->engineBoom();
            }
        }
    }
    void setSequence(const vector<string> &v) 
    {
        seq = v;
    }
private:
    vector<string> seq;
};

class BenzModel : public CarModel {
protected:
    void start()
    {
        cout << "Benz Start" << endl;
    }
    void stop()
    {
        cout << "Benz Stop" << endl;
    }
    void alarm()
    {
        cout << "Benz Alarm" << endl;
    }
    void engineBoom()
    {
        cout << "Benz EngineBoom" << endl;
    }
};


namespace DP {
    namespace Creational {
        void bulider() 
        {
        }
    }
}