#include <iostream>
#include <vector>
using namespace std;

class EVParkingSystem {
private:
    vector<bool> slots;
    int totalSlots;

public:
    EVParkingSystem(int n) {
        totalSlots = n;
        slots.resize(n, false);
    }

    void displaySlots() {
        cout << "\n===== EV Parking Slots =====\n";

        for (int i = 0; i < totalSlots; i++) {
            cout << "Slot " << i + 1 << ": ";

            if (slots[i])
                cout << "Occupied";
            else
                cout << "Available";

            cout << endl;
        }
    }

    void parkEV() {
        for (int i = 0; i < totalSlots; i++) {
            if (!slots[i]) {
                slots[i] = true;

                cout << "\nEV parked successfully!";
                cout << "\nAssigned Slot: " << i + 1 << endl;
                return;
            }
        }

        cout << "\nNo parking slots available.\n";
    }

    void removeEV() {
        int slot;

        cout << "\nEnter slot number to free: ";
        cin >> slot;

        if (slot < 1 || slot > totalSlots) {
            cout << "Invalid slot number!\n";
            return;
        }

        if (!slots[slot - 1]) {
            cout << "Slot is already empty.\n";
        } else {
            slots[slot - 1] = false;
            cout << "EV removed successfully from Slot "
                 << slot << ".\n";
        }
    }

    void showAvailableSlots() {
        int count = 0;

        cout << "\nAvailable EV Charging Slots: ";

        for (int i = 0; i < totalSlots; i++) {
            if (!slots[i]) {
                cout << i + 1 << " ";
                count++;
            }
        }

        if (count == 0)
            cout << "None";

        cout << "\nTotal Available Slots: " << count << endl;
    }
};

int main() {
    int n, choice;

    cout << "===== Smart EV Parking System =====\n";

    cout << "Enter number of parking slots: ";
    cin >> n;

    EVParkingSystem parking(n);

    do {
        cout << "\n\n----- MENU -----\n";
        cout << "1. Display Parking Slots\n";
        cout << "2. Park EV\n";
        cout << "3. Remove EV\n";
        cout << "4. Show Available Slots\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                parking.displaySlots();
                break;

            case 2:
                parking.parkEV();
                break;

            case 3:
                parking.removeEV();
                break;

            case 4:
                parking.showAvailableSlots();
                break;

            case 5:
                cout << "\nThank you for using Smart EV Parking System!\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
