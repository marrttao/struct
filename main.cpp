#include <iostream>
#include <memory>
#include <string>

using namespace std;

#define EMPTY_STRING_CHECK(str) ((str).empty() ? "NOW NOTHING" : (str))
#define EMPTY_INT_CHECK(value) ((value) == 0 ? "NOW NOTHING" : to_string(value))

struct Engine {
    string name;
    int displacement = 0;
    int power = 0;
};

struct Wheel {
    int clearance = 0;
    string rubber;
    int diameter = 0;
};

struct Gearbox {
    int gears = 0;
    string type;
    int ratio = 0;
};

struct Car {
protected:
    bool isTruck = false;
    bool isFamilyCar = false;
    bool isSportsCar = false;

public:
    string mark;
    string color;
    Engine eng;
    Wheel whl;
    Gearbox gbox;

    void print() {
        cout << "Mark: " << EMPTY_STRING_CHECK(mark) << endl;
        cout << "Color: " << EMPTY_STRING_CHECK(color) << endl;
        cout << "Engine: " << EMPTY_STRING_CHECK(eng.name) << endl;
        cout << "Displacement: " << EMPTY_INT_CHECK(eng.displacement) << endl;
        cout << "Power: " << EMPTY_INT_CHECK(eng.power) << endl;
        cout << "Clearance: " << EMPTY_INT_CHECK(whl.clearance) << endl;
        cout << "Rubber: " << EMPTY_STRING_CHECK(whl.rubber) << endl;
        cout << "Diameter: " << EMPTY_INT_CHECK(whl.diameter) << endl;
        cout << "Gears: " << EMPTY_INT_CHECK(gbox.gears) << endl;
        cout << "Type: " << EMPTY_STRING_CHECK(gbox.type) << endl;
        cout << "Ratio: " << EMPTY_INT_CHECK(gbox.ratio) << endl;
    }

