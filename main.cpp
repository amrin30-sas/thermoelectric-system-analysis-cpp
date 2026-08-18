#include <iostream>
#include <iomanip>
using namespace std;

int main() {
double load, length, E, I, c;

cout << "=== Cantilever Beam Analysis ===\n\n";  

cout << "Load at free end (N): ";  
cin >> load;  

cout << "Beam length (m): ";  
cin >> length;  

cout << "Young's modulus (Pa): ";  
cin >> E;  

cout << "Second moment of area (m^4): ";  
cin >> I;  

cout << "Distance from neutral axis (m): ";  
cin >> c;  

double deflection =  
    (load * length * length * length) /  
    (3.0 * E * I);  

double bendingMoment = load * length;  

double bendingStress =  
    (bendingMoment * c) / I;  

cout << fixed << setprecision(6);  

cout << "\n--- Results ---\n";  

cout << "Maximum Deflection : "  
     << deflection << " m\n";  

cout << "Maximum Deflection : "  
     << deflection * 1000 << " mm\n";  

cout << "Maximum Bending Moment : "  
     << bendingMoment << " N·m\n";  

cout << "Maximum Bending Stress : "  
     << bendingStress / 1e6 << " MPa\n";  

return 0;

}
