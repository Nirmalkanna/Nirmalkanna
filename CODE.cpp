#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Class to represent a car
class Car {
public:
    string make;
    string model;
    string license_plate;
    bool available;
    Car(string ma, string mo, string lp) {
        make = ma;
        model = mo;
        license_plate = lp;
        available = true;
    }
};

// Class to represent a car rental service
class CarRentalService {
public:
    vector<Car> cars;
    void add_car() {
        cout << "Enter car make: ";
        string make;
        cin >> make;
        cout << "Enter car model: ";
        string model;
        cin >> model;
        cout << "Enter license plate: ";
        string license_plate;
        cin >> license_plate;
        Car car(make, model, license_plate);
        cars.push_back(car);
        cout << "Added car " << make << " " << model << " with license plate " << license_plate << "." << endl;
    }
    void rent_car() {
        cout << "Enter license plate: ";
        string license_plate;
        cin >> license_plate;
        vector<Car>::iterator it = find_if(cars.begin(), cars.end(), [&](const Car& c) { return c.license_plate == license_plate; });
        if (it == cars.end()) {
            cout << "Invalid license plate." << endl;
            return;
        }
        Car& car = *it;
        if (!car.available) {
            cout << "Car is not available." << endl;
            return;
        }
        car.available = false;
        cout << "Rented car " << car.make << " " << car.model << " with license plate " << car.license_plate << "." << endl;
    }
    void return_car() {
        cout << "Enter license plate: ";
        string license_plate;
        cin >> license_plate;
        vector<Car>::iterator it = find_if(cars.begin(), cars.end(), [&](const Car& c) { return c.license_plate == license_plate; });
        if (it == cars.end()) {
            cout << "Invalid license plate." << endl;
            return;
        }
        Car& car = *it;
        if (car.available) {
            cout << "Car is already available." << endl;
            return;
        }
        car.available = true;
        cout << "Returned car " << car.make << " " << car.model << " with license plate " << car.license_plate << "." << endl;
    }
};

// Main function
int main() {
    CarRentalService car_rental_service;
    while (true) {
        cout << "Enter 1 to add a car, 2 to rent a car, 3 to return a car, or 4 to exit: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                car_rental_service.add_car();
                break;
            case 2:
                car_rental_service.rent_car();
                break;
            case 3:
                car_rental_service.return_car();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice." << endl;
                break;
        }
    }
}
