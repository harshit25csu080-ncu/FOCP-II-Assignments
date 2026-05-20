#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    string name, subject, hw;

    cout << "Name: ";
    getline(cin, name);

    cout << "Subject: ";
    getline(cin, subject);

    cout << "Homework: ";
    getline(cin, hw);

    if(name=="") name="Student";
    if(subject=="") subject="Math";
    if(hw=="") hw="assignment";

    vector<string> excuses =
    {
        name + " was emotionally not ready for the " + hw + " 😭",

        "The " + subject + " " + hw + " looked at " + name + " and won 💀",

        name + " opened the notebook and instantly got sleepy 😴",

        "WiFi and motivation both disappeared together 😂",

        name + " got distracted by YouTube for 5 hours 📱",

        "Even Google looked confused by this " + hw + " 😭",

        name + " planned to study but the bed said no 🛌",

        "The brain stopped working during the " + subject + " homework ⚡",

        name + " and homework have a toxic relationship 💅",

        "One question of the " + hw + " caused full mental damage 💀"
    };

    cout << "\n📚 Excuse:\n";
    cout << excuses[rand() % excuses.size()];

    return 0;
}
