#include <iostream>

using namespace std;

const string categories[6] = {"Study", "Cloud", "Entertaintment", "AI Tool", "Game", "Other"};

struct subscription {
    int id;
    string name;
    string category;
    bool status;
};

int main()
{
    for (int i=0; i<n; i++){
    subscription app[n];
    
    app[0].id = 1;
    app[0].name = "Netflix";
    app[0].category = categories[0];
    
    cout << app[0].name << endl;
    cout << app[0].category;
    }
    return 0;
}
