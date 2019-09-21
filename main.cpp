#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Person
{
public:
    std::string name;
    int given;
    int recived;
    Person() : name(), given(0), recived(0) { }
     void give(int amount) { given = amount; }
     void receive(int amount) { recived += amount; }
     int total() { return recived - given; }
};


int main(){
    bool control = true;
    int n = 0;
    while (cin >> n){
        vector<Person> Index(n);
        map<string, Person*> Map;
        if (!control)
            cout<<endl;
        else control = false;
        for (auto & i : Index) {
            cin>>i.name;
            Map[i.name] = &i;
        }
        string giver, reciver;
        int numreciver = 0, numgiver = 0;
        for (int i = 0; i < n; ++i){
            cin>>giver>>numgiver>>numreciver;
            Person* ptr = Map[giver];
            for (int j = 0; j != numreciver; ++j){
                cin>>reciver;
                Map[reciver]->receive(numgiver / numreciver);
                ptr->give(numgiver - (numgiver % numreciver));
            }
        }

        for (auto & it : Index){
            cout<<it.name<<" "<<it.total()<<endl;
        }

    }
}

