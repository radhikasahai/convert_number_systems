#include <iostream>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

// Function to convert binary to decimal
int binaryToDecimal(string binary) {
    int decimal = 0;
    int base = 1;
    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1')
            decimal += base;
        base *= 2;
    }
    return decimal;
}

// Function to convert decimal to binary
string decimalToBinary(int decimal) {
    if (decimal == 0)
        return "0";
    string binary = "";
    while (decimal > 0) {
        binary = to_string(decimal % 2) + binary;
        decimal /= 2;
    }
    return binary;
}

// Function to convert decimal to octal
string decimalToOctal(int decimal) {
    if (decimal == 0)
        return "0";
    string octal = "";
    while (decimal > 0) {
        octal = to_string(decimal % 8) + octal;
        decimal /= 8;
    }
    return octal;
}

// Function to convert decimal to hexadecimal
string decimalToHexadecimal(int decimal) {
    if (decimal == 0)
        return "0";
    string hex = "";
    while (decimal > 0) {
        int remainder = decimal % 16;
        if (remainder < 10)
            hex = char('0' + remainder) + hex;
        else
            hex = char('A' + remainder - 10) + hex;
        decimal /= 16;
    }
    return hex;
}

// Function to convert any base to decimal
int anyBaseToDecimal(string num, int base) {
    int decimal = 0;
    int power = 0;
    for (int i = num.length() - 1; i >= 0; i--) {
        int digit;
        if (isdigit(num[i]))
            digit = num[i] - '0';
        else
            digit = num[i] - 'A' + 10;
        decimal += digit * pow(base, power);
        power++;
    }
    return decimal;
}

// Function to convert decimal to any base
string decimalToAnyBase(int decimal, int base) {
    if (decimal == 0)
        return "0";
    string result = "";
    while (decimal > 0) {
        int remainder = decimal % base;
        if (remainder < 10)
            result = char('0' + remainder) + result;
        else
            result = char('A' + remainder - 10) + result;
        decimal /= base;
    }
    return result;
}

int main() {
    string num;
    int baseFrom, baseTo;

    cout << "Enter the number: ";
    cin >> num;
    cout << "Enter the base of the input number: ";
    cin >> baseFrom;
    cout << "Enter the target base for the output number: ";
    cin >> baseTo;

    // Check if the input base is valid
    if (baseFrom < 2 || baseFrom > 16 || baseTo < 2 || baseTo > 16) {
        cout << "Invalid base. Please enter a base between 2 and 16." << endl;
        return 1;
    }

    // Check if the input number is valid for its base
    for (char digit : num) {
        if (isdigit(digit)) {
            if (digit - '0' >= baseFrom) {
                cout << "Invalid digit for the given base." << endl;
                return 1;
            }
        } else {
            if (!isalpha(digit) || (toupper(digit) - 'A' + 10) >= baseFrom) {
                cout << "Invalid digit for the given base." << endl;
                return 1;
            }
        }
    }

    int decimalNumber = anyBaseToDecimal(num, baseFrom);

    cout << num << " in base " << baseFrom << " is equivalent to ";

    if (baseTo == 10) {
        cout << decimalNumber << " in base " << baseTo << endl;
    } else if (baseTo == 2) {
        cout << decimalToBinary(decimalNumber) << " in base " << baseTo << endl;
    } else if (baseTo == 8) {
        cout << decimalToOctal(decimalNumber) << " in base " << baseTo << endl;
    } else if (baseTo == 16) {
        cout << decimalToHexadecimal(decimalNumber) << " in base " << baseTo << endl;
    } else {
        cout << decimalToAnyBase(decimalNumber, baseTo) << " in base " << baseTo << endl;
    }

    return 0;
}
