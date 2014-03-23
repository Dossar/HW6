/* 
 * File:   hw6.cpp
 * Author: Roy Van Liew and Saqib Zahid
 *
 * Last updated on March 23rd, 2014, 1:08 PM
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector> // C++ library for vectors

using namespace std;

class ComputerLabs
{
    
public:
    ComputerLabs(); // Default constructor
    ~ComputerLabs(); // Destructor
    void show_labs(); // Finished. Outputs the current status of the labs.
    void login();
    void logoff();
    void search_user();
    void addLab();
    void addComp();
    void removeLab();
    void removeComp();
    
private:
    // 1st dimension is lab number, 2nd dimension is user ID (computer).
    vector< vector<string> > labs;
    
};

// Default constructor for Computer Labs.
// Ask user to input number and sizes of the labs, and initialize labs to empty.
ComputerLabs::ComputerLabs() {
    
    int numOfLabs, computers;
    int i, j; // for loop counters.
    do {
        cout << "How many Computer Labs do you want?" << endl;
        cin >> numOfLabs;
        cout << "How many Computers do you want in each lab?" << endl;
        cin >> computers;
        if ( numOfLabs < 0 || computers < 0)
            cout << "Cannot have negative labs or computers. Try again." << endl;
    } while ( numOfLabs < 0 || computers < 0 );
    
    labs.resize(numOfLabs); // Make first dimension size of the labs dimension entered.
    for (i = 0; i < numOfLabs; i++){
        for (j = 0; j < computers ; j++)
                // Initialize second dimension with all empty stations.
                labs[i].push_back("Empty");
    }

}

// ComputerLabs destructor.
ComputerLabs::~ComputerLabs(){
    
}

// Display the current labs.
void ComputerLabs::show_labs() {

    int d1 = labs.size(); // First dimension of labs vector
    int d2; // Second dimension of labs vector
    int i, j; // for loop counters.

    // Output the stations and statuses of the computers.
    cout << "Labs:\tComputer Stations:" << endl;
    for( i = 0; i < d1; i++){
        // This cout statement is for the lab number
        cout << i << ":\t";
        // Here d2 is for the number of computers in that lab to output.
        d2 = labs[i].size();
        for( j = 0; j < d2; j++ )
            cout << j << ": " << labs[i][j] << ' ';
        cout << endl;
    }
    return;
    
}

void ComputerLabs::login(){
    
    string userID;
    int lab, comp;
    
    // Get User ID, 5 characters long.
    do {
        cout << "Enter User ID. It must be exactly 5 characters." << endl;
        cin >> userID;
    } while ( userID.length() != 5 );
    
    // Get the Lab and Computer Station.
    // These must be within the bounds of the vector.
    do {
        cout << "Specify Lab Number." << endl;
        cin >> lab;
        cout << "Specify Computer Station." << endl;
        cin >> comp;
        if ( ( lab > labs.size() || comp > labs[lab].size() ) || ( lab < 0 || comp < 0 ) )
            cout << "Invalid lab or computer station." << endl;
    } while( ( lab > labs.size() || comp > labs[lab].size() ) || ( lab < 0 || comp < 0 ) );
    
    // Assign the ID to that spot in the vector.
    labs[lab][comp] = userID;
    
}

void ComputerLabs::logoff(){
    
    string userID;
    int lab, comp;
    int d1 = labs.size(); // First dimension of labs vector
    int d2; // Second dimension of labs vector
    int i, j; // for loop counters.
    
    // Get User ID, 5 characters long.
    do {
        cout << "Enter User ID. It must be exactly 5 characters." << endl;
        cin >> userID;
    } while ( userID.length() != 5 );
    
    // Search through the labs.
    for( i = 0; i < d1; i++){
        // Here d2 is for the number of computers in that lab.
        d2 = labs[i].size();
        for( j = 0; j < d2; j++ ){
            // If the user is found, log that user off.
            if( labs[i][j] == userID ){
                labs[i][j] = "Empty"; // Indicate that the user logged off.
                cout << "User " << userID << " found at Lab " << i << " Station " << j << "." << endl;
                cout << "User " << userID << " successfully logged off." << endl;
                return;
            }
        }
    }
    
    // If we get here that means the user was not found.
    cout << "This user is not logged in." << endl;
    return;
    
}

int main() {
    
    ComputerLabs lab;
    lab.show_labs();
    
    cout << "Attempting a login." << endl;
    lab.login();
    lab.show_labs();
    
    cout << "Attempting a logoff." << endl;
    lab.logoff();
    lab.show_labs();
    
    return 0;
}

