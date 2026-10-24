#include <iostream>

using namespace std;

struct subscription {
    int id;
    string name;
    string category[3] = {"Study", "Entertaintment", "Other"};
    bool status;
};

int main()
{
    subscription app[3];
    
    string input;
    
    app[0].id = 1;
    app[0].name = input;
    
    cout << app[0].name;

    return 0;
}
