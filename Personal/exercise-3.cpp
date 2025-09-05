#include <iostream>
using namespace std;

int exercise3()
{
    double sales = 95000;
    cout << "Sales: $" << sales << endl;

    const double state_tax_rate = .04;
    double state_tax = sales * state_tax_rate;
    cout << "State tax: $" << state_tax << endl;

    const double county_tax_rate = .02;
    double county_tax = sales * county_tax_rate;
    cout << "County tax: $" << county_tax << endl;

    double total_tax = county_tax + state_tax;
    cout << "Total tax: $" << total_tax;
    
    return 0;
}
