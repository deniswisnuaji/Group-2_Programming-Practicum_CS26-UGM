#include <iostream>

using namespace std;

const string categories[6] = {"Study", "Cloud", "Entertainment", "AI Tool", "Game", "Other"};

struct subscription {
    int id;
    string name;
    string category;
    double monthlyCost; //pake double ; standarnya nama variabel tuh harus udah jelas itu untuk apa, pake camel case.
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

        cout << "\n=== Subscription no. " << i + 1 << " ===" << endl; // formattingnya better gini, but yang kemaren dibikin is fine.
        cout << "Enter Name: ";
        getline(cin, app[i].name);
        
        cout << "Select a category ";
        for (int j = 0; j < 6; j++) {
            cout << j + 1 << ". " << categories[j] << endl;
        }
        // nambahin enter di sini biar rapi. ntar komen ini hapus aja
        int categoryChoice;
        cout<<"Category number: ";
        cin >> categoryChoice;
        cin.ignore();
        // enter
        if (categoryChoice >= 1 && categoryChoice <= 6) {
            app[i].category = categories[categoryChoice - 1];
        } else {
            cout << "Invalid category choice. Defaulting to 'Other'.\n";
            app[i].category = "Other";
        }

        cout << "Enter monthly cost: "; // masih sama, ngurangi redundansi
        cin >> app[i].monthlyCost;
        cin.ignore();

        //nambahin validasi buat nge-eliminasi nilai negative
        if (app[i].monthlyCost <= 0.0) {
            cout << "Monthly Cost Cannot be negative!" << endl;
            return 0; // sementara kita buat programnya otomatis exit, di next weeks kita perbaiki.
        }
        
        cout << "Enter the usage frequency (per week) for subscription: ";
        cin >> app[i].usage;
        cin.ignore();

        // tolong tambahin validasi buat frekuensi penggunaan per minggu yaa (range 1 - 7) ; else display error -> return 0.
        
        cout << "Is the subscription active? (1 for Yes, 0 for No): ";
        cin >> app[i].isActive;
        cin.ignore();

        // ini juga, validasiin buat 1/0 aja yaa.
    }

    // ini udah kubikinin displaynya, silahkan dipahami logikanya yaa..
    cout << "\n=== Displaying the struct ===" << endl;
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
