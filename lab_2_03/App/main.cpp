#include <library.h>
#include <iostream>

using namespace std;

int main() {

    int operation;
    string tmp_operation;

    double value;
    string tmp_value;

    string tmp_ntype;
    int ntype;
    string type;

    while (true) {
        bool valid = true;

        cout << "1. Temperature" << endl;
        cout << "2. Length" << endl;
        cout << "3. Mass" << endl;
        cout << "4. Time" << endl;
        cout << "5. Volume" << endl;
        cout << "6. Exit" << endl;

        while (true) {
            cout << "Enter operation:" << endl;
            getline(cin, tmp_operation);
            if (satl::isInt(tmp_operation)) break;
            cout << "Invalid operation" << endl;
        }

        operation = stoi(tmp_operation);

        switch (operation) {
            case 1: {
                cout << "1. Celsius" << endl;
                cout << "2. Fahrenheit" << endl;
                cout << "3. Kelvin" << endl;

                while (true) {
                    cout << "Enter type:" << endl;
                    getline(cin, tmp_ntype);
                    if (satl::isInt(tmp_ntype)) {
                        if (stoi(tmp_ntype) < 4 || stoi(tmp_ntype) > 0) { break; }
                        cout << "Invalid type" << endl;
                    }
                }
                ntype = stoi(tmp_ntype);

                if (ntype == 1) { type = "celsius"; }
                else if (ntype == 2) { type = "fahrenheit"; }
                else if (ntype == 3) { type = "kelvin"; }
                else { type = "Invalid"; }

                while (true) {
                    cout << "Enter value:" << endl;
                    getline(cin, tmp_value);
                    if (satl::isFloat(tmp_value)) { break; }
                    cout << "Invalid value" << endl;
                }
                value = stof(tmp_value);

                satl::converter(value, type);
                break;
            }
            case 2: {
                cout << "1. Meters" << endl;
                cout << "2. Kilometers" << endl;
                cout << "3. Miles" << endl;
                cout << "4. Feet" << endl;

                while (true) {
                    cout << "Enter type:" << endl;
                    getline(cin, tmp_ntype);
                    if (satl::isInt(tmp_ntype)) {
                        if (stoi(tmp_ntype) < 5 || stoi(tmp_ntype) > 0) { break; }
                        cout << "Invalid type" << endl;
                    }
                }
                ntype = stoi(tmp_ntype);
                if (ntype == 1) { type = "meters"; }
                else if (ntype == 2) { type = "kilometers"; }
                else if (ntype == 3) { type = "miles"; }
                else if (ntype == 4) { type = "feet"; }
                else { type = "invalid"; }

                while (true) {
                    cout << "Enter value:" << endl;
                    getline(cin, tmp_value);
                    if (satl::isFloat(tmp_value)) { break; }
                    cout << "Invalid value" << endl;
                }
                value = stof(tmp_value);

                satl::converter(value, type);
                break;
            }
            case 3: {
                cout << "1. Kilograms" << endl;
                cout << "2. Grams" << endl;
                cout << "3. Pounds" << endl;

                while (true) {
                    cout << "Enter type:" << endl;
                    getline(cin, tmp_ntype);
                    if (satl::isInt(tmp_ntype)) {
                        if (stoi(tmp_ntype) < 4 || stoi(tmp_ntype) > 0) { break; }
                        cout << "Invalid type" << endl;
                    }
                }
                ntype = stoi(tmp_ntype);
                if (ntype == 1) { type = "kilograms"; }
                else if (ntype == 2) { type = "grams"; }
                else if (ntype == 3) { type = "pounds"; }
                else { type = "invalid"; }

                while (true) {
                    cout << "Enter value:" << endl;
                    getline(cin, tmp_value);
                    if (satl::isFloat(tmp_value)) { break; }
                    cout << "Invalid value" << endl;
                }
                value = stof(tmp_value);

                satl::converter(value, type);
                break;
            }
            case 4: {
                cout << "1. Seconds" << endl;
                cout << "2. Minutes" << endl;
                cout << "3. Hours" << endl;

                while (true) {
                    cout << "Enter type:" << endl;
                    getline(cin, tmp_ntype);
                    if (satl::isInt(tmp_ntype)) {
                        if (stoi(tmp_ntype) < 4 || stoi(tmp_ntype) > 0) { break; }
                        cout << "Invalid type" << endl;
                    }
                }
                ntype = stoi(tmp_ntype);
                if (ntype == 1) { type = "seconds"; }
                else if (ntype == 2) { type = "minutes"; }
                else if (ntype == 3) { type = "hours"; }
                else { type = "invalid"; }

                while (true) {
                    cout << "Enter value:" << endl;
                    getline(cin, tmp_value);
                    if (satl::isFloat(tmp_value)) { break; }
                    cout << "Invalid value" << endl;
                }
                value = stof(tmp_value);

                satl::converter(value, type);
                break;
            }
            case 5: {
                cout << "1. Liters" << endl;
                cout << "2. Milliliters" << endl;
                cout << "3. Gallons" << endl;

                while (true) {
                    cout << "Enter type:" << endl;
                    getline(cin, tmp_ntype);
                    if (satl::isInt(tmp_ntype)) {
                        if (stoi(tmp_ntype) < 4 || stoi(tmp_ntype) > 0) { break; }
                        cout << "Invalid type" << endl;
                    }
                }
                ntype = stoi(tmp_ntype);
                if (ntype == 1) { type = "liters"; }
                else if (ntype == 2) { type = "milliliters"; }
                else if (ntype == 3) { type = "gallons"; }
                else { type = "invalid"; }

                while (true) {
                    cout << "Enter value:" << endl;
                    getline(cin, tmp_value);
                    if (satl::isFloat(tmp_value)) { break; }
                    cout << "Invalid value" << endl;
                }
                value = stof(tmp_value);

                satl::converter(value, type);
                break;
            }
            case 6: {
                valid = false;
                break;
            }
            default: {
                cout << "Invalid operation" << endl;
            }
        }
        if (valid == false) { break; }
    }

    return 0;
}