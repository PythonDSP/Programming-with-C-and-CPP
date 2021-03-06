// abstractClassEx.cpp

#include <iostream>
using namespace std;

class Jungle{
private: // not accessible outside the class
    string visitorName;

public:  // to allow access to function 'welcomeMessage' outside the class
    
    // setVisitorName is accessible outside the class, which will set the visitor name
    void setVisitorName(string name){
        visitorName = name;
    }

    // function to retrieve the visitorName as it is not accessible directly
    string getVisitorName(){
        return visitorName;
    }

    // welcome message
    void welcomeMessage(){
        cout << "Welcome to Jungle " << getVisitorName();
    }

    virtual void scarySound() = 0;
};

class Animal : public Jungle{
public:
    void scarySound(){
        cout << "Animals are running away due to scary sound." << endl;
    }
};

class Bird : public Jungle{
public:
    void scarySound(){
        cout << "Birds are flying away due to scary sound." << endl;
    }
};

// Now, it is compulsory to define 'scarySound' in Insect as well
class Insect : public Jungle{
public:
    void scarySound(){
        cout << "Insects do not care about scary sound." << endl;
    }
};

int main(){
    Animal a;
    Bird b;
    Insect i;

    a.scarySound();
    b.scarySound();
    i.scarySound();

    return 0;
}

/* Outputs
Animals are running away due to scary sound.
Birds are flying away due to scary sound.
Insects do not care about scary sound.
*/