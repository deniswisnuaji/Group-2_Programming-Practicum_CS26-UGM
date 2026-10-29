#include <iostream>

using namespace std;

const string categories[6] = {"Study", "Cloud", "Entertainment", "AI Tool", "Game", "Other"};

struct subscription {
    int id;
    string name;
    string category;
    double monthlyCost;
    int usage;
    bool isActive;
};

int main()
{
    int n;
    cout << "Enter the number of subscriptions: ";
    cin >> n;
    cin.ignore(); 

    subscription app[n];

    for (int i = 0; i < n; i++) {
        app[i].id = i + 1;

        cout << "\n=== Subscription no. " << i + 1 << " ===" << endl;
        cout << "Enter Name: ";
        getline(cin, app[i].name);
        
        cout << "Select a category " << endl;
        for (int j = 0; j < 6; j++) {
            cout << j + 1 << ". " << categories[j] << endl;
        }
        
        int categoryChoice;
        cout<<"Category number: ";
        cin >> categoryChoice;
        cin.ignore();
        
        if (categoryChoice >= 1 && categoryChoice <= 6) {
            app[i].category = categories[categoryChoice - 1];
        } else {
            cout << "Invalid category choice. Defaulting to 'Other'!\n";
            app[i].category = "Other";
        }

        cout << "Enter monthly cost: ";
        cin >> app[i].monthlyCost;
        cin.ignore();

       
        if (app[i].monthlyCost <= 0.0) {
            cout << "Monthly Cost Cannot be zero or negative!" << endl;
            return 0; 
        }
        
        cout << "Enter the usage frequency per week (0 - 7) for subscription: ";
        cin >> app[i].usage;
        cin.ignore();

        if (app[i].usage < 0 || app[i].usage > 7) {
            cout << "Invalid usage frequency. Usage frequency must be between 0 and 7!" << endl;
            return 0;
        }
        
        int activeChoice;
        cout << "Is the subscription active? (1 for Yes, 0 for No): ";
        cin >> activeChoice;
        cin.ignore();

        if (activeChoice != 1 && activeChoice != 0) {
            cout << "Invalid input. Please enter only 1 or 0!" << endl;
            return 0;
        }
        app[i].isActive = (activeChoice == 1);
    }

    cout << "\n=== Subscription(s) display ===" << endl;
    for (int i = 0; i < n; i++) {
        cout << "\n=== Subscription No. " << i + 1 << " ===" << endl;
        cout << "App ID        : " << app[i].id << endl;
        cout << "App Name      : " << app[i].name << endl;
        cout << "Category      : " << app[i].category << endl;
        cout << "Monthly cost  : " << app[i].monthlyCost << endl;
        cout << "Weekly usage  : " << app[i].usage << endl;
        cout << "Status        : ";
        if (app[i].isActive == 1) {
            cout << "Active" << endl;
        } else {
            cout << "Inactive" << endl;
        }
    }
    
    return 0;
}
