#include "phone_number.h"
#include <sstream>

PhoneNumber::PhoneNumber(const string &international_number)
{
    istringstream iss(international_number);
    char t;
    iss >> t;
    if (t != '+')
    {
        throw std::invalid_argument("Invalid phone number");
    }
    string country_code;
    string city_code;
    string local_number;
    getline(iss, country_code, '-');
    getline(iss, city_code, '-');
    iss >> local_number;
    if (local_number == "" || city_code == "" || country_code == "")
    {
        throw std::invalid_argument("Invalid phone number");
    }
    else
    {
        country_code_ = country_code;
        city_code_ = city_code;
        local_number_ = local_number;
    }
}

string PhoneNumber::GetCountryCode() const
{
    return country_code_;
}

string PhoneNumber::GetCityCode() const
{
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
    ostringstream oss;
    oss << '+' << country_code_
        << '-' << city_code_
        << '-' << local_number_;
    return oss.str();
}