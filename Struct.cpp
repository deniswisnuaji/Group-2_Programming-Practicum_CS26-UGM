
#include <iostream>
#include <string>
using namespace std;

const string categories[6] = {"Study", "Cloud", "Entertainment", "AI Tool", "Game", "Other"};

const int MAX_SUBSCRIPTIONS = 100;

struct subscription {
    int id;
    string name;
    string category;
    double monthlyCost;
    int usage;
    bool isActive;
};

subscription app[MAX_SUBSCRIPTIONS];
int n = 0;

void display(subscription out) {
    cout << "App ID        : " << out.id << endl;
    cout << "App Name      : " << out.name << endl;
    cout << "Category      : " << out.category << endl;
    cout << "Monthly cost  : " << out.monthlyCost << endl;
    cout << "Weekly usage  : " << out.usage << endl;
    cout << "Status        : ";

    if (out.isActive == true) {
        cout << "Active" << endl;
    } else {
        cout << "Inactive" << endl;
    }
}

void addSubscription() {
    if (n >= MAX_SUBSCRIPTIONS) {
        cout << "Subscription storage is full!\n";
        return;
    }

    int amount;

    cout << "How many subscriptions do you want to add? ";
    cin >> amount;

    if (amount <= 0 || amount > MAX_SUBSCRIPTIONS - n) {
        cout << "Invalid number of subscriptions!\n";
        return;
    }

    for (int i = 0; i < amount; i++) {
        app[n].id = n + 1;

        cout << "\n=== Subscription no. "<< app[n].id << " ===\n";

        cout << "Enter Name: ";
        getline(cin >> ws, app[n].name);

        cout << "Select a category:\n";

        for (int j = 0; j < 6; j++) {
            cout << j + 1 << ". " << categories[j] << endl;
        }

        int categoryChoice;
        cout << "Category number: ";
        cin >> categoryChoice;

        if (categoryChoice >= 1 && categoryChoice <= 6) {
            app[n].category = categories[categoryChoice - 1];
        } else {
            cout << "Invalid category. Defaulting to Other.\n";
            app[n].category = "Other";
        }

        cout << "Enter monthly cost: ";
        cin >> app[n].monthlyCost;

        if (app[n].monthlyCost <= 0) {
            cout << "Monthly cost must be greater than zero!\n";
            return;
        }

        cout << "Enter weekly usage (0 - 7): ";
        cin >> app[n].usage;

        if (app[n].usage < 0 || app[n].usage > 7) {
            cout << "Usage must be between 0 and 7!\n";
            return;
        }

        int activeChoice;
        cout << "Is the subscription active? (1 = Yes, 0 = No): ";
        cin >> activeChoice;

        if (activeChoice == 1) {
            app[n].isActive = true;
        } else if (activeChoice == 0) {
            app[n].isActive = false;
        } else {
            cout << "Please enter only 1 or 0!\n";
            return;
        }

        n++;

        cout << "Subscription added successfully!\n";
    }
}

void displaySubscription() {
    if (n == 0) {
        cout << "No subscriptions have been added yet.\n";
        return;
    }

    cout << "\n=== Subscription List ===\n";

    for (int i = 0; i < n; i++) {
        cout << "\n=== Subscription No. "
             << i + 1 << " ===\n";

        display(app[i]);
    }
}

int main() {
    addSubscription();
    displaySubscription();
    return 0;
}
