/*
Author: Pedro Castro (pc3151@nyu.edu)
Date: 07/15/2022
This file has question 3 for homework 2
*/



#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>
#include<algorithm>
#include <cctype>
#include <cstring>
#include <new>
#include <chrono>
#include <algorithm>

using namespace std;

int main()
{
    int johnDays, johnHours, johnMinutes, billDays, billHours, billMinutes;
    cout << "Please enter the number of days John has worked: \n";
    cin >> johnDays;
    cout << "Please enter the number of hours John has worked: \n";
    cin >> johnHours;
    cout << "Please enter the number of minutes John has worked: \n";
    cin >> johnMinutes;

    cout << "Please enter the number of days Bill has worked: \n";
    cin >> billDays;
    cout << "Please enter the number of hours Bill has worked: \n";
    cin >> billHours;
    cout << "Please enter the number of minutes Bill has worked: \n";
    cin >> billMinutes;

    cout << "The total time both of them worked together is: " << johnDays +
                                                                  billDays << " days, " << johnHours + billHours << " hours and " <<
         johnMinutes + billMinutes << " minutes.\n";
    return 0;
}