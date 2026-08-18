#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double hotTemp, coldTemp;
    double seebeck, resistance, loadResistance;

    cout << "=== Thermoelectric Generator Calculator ===\n\n";

    cout << "Enter hot-side temperature (°C): ";
    cin >> hotTemp;

    cout << "Enter cold-side temperature (°C): ";
    cin >> coldTemp;

    cout << "Enter Seebeck coefficient (V/K): ";
    cin >> seebeck;

    cout << "Enter internal resistance (Ohm): ";
    cin >> resistance;

    cout << "Enter load resistance (Ohm): ";
    cin >> loadResistance;

    double deltaT = hotTemp - coldTemp;

    if (deltaT <= 0) {
        cout << "\nError: Hot-side temperature must be greater "
             << "than cold-side temperature.\n";
        return 1;
    }

    double voltage = seebeck * deltaT;

    double current = voltage / (resistance + loadResistance);

    double power = current * current * loadResistance;

    double maxPower = (voltage * voltage) /
                      (4.0 * resistance);

    double efficiency = (power / (voltage * current)) * 100.0;

    cout << fixed << setprecision(4);

    cout << "\n--- Results ---\n";
    cout << "Temperature Difference : " << deltaT << " °C\n";
    cout << "Open-Circuit Voltage   : " << voltage << " V\n";
    cout << "Current                : " << current << " A\n";
    cout << "Output Power           : " << power << " W\n";
    cout << "Maximum Possible Power : " << maxPower << " W\n";
    cout << "Electrical Efficiency  : " << efficiency << " %\n";

    return 0;
}
