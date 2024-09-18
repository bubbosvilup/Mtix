#include <iostream>
#include <iomanip>
#include <cmath>
#include "calcolatore.h"

using namespace std;

const double NICOTINE_CONCENTRATION = 20.0;

void printSeparator() {
    cout << "----------------------------------------" << endl;
}

void printHeader(string title) {
    printSeparator();
    cout << title << endl;
    printSeparator();
}

void drawContainer(double totalVolume, double aromaVolume, double nicotineVolume, double baseVolume) {
    int height = 10;
    int aromaHeight = round((aromaVolume / totalVolume) * height);
    int nicotineHeight = round((nicotineVolume / totalVolume) * height);
    int baseHeight = height - aromaHeight - nicotineHeight;

    printHeader("Container Levels (Stylized)");

    cout << "    _______" << endl;
    cout << "   |       |" << endl;

    for (int i = 0; i < height; i++) {
        if (i < baseHeight) {
            cout << "   |  BASE |" << endl;
        }
        else if (i < baseHeight + nicotineHeight) {
            cout << "   |NICOTIN|" << endl;
        }
        else {
            cout << "   | AROMA |" << endl;
        }
    }

    cout << "   |_______|" << endl;

    cout << "Legend:" << endl;
    cout << "- AROMA: " << aromaVolume << " ml" << endl;
    cout << "- NICOTINE: " << nicotineVolume << " ml" << endl;
    cout << "- BASE: " << baseVolume << " ml" << endl;
    printSeparator();
}

void calculateVolumes(double totalVolume, double desiredNicotineMgMl, int baseType, int numAromas, double aromaPercentage) {
    double aromaVolume = (aromaPercentage / 100.0) * totalVolume;
    double remainingVolume = totalVolume - aromaVolume;
    double nicotineVolume = (desiredNicotineMgMl * remainingVolume) / NICOTINE_CONCENTRATION;
    double baseVolume = remainingVolume - nicotineVolume;
    double aromaVolumePerType = aromaVolume / numAromas;

    double pgPercentage, vgPercentage;
    switch (baseType) {
    case 50:
        pgPercentage = 50.0;
        vgPercentage = 50.0;
        break;
    case 60:
        pgPercentage = 60.0;
        vgPercentage = 40.0;
        break;
    case 70:
        pgPercentage = 70.0;
        vgPercentage = 30.0;
        break;
    default:
        cout << "Invalid base type!" << endl;
        return;
    }

    double pgBaseVolume = (pgPercentage / 100.0) * baseVolume;
    double vgBaseVolume = (vgPercentage / 100.0) * baseVolume;
    double pgBaseWeight = pgBaseVolume * 1.04;
    double vgBaseWeight = vgBaseVolume * 1.26;

    printHeader("Liquid Summary");

    cout << "Total liquid volume: " << totalVolume << " ml" << endl;

    printHeader("Flavors");
    cout << "Flavor percentage: " << aromaPercentage << "%" << endl;
    cout << "Total flavor volume: " << aromaVolume << " ml" << endl;
    cout << "Number of flavors: " << numAromas << endl;
    cout << "Flavor volume per type: " << aromaVolumePerType << " ml" << endl;

    printHeader("Nicotine Base");
    cout << "Desired nicotine strength: " << desiredNicotineMgMl << " mg/ml" << endl;
    cout << "Total nicotine base volume: " << nicotineVolume << " ml" << endl;

    printHeader("Nicotine-Free Base");
    cout << "Total nicotine-free base volume: " << baseVolume << " ml" << endl;
    cout << "  - Propylene Glycol (PG): " << pgBaseVolume << " ml (" << pgBaseWeight << " g)" << endl;
    cout << "  - Vegetable Glycerin (VG): " << vgBaseVolume << " ml (" << vgBaseWeight << " g)" << endl;

    drawContainer(totalVolume, aromaVolume, nicotineVolume, baseVolume);
}

void calcolatoreLiquido() {
    double totalVolume, desiredNicotineMgMl, aromaPercentage;
    int baseType, numAromas;

    cout << "Enter the total liquid volume (in ml): ";
    cin >> totalVolume;

    cout << "Enter the desired nicotine strength (in mg/ml): ";
    cin >> desiredNicotineMgMl;

    cout << "Enter the base type (50 for 50/50, 60 for 60/40, 70 for 70/30): ";
    cin >> baseType;

    cout << "Enter the flavor percentage (e.g., 10, 15, 20): ";
    cin >> aromaPercentage;

    cout << "Enter the number of flavors you want to use: ";
    cin >> numAromas;

    calculateVolumes(totalVolume, desiredNicotineMgMl, baseType, numAromas, aromaPercentage);
}
