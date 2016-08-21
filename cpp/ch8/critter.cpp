#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <typeinfo>

using namespace std;

class critter
{
    int mHunger;
    int mBoredom;
    int getMood() const;
    
public:
    critter(int hunger = 0, int boredom = 0):
    mHunger(hunger),
    mBoredom(boredom)
    {}
    void passTime(int time = 1);
    void talk();
    void eat(int food = 4);
    void play(int fun = 4);
    int getHunger() const;
    int getBoredom() const;
};

int critter::getHunger() const
{
    return mHunger;
}

int critter::getBoredom() const
{
    return mBoredom;
}

inline int critter::getMood() const
{
    return mHunger + mBoredom;   
}

void critter::passTime(int time)
{
    mHunger += time;
    mBoredom += time;
}

void critter::talk()
{
    cout << "I'm a critter and i feel ";
    int mood = getMood();
    mood /= 5;
    
    switch(mood)
    {
        case 0:
            cout << "happy";
            break;
        case 1:
            cout << "okay";
            break;
        case 2:
            cout << "frustrated";
            break;
        default:
            cout << "mad";
            break;
    }
    
    cout << endl;
    passTime();
}

void critter::eat(int food)
{
    cout << "Brruppp." << endl;
    mHunger -= food;
    if (mHunger < 0)
        mHunger = 0;
        
    passTime();    
}

void critter::play(int boredom)
{
    cout << "Wheee!" << endl;
    mBoredom -= boredom;
    if (mBoredom < 0)
        mBoredom = 0;
        
    passTime();    
}

int main()
{
    char quit = false;
    int choice = 0;
    
    critter crit;
    crit.talk();
    
    while (!quit)
    {
        cout << endl;
        cout << "Critter's hunger level: " << crit.getHunger() << endl;
        cout << "Critter's boredom level: " << crit.getBoredom() << endl;
        cout << endl;
        cout << "Choose action:" << endl;
        cout << "1 - Listen to your critter" << endl;
        cout << "2 - Feed your critter" << endl;
        cout << "3 - Play with your critter" << endl;
        cout << "4 - Quit" << endl;
        cout << "Choice: ";
        cin >> choice;
        cout << endl;
        switch(choice)
        {
            case 1:
                crit.talk();
                break;
            case 2:
                crit.eat();
                break;
            case 3:
                crit.play();
                break;
            case 4:
                quit = true;
                break;
            default:
                cout << "Sorry, bad choice" << endl;
                break;
        }
    }
    
    cout << "Good-bye!" << endl;
    
    return 0;
}