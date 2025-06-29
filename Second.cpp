#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter number of units: ";
    cin >> n;

    vector<int> units(n);
    cout << "Enter unit denominations: ";
    for (int i = 0; i < n; ++i) {
        cin >> units[i];
    }

    // Sort in ascending order, we'll use reverse later for greedy
    sort(units.begin(), units.end());

    int upperLimit;
    cout << "Enter the upper limit (exclusive): ";
    cin >> upperLimit;

    int totalUnitsUsed = 0;

    for (int amount = 1; amount < upperLimit; ++amount) {
        int remaining = amount;
        int unitsUsed = 0;

        for (int i = n - 1; i >= 0; --i) {
            int count = remaining / units[i];
            remaining -= count * units[i];
            unitsUsed += count;

            if (remaining == 0) break;
        }

        totalUnitsUsed += unitsUsed;

        // Optional: Print units used for each value
        // cout << amount << ": " << unitsUsed << " units used" << endl;
    }

    double averageUnits = static_cast<double>(totalUnitsUsed) / (upperLimit - 1);
    cout << fixed << setprecision(2);
    cout << "Average number of units used: " << averageUnits << endl;

    return 0;
}
