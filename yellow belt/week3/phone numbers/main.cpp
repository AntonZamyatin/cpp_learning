#include "phone_number.h"
#include <iostream>

int main()
{
    PhoneNumber pn("+34-34r43--dfvsdfv");
    cout << pn.GetCountryCode() << '\n'
         << pn.GetCityCode() << '\n'
         << pn.GetLocalNumber() << '\n'
         << pn.GetInternationalNumber() << endl;
    return 0;
}