
#include <iostream>

using namespace std;

const string categories[6] = {"Study", "Cloud", "Entertainment", "AI Tool", "Game", "Other"};

struct subscription {
    int id;
    string name;
    string category;
    float mcost;
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
        
        cout << "Enter the name of subscription " << i + 1 << ": ";
        getline(cin, app[i].name);
        
        cout << "Select a category for subscription " << i + 1 << ":\n";
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
            cout << "Invalid category choice. Defaulting to 'Other'.\n";
            app[i].category = "Other";
        }

        cout << "Enter the monthly cost for subscription " << i + 1 << ": ";
        cin >> app[i].mcost;
        cin.ignore();
        
        cout << "Enter the usage frequency (per week) for subscription " << i + 1 << ": ";
        cin >> app[i].usage;
        cin.ignore();
        
        cout << "Is the subscription active? (1 for Yes, 0 for No): ";
        cin >> app[i].isActive;
        cin.ignore();
    }
    
    return 0;
}
