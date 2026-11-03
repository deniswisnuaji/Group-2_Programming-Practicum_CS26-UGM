#include <iostream>
#include <string>
using namespace std;

const string categories[6] = {
    "Study", "Cloud", "Entertainment",
    "AI Tool", "Game", "Other"
};

const int MAX_SUBSCRIPTIONS = 255;

int menuChoice = 1;
bool loop = true;
int n = 0;

struct subscription {
    string id;
    string name;
    string category;
    double monthlyCost;
    int usage;
    bool isActive;
};

subscription app[MAX_SUBSCRIPTIONS];

void menu() {
    int choice;

    cout << "\n=== Student Subscription Manager ===" << endl;
    cout << "= 1. Display Subscription(s)       ===" << endl;
    cout << "= 2. Add Subscription(s)           ===" << endl;
    cout << "= 3. Search Subscription(s)        ===" << endl;
    cout << "= 4. Sort Subscription(s)          ===" << endl;
    cout << "= 0. Exit                          ===" << endl;
    cout << "======================================" << endl;
    cout << "Input choice: ";
    cin >> choice;

    menuChoice = choice;
}

void dummyData() {
    if (!app[0].id.empty()) {
        cout << "==== ERROR =========================================" << endl;
        cout << "Dummy data has been added or the memory is not empty!" << endl;
    } else {
        app[0].id = "App.03_01";
        app[0].name = "Netflix";
        app[0].category = categories[2];
        app[0].monthlyCost = 65000;
        app[0].usage = 3;
        app[0].isActive = true;

        app[1].id = "App.05_02";
        app[1].name = "Starlight Member";
        app[1].category = categories[4];
        app[1].monthlyCost = 125000;
        app[1].usage = 7;
        app[1].isActive = false;

        app[2].id = "App.04_03";
        app[2].name = "One Drive";
        app[2].category = categories[1];
        app[2].monthlyCost = 75000;
        app[2].usage = 3;
        app[2].isActive = true;

        cout << "Dummy data has been added successfully!" << endl;

        n = 3;
    }
}

void classifyCost(subscription out) {

    cout << "Cost Classification: ";

    if (out.monthlyCost <= 30000) {
        cout << "Low" << endl;
    }
    else if (out.monthlyCost <= 70000) {
        cout << "Medium" << endl;
    }
    else {
        cout << "High" << endl;
    }
}

void display(subscription out) {
    cout << "\nApp ID        : " << out.id << endl;
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

    classifyCost(out);
}

void addSubscription() {
    if (n >= MAX_SUBSCRIPTIONS) {
        cout << "Subscription storage is full!\n";
        return;
    }

    int amount;

    cout << "Enter the amount of data you want to add: ";
    cin >> amount;

    if (amount <= 0 || amount > MAX_SUBSCRIPTIONS - n) {
        cout << "Invalid number of subscriptions!\n";
        return;
    }

    for (int i = 0; i < amount; i++) {

        cout << "\n=== Subscription no. " << n + 1 << " ===\n";

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
            categoryChoice = 6;
        }

        app[n].id = "App.0" + to_string(categoryChoice)
                    + "_0" + to_string(n + 1);

        if (n > 8){
            app[n].id = "App.0" + to_string(categoryChoice)
                    + "_" + to_string(n + 1);
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
        }
        else if (activeChoice == 0) {
            app[n].isActive = false;
        }
        else {
            cout << "Please enter only 1 or 0!\n";
            return;
        }

        n++;

        cout << "Subscription added successfully!\n";
    }
}

void displaySubscription() {

    cout << "\n=== Subscription List ===\n";

    if (n == 0) {
        cout << "No subscriptions have been added yet.\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        cout << "\n=== Subscription No. " << i + 1 << " ===\n";
        display(app[i]);
    }
}

void linearSearch() {

    if (n == 0) {
        cout << "No subscriptions available to search!\n";
        return;
    }

    int searchChoice;
    string keyword;
    bool found = false;

    cout << "\n=== Search Subscription ===\n";
    cout << "1. Search by ID\n";
    cout << "2. Search by Name\n";
    cout << "3. Search by Category\n";
    cout << "Input choice: ";
    cin >> searchChoice;

    if (searchChoice < 1 || searchChoice > 3) {
        cout << "Invalid search choice!\n";
        return;
    }

    cout << "Enter search keyword: ";
    getline(cin >> ws, keyword);

    for (int i = 0; i < n; i++) {

        if (searchChoice == 1 && app[i].id == keyword) {
            display(app[i]);
            found = true;
        }

        else if (searchChoice == 2 &&
                 app[i].name.find(keyword) != string::npos) {
            display(app[i]);
            found = true;
        }

        else if (searchChoice == 3 &&
                 app[i].category == keyword) {
            display(app[i]);
            found = true;
        }
    }

    if (found == false) {
        cout << "Subscription not found!\n";
    }
}

void bubbleSort() {

    if (n == 0) {
        cout << "No subscriptions available to sort!\n";
        return;
    }

    int sortChoice;

    cout << "\n=== Sort Subscription ===\n";
    cout << "1. Monthly Cost (Lowest to Highest)\n";
    cout << "2. Monthly Cost (Highest to Lowest)\n";
    cout << "3. Weekly Usage (Lowest to Highest)\n";
    cout << "4. Weekly Usage (Highest to Lowest)\n";
    cout << "Input choice: ";
    cin >> sortChoice;

    if (sortChoice < 1 || sortChoice > 4) {
        cout << "Invalid sorting choice!\n";
        return;
    }

    for (int i = 0; i < n - 1; i++) {

        for (int j = 0; j < n - i - 1; j++) {

            bool swapNeeded = false;

            if (sortChoice == 1 &&
                app[j].monthlyCost > app[j + 1].monthlyCost) {
                swapNeeded = true;
            }

            else if (sortChoice == 2 &&
                     app[j].monthlyCost < app[j + 1].monthlyCost) {
                swapNeeded = true;
            }

            else if (sortChoice == 3 &&
                     app[j].usage > app[j + 1].usage) {
                swapNeeded = true;
            }

            else if (sortChoice == 4 &&
                     app[j].usage < app[j + 1].usage) {
                swapNeeded = true;
            }

            if (swapNeeded == true) {
                subscription temp = app[j];
                app[j] = app[j + 1];
                app[j + 1] = temp;
            }
        }
    }

    cout << "\nSubscriptions sorted successfully!\n";

    displaySubscription();
}

void close() {
    cout << "Bye-bye!" << endl;
    loop = false;
}

int main() {

    do {
        menu();

        switch (menuChoice) {

            case 1:
                displaySubscription();
                break;

            case 2:
                addSubscription();
                break;

            case 3:
                linearSearch();
                break;

            case 4:
                bubbleSort();
                break;

            case 99:
                dummyData();
                break;

            case 0:
                close();
                break;

            default:
                cout << "Invalid input!\n";
                break;
        }

    } while (loop == true);

    return 0;
}