    void setAll() {
        cout << "Enter car mark: ";
        cin >> this->mark;
        cout << "Enter car color: ";
        cin >> this->color;
        cout << "Enter engine name: ";
        cin >> this->eng.name;
        cout << "Enter engine displacement: ";
        cin >> this->eng.displacement;

        bool validPower = false;
        while (!validPower) {
            cout << "Enter engine power: ";
            cin >> eng.power;
            if (isTruck && eng.power > 276) {
                cout << "Power is too high for a truck, the max is 276 km/hour!" << endl;
            }
            else if (isFamilyCar && eng.power > 200) {
                cout << "Power is too high for a family car, the max is 200 km/hour!" << endl;
            }
            else if (isSportsCar && eng.power < 400) {
                cout << "Power is too low for a sports car, the minimum is 400 km/hour!" << endl;
            }
            else {
                validPower = true;
            }
        }

        cout << "Enter wheel clearance: ";
        cin >> whl.clearance;

        bool validClearance = false;
        while (!validClearance) {
            if (isTruck && whl.clearance < 30) {
                cout << "Clearance is too low for a truck, the minimum is 30 cm!" << endl;
            }
            else if (isFamilyCar && whl.clearance < 15) {
                cout << "Clearance is too low for a family car, the minimum is 15 cm!" << endl;
            }
            else if (isSportsCar && whl.clearance < 10) {
                cout << "Clearance is too low for a sports car, the minimum is 10 cm!" << endl;
            }
            else {
                validClearance = true;
            }
            if (!validClearance) {
                cout << "Enter wheel clearance: ";
                cin >> whl.clearance;
            }
        }

        cout << "Enter wheel rubber: ";
        cin >> whl.rubber;

        cout << "Enter wheel diameter: ";
        cin >> whl.diameter;

        bool validDiameter = false;
        while (!validDiameter) {
            if (isSportsCar && whl.diameter > 20) {
                cout << "Diameter is too large for a sports car, the maximum is 20 inches!" << endl;
            }
            else {
                validDiameter = true;
            }
            if (!validDiameter) {
                cout << "Enter wheel diameter: ";
                cin >> whl.diameter;
            }
        }

        cout << "Enter gearbox gears: ";
        cin >> gbox.gears;

        cout << "Enter gearbox type: ";
        cin >> gbox.type;

        bool validGearboxType = false;
        while (!validGearboxType) {
            if (isSportsCar && gbox.type != "manual") {
                cout << "Sports cars should only have manual transmission!" << endl;
            }
            else {
                validGearboxType = true;
            }
            if (!validGearboxType) {
                cout << "Enter gearbox type: ";
                cin >> gbox.type;
            }
        }

        cout << "Enter gearbox ratio: ";
        cin >> gbox.ratio;
    }
    void setOne() {
        int choice;
        cout << "Select the attribute to change:" << endl;
        cout << "1. Mark" << endl;
        cout << "2. Color" << endl;
        cout << "3. Engine name" << endl;
        cout << "4. Engine displacement" << endl;
        cout << "5. Engine power" << endl;
        cout << "6. Wheel clearance" << endl;
        cout << "7. Wheel rubber" << endl;
        cout << "8. Wheel diameter" << endl;
        cout << "9. Gearbox gears" << endl;
        cout << "10. Gearbox type" << endl;
        cout << "11. Gearbox ratio" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter car mark: ";
            cin >> this->mark;
            break;
        case 2:
            cout << "Enter car color: ";
            cin >> this->color;
            break;
        case 3:
            cout << "Enter engine name: ";
            cin >> this->eng.name;
            break;
        case 4:
            cout << "Enter engine displacement: ";
            cin >> this->eng.displacement;
            break;
        case 5: {
            bool validPower = false;
            while (!validPower) {
                cout << "Enter engine power: ";
                cin >> eng.power;
                if (isTruck && eng.power > 276) {
                    cout << "Power is too high for a truck, the max is 276 km/hour!" << endl;
                }
                else if (isFamilyCar && eng.power > 200) {
                    cout << "Power is too high for a family car, the max is 200 km/hour!" << endl;
                }
                else if (isSportsCar && eng.power < 400) {
                    cout << "Power is too low for a sports car, the minimum is 400 km/hour!" << endl;
                }
                else {
                    validPower = true;
                }
            }
            break;
        }
        case 6: {
            bool validClearance = false;
            while (!validClearance) {
                cout << "Enter wheel clearance: ";
                cin >> whl.clearance;
                if (isTruck && whl.clearance < 30) {
                    cout << "Clearance is too low for a truck, the minimum is 30 cm!" << endl;
                }
                else if (isFamilyCar && whl.clearance < 15) {
                    cout << "Clearance is too low for a family car, the minimum is 15 cm!" << endl;
                }
                else if (isSportsCar && whl.clearance < 10) {
                    cout << "Clearance is too low for a sports car, the minimum is 10 cm!" << endl;
                }
                else {
                    validClearance = true;
                }
            }
            break;
        }
        case 7:
            cout << "Enter wheel rubber: ";
            cin >> whl.rubber;
            break;
        case 8: {
            bool validDiameter = false;
            while (!validDiameter) {
                cout << "Enter wheel diameter: ";
                cin >> whl.diameter;
                if (isSportsCar && whl.diameter > 20) {
                    cout << "Diameter is too large for a sports car, the maximum is 20 inches!" << endl;
                }
                else {
                    validDiameter = true;
                }
            }
            break;
        }
        case 9:
            cout << "Enter gearbox gears: ";
            cin >> gbox.gears;
            break;
        case 10: {
            bool validGearboxType = false;
            while (!validGearboxType) {
                cout << "Enter gearbox type: ";
                cin >> gbox.type;
                if (isSportsCar && gbox.type != "manual") {
                    cout << "Sports cars should only have manual transmission!" << endl;
                }
                else {
                    validGearboxType = true;
                }
            }
            break;
        }
        case 11:
            cout << "Enter gearbox ratio: ";
            cin >> gbox.ratio;
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
        }
    }
};

struct SportsCar : public Car {
public:
    SportsCar() { this->isSportsCar = true; }
};

struct FamilyCar : public Car {
public:
    FamilyCar() { this->isFamilyCar = true; }
};

struct Truck : public Car {
public:
    Truck() { this->isTruck = true; }
};

int main() {
    int choice;
    shared_ptr<Car> myCar;

    do {
        cout << "Select car type:" << endl;
        cout << "1. Sports car" << endl;
        cout << "2. Family car" << endl;
        cout << "3. Truck" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            myCar = make_shared<SportsCar>();
            break;
        case 2:
            myCar = make_shared<FamilyCar>();
            break;
        case 3:
            myCar = make_shared<Truck>();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
            continue;
        }

        int action;
        do {
            cout << "Select action:" << endl;
            cout << "1. Set all attributes" << endl;
            cout << "2. Set one attribute" << endl;
            cout << "3. Print car details" << endl;
            cout << "4. Select car type" << endl;
            cout << "Other. Exit";
            cout << "Enter your choice: ";
            cin >> action;

            switch (action) {
            case 1:
                myCar->setAll();
                break;
            case 2:
                myCar->setOne();
                break;
            case 3:
                myCar->print();
                break;
            case 4:
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
            }
        } while (action != 4);

    } while (choice != 4);

    return 0;
}
