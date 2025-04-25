#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;

void PrintMenu() {
    cout << "\nCorner Grocer Menu\n";
    cout << "1. Search for item frequency\n";
    cout << "2. Print all item frequencies\n";
    cout << "3. Print histogram of items\n";
    cout << "4. Exit\n";
    cout << "Enter choice: ";
}

map<string, int> LoadData(const string& filename) {
    map<string, int> itemFrequency;
    ifstream inFile(filename);
    string item;

    while (inFile >> item) {
        itemFrequency[item]++;
    }

    inFile.close();

    // Write to backup file
    ofstream outFile("frequency.dat");
    for (const auto& pair : itemFrequency) {
        outFile << pair.first << " " << pair.second << endl;
    }
    outFile.close();

    return itemFrequency;
}

void PrintHistogram(const map<string, int>& itemFrequency) {
    for (const auto& pair : itemFrequency) {
        cout << setw(15) << left << pair.first << " ";
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    map<string, int> itemFrequency = LoadData("CS210_Project_Three_Input_File.txt");

    int choice;
    string searchItem;

    while (true) {
        PrintMenu();
        cin >> choice;

        if (choice == 1) {
            cout << "Enter item name: ";
            cin >> searchItem;
            cout << "Frequency: " << itemFrequency[searchItem] << endl;
        }
        else if (choice == 2) {
            for (const auto& pair : itemFrequency) {
                cout << pair.first << " " << pair.second << endl;
            }
        }
        else if (choice == 3) {
            PrintHistogram(itemFrequency);
        }
        else if (choice == 4) {
            cout << "Exiting program." << endl;
            break;
        }
        else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}