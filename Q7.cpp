#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // Seed random number generator so roasts differ each run
    srand(time(0));

    // Get user's name
    string name;
    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input bug fix
    if (name.empty()) {
        cout << "No name entered. Using 'Mystery Human' instead.\n";
        name = "Mystery Human";
    }

    // Store all roast templates with {name} as placeholder
    vector<string> roasts = {
        "{name} writes code so slow that even a turtle switched to Python.",
        "If procrastination were an Olympic sport, {name} would already have a gold medal.",
        "{name}'s debugging style is basically staring at the screen until the bug gets embarrassed and leaves.",
        "{name}'s code runs so slowly that even dial-up internet feels fast.",
        "If laziness had a brand ambassador, it would be {name}.",
        "{name} doesn't debug code — they negotiate with bugs.",
        "{name} once tried to compile a grocery list and got 47 errors.",
        "Scientists studied {name}'s commit history and declared it a natural disaster.",
        "{name}'s code has more comments saying 'fix later' than actual logic.",
        "Asking {name} to write clean code is like asking a cat to do homework.",
        "{name} has been 'almost done' with their project since last semester.",
        "The only thing {name} deploys on time is excuses."
    };

    // Randomly pick one roast
    int index = rand() % roasts.size();
    string roast = roasts[index];

    // Replace {name} placeholder with actual name
    string placeholder = "{name}";
    size_t pos = roast.find(placeholder);
    while (pos != string::npos) {
        roast.replace(pos, placeholder.length(), name);
        pos = roast.find(placeholder, pos + name.length());
    }

    // Display the roast
    cout << "\nYour Roast: " << roast << endl;

    return 0;
}
