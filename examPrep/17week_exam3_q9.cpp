#include <iostream>
#include <vector>

using namespace std;

class Device {
public:
    Device(string serial, int value) {
        this->serial = serial;
        this->value = value;
    }
    string serial;
    int value;
    string valueDescriptor;
    void print() {
        cout << "Serial: " << serial << " " << valueDescriptor << ": " << value << endl;
    }
};

class Laptop : public Device {
public:
    Laptop(string serial, int value) : Device(serial, value) {
        this->valueDescriptor = "ram";
    }
};

class Projector : public Device {
public:
    Projector(string serial, int value) : Device(serial, value) {
        this->valueDescriptor = "bulb life";
    }
};

class Composite : vector<Device> {
public:
    void printItem(int index) {
        (*this)[index].print();
    }
    Composite& operator+=(Device device) {
        this->push_back(device);
        return *this;
    }
};




int main(){
    Laptop dell("abc123", 8096);
    cout << "Dell: " << endl;
    dell.print();

    Projector epson("xufhfh1", 10000);
    cout << "Projector: " << endl;
    epson.print();

    Composite together;
    together += dell;
    together += epson;
    cout << "*******************" << endl;
    cout << "Together: " << endl;
    together.printItem(0);
}