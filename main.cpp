#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string convert(const string &input)
{
    string output = input;
    transform(output.begin(), output.end(), output.begin(), ::tolower);
    if (!output.empty())
    {
        output[0] = toupper(output[0]);
    }
    return output;
}

int main()
{

    string userInput;

    cout << "Need travel vaccines? Plan ahead before you travel.\n";
    cout << "Enter a country: ";
    getline(cin, userInput);

    userInput = convert(userInput); // Clean the input to match the format in the file

    ifstream file("vaccines copy.csv"); // data file

    string headerLine;
    getline(file, headerLine); // Skip the header line

    string line;
    bool found = false; // flag

    while (getline(file, line))
    {
        stringstream ss(line); // break the line for smaller parts
        string country, required, recommended;

        getline(ss, country, ','); // stored a data from line
        getline(ss, required, ',');
        getline(ss, recommended);

        if (convert(country) == userInput)
        {
            cout << "\nVaccination info for " << country << ":\n";

            bool hasRequired = !required.empty(); // checkig the data
            bool hasRecommended = !recommended.empty();

            if (hasRequired)
            {
                cout << "Required: " << required << endl;
            }
            else
            {
                cout << "No required vaccinations.\n";
            }

            if (hasRecommended)
            {
                cout << "Recommended: " << recommended << endl;
            }
            else
            {
                cout << "No recommended vaccinations.\n";
            }

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Country not found.\n";
    }

    return 0;
}
