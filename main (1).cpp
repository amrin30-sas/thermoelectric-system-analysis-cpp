#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
double Th_in, Th_out;
double Tc_in, Tc_out;
double massFlowHot, specificHeatHot;
double area, U;

cout << "=== Heat Exchanger Analysis ===\n\n";  

cout << "Hot fluid inlet temperature (°C): ";  
cin >> Th_in;  

cout << "Hot fluid outlet temperature (°C): ";  
cin >> Th_out;  

cout << "Cold fluid inlet temperature (°C): ";  
cin >> Tc_in;  

cout << "Cold fluid outlet temperature (°C): ";  
cin >> Tc_out;  

cout << "Hot fluid mass flow rate (kg/s): ";  
cin >> massFlowHot;  

cout << "Hot fluid specific heat (J/kg-K): ";  
cin >> specificHeatHot;  

cout << "Heat exchanger area (m²): ";  
cin >> area;  

cout << "Overall heat transfer coefficient U (W/m²-K): ";  
cin >> U;  

double deltaT1 = Th_in - Tc_out;  
double deltaT2 = Th_out - Tc_in;  

if (deltaT1 <= 0 || deltaT2 <= 0) {  
    cout << "\nInvalid temperature conditions.\n";  
    return 1;  
}  

double lmtd;  

if (fabs(deltaT1 - deltaT2) < 1e-9) {  
    lmtd = deltaT1;  
} else {  
    lmtd = (deltaT1 - deltaT2) /  
           log(deltaT1 / deltaT2);  
}  

double heatTransferRate =  
    massFlowHot * specificHeatHot *  
    (Th_in - Th_out);  

double theoreticalHeatTransfer =  
    U * area * lmtd;  

double effectiveness =  
    (heatTransferRate / theoreticalHeatTransfer) * 100.0;  

cout << fixed << setprecision(3);  

cout << "\n--- Results ---\n";  
cout << "LMTD                    : "  
     << lmtd << " K\n";  

cout << "Heat Transfer Rate      : "  
     << heatTransferRate << " W\n";  

cout << "UA × LMTD               : "  
     << theoreticalHeatTransfer << " W\n";  

cout << "Calculated Performance  : "  
     << effectiveness << " %\n";  

return 0;

}
