#include <iostream>
#include "consulente.h"

using namespace std;

void consulenteAromiNicotina() {
    int quitSmoking, cigarettesPerDay, cigaretteType;
    int drawType, flavorPreference;
    double nicotineStrength;
    string baseType;
    double resistance;
    int wattage;
    string flavorSuggestion;

    cout << "Welcome to the Flavor and Nicotine Consultant!" << endl;

    cout << "\nHave you recently quit smoking traditional cigarettes?" << endl;
    cout << "[1] Yes" << endl;
    cout << "[2] No" << endl;
    cout << "Choose an option: ";
    cin >> quitSmoking;

    if (quitSmoking == 1) {
        cout << "\nHow many cigarettes per day did you smoke?" << endl;
        cin >> cigarettesPerDay;

        cout << "\nDid you smoke regular or light cigarettes?" << endl;
        cout << "[1] Regular (e.g., Marlboro, Camel, etc.)" << endl;
        cout << "[2] Light (e.g., Marlboro Light, etc.)" << endl;
        cout << "Choose an option: ";
        cin >> cigaretteType;

        if (cigaretteType == 1) {
            if (cigarettesPerDay >= 20) {
                nicotineStrength = 12.0;
            }
            else {
                nicotineStrength = 9.0;
            }
        }
        else {
            if (cigarettesPerDay >= 15) {
                nicotineStrength = 9.0;
            }
            else {
                nicotineStrength = 6.0;
            }
        }
    }
    else {
        nicotineStrength = 3.0;
    }

    cout << "\nWhat type of draw do you prefer?" << endl;
    cout << "[1] Mouth-to-lung (MTL, similar to smoking regular cigarettes)" << endl;
    cout << "[2] Direct lung (DL, draws directly to lungs, more vapor)" << endl;
    cout << "Choose an option: ";
    cin >> drawType;

    if (drawType == 1) {
        baseType = "50/50 (balanced)";
        resistance = 1.2;
        wattage = 11;
    }
    else {
        baseType = "70/30 or 60/40 (more vapor production)";
        resistance = 0.4;
        wattage = 30;
    }

    cout << "\nWhat type of flavors do you prefer?" << endl;
    cout << "[1] Intense flavors (tobacco)" << endl;
    cout << "[2] Sweet flavors (creamy)" << endl;
    cout << "[3] Light and fresh flavors (fruity)" << endl;
    cout << "Choose an option: ";
    cin >> flavorPreference;

    if (quitSmoking == 1) {
        if (flavorPreference == 1) {
            int sweetPreference;
            cout << "\nDo you like sweet flavors?" << endl;
            cout << "[1] Yes" << endl;
            cout << "[2] No" << endl;
            cout << "Choose an option: ";
            cin >> sweetPreference;

            if (sweetPreference == 1) {
                flavorSuggestion = "Tobacco with notes of vanilla, hazelnut, or honey";
            }
            else {
                flavorSuggestion = "Classic tobacco, for a similar feeling to traditional cigarettes";
            }
        }
    }
    else if (flavorPreference == 1) {
        flavorSuggestion = "Classic tobacco";
    }
    else if (flavorPreference == 2) {
        flavorSuggestion = "Creamy, with sweet flavors like vanilla or chocolate";
    }
    else {
        flavorSuggestion = "Fruity, maybe with ice for a refreshing touch";
    }

    cout << "\n*** Recommendations for you ***" << endl;
    cout << "Recommended nicotine strength: " << nicotineStrength << " mg/ml" << endl;
    cout << "Recommended base type: " << baseType << endl;
    cout << "Recommended resistance: " << resistance << " Ohm" << endl;
    cout << "Recommended wattage: " << wattage << " W" << endl;
    cout << "Recommended flavor: " << flavorSuggestion << endl;
}
