#include <iostream>

using namespace std;

const string categories[3] = {"Study", "Entertaintment", "Other"};

struct subscription {
    int id;
    string name;
    string category;
    bool status;
};

int main()
{
    subscription app[3];
    
    app[0].id = 1;
    app[0].name = "Netflix";
    app[0].category = categories[0];
    
    cout << app[0].name << endl;
    cout << app[0].category;

    return 0;
}
