/* 
 * File:   hw6.cpp
 * Author: Roy Van Liew and Saqib Zahid
 *
 * Last updated on March 25th, 2014, 8:54 AM
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

// In login we assign a user ID to a valid computer station in a lab.
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
    
    return;
    
}

// In logoff we're checking if an entered user ID exists.
// If it does, set that computer status to "Empty"
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
        if( userID.length() != 5 )
            cout << "The ID entered was not 5 characters. Try again." << endl;        
    } while ( userID.length() != 5 );
    
    // Search through the labs.
    for( i = 0; i < d1; i++){
        // Here d2 is for the number of computers in that lab.
        d2 = labs[i].size();
        for( j = 0; j < d2; j++ ){
            // If the user is found, log that user off.
            if( labs[i][j] == userID ){
                labs[i][j] = "Empty"; // Indicate that the user logged off.
                cout << "User " << userID << " successfully logged off." << endl;
                return;
            }
        }
    }
    
    // If we get here that means the user was not found.
    cout << "This user is not logged in." << endl;
    
    return;
    
}

// Like logoff we are checking if a user ID exists.
// However we are just outputting which lab and station it is in.
void ComputerLabs::search_user(){
    
    string userID;
    int lab, comp;
    int d1 = labs.size(); // First dimension of labs vector
    int d2; // Second dimension of labs vector
    int i, j; // for loop counters.
    
    // Get User ID, 5 characters long.
    do {
        cout << "Enter User ID. It must be exactly 5 characters." << endl;
        cin >> userID;
        if( userID.length() != 5 )
            cout << "The ID entered was not 5 characters. Try again." << endl;
    } while ( userID.length() != 5 );
    
    // Search through the labs.
    for( i = 0; i < d1; i++){
        // Here d2 is for the number of computers in that lab.
        d2 = labs[i].size();
        for( j = 0; j < d2; j++ ){
            // If the user is found, specify the lab and the computer station.
            if( labs[i][j] == userID ){
                cout << "User " << userID << " found at Lab " << i << ", Station " << j << "." << endl;
                return;
            }
        }
    }
    
    // If we get here that means the user was not found.
    cout << "This user was not found." << endl;
    
    return;
    
}

// User specifies where in the first dimension of the vector to insert the new lab.
// Then if it is valid, create second dimension for that lab from what the user inputs for computers.
// Initialize all the computers in the new lab to Empty.
void ComputerLabs::addLab(){
    
    int lab, comp;
    int i; // for loop counters.
    int d1; // Number of labs
    d1 = labs.size(); // Valid positions for new lab.
    do {
        cout << "Currently there are labs 0 to " << d1-1 << "." << endl;
        cout << "At what position do you want the new lab?" << endl;
        cin >> lab;
        cout << "How many Computers do you want in this new lab?" << endl;
        cin >> comp;
        if( ( lab > d1 ) || lab < 0 )
            cout << "Invalid new lab position." << endl;
        if( comp < 0 )
            cout << "Cannot have negative computers." << endl;
    } while ( ( lab > d1 ) || lab < 0 || comp < 0 );
     
    vector<string> newlab;
    for (i = 0; i < comp ; i++ )
        newlab.push_back("Empty");
    labs.insert( labs.begin()+lab , newlab );
    
    return;
    
}

// Add a computer to an already existing lab.
// Get valid lab number first. If the lab is found, show user how many computers there are.
// The user can then state the position to enter the new computer.
void ComputerLabs::addComp(){
    
    int lab, comp;
    int d1 = labs.size(); // First dimension of labs vector
    int d2; // Second dimension of labs vector
    int i, j; // for loop counters.
    
    // Get a valid lab number.
    do {
        cout << "Currently there are labs 0 to " << d1-1 << "." << endl;
        cout << "What lab do you want the new computer in?" << endl;
        cin >> lab;
        if( ( lab > (d1-1) ) || lab < 0 )
            cout << "Invalid lab position." << endl;
    } while ( ( lab > (d1-1) ) || lab < 0 );
    
    d2 = labs[lab].size(); // Get how many computers are in that lab.
    do {
        cout << "Currently there are computers 0 to " << d2-1 << "." << endl;
        cout << "At what position do you want the new computer?" << endl;
        cin >> comp;
        if( ( comp > d2-1 ) || comp < 0 )
            cout << "Invalid new computer position." << endl;
    } while ( ( comp > d2-1 ) || comp < 0 );
    
    // Insert new computer in specified position of the lab.
    labs[lab].insert( labs[lab].begin()+comp , "Empty" );
    
    return;
    
}

// Remove a lab from the current list of labs (first dimension).
//void ComputerLabs::removeLab(){
//    
//    int lab;
//    int d1 = labs.size(); // First dimension of labs vector
//    int i; // for loop counter.
//    
//    // Get a valid lab number.
//    do {
//        cout << "There are currently " << d1 << " labs." << endl;
//        cout << "Which lab would you like to remove?" << endl;
//        cin >> lab;
//        if( ( lab > (d1-1) ) || lab < 0 )
//            cout << "Invalid lab position." << endl;
//    } while ( ( lab > (d1-1) ) || lab < 0 );
//    
//     // Remove the specified lab position.
//     labs.erase( lab );   
//    
//    return;
//    
//}

// Here a user specifies the lab to remove a computer from.
// After a valid lab is entered, a valid computer has to be entered.
//void ComputerLabs::removeComp(){
//    
//    int lab, comp;
//    int d1 = labs.size(); // First dimension of labs vector
//    int d2; // Second dimension of labs vector
//    int i, j; // for loop counters.
//    
//    // Get a valid lab number.
//    do {
//        cout << "There are currently " << d1 << " labs." << endl;
//        cout << "Which lab would you like to remove a computer?" << endl;
//        cin >> lab;
//        if( ( lab > (d1-1) ) || lab < 0 )
//            cout << "Invalid lab position." << endl;
//    } while ( ( lab > (d1-1) ) || lab < 0 );
//    
//    d2 = labs[lab].size(); // Get how many computers are in that lab.
//    do {
//        cout << "There are currently " << d2 << " computers." << endl;
//        cout << "At what position in this lab do you want to remove a computer?" << endl;
//        cin >> comp;
//        if( ( comp > d2-1 ) || comp < 0 )
//            cout << "Invalid new computer position." << endl;
//    } while ( ( comp > d2-1 ) || comp < 0 );
//    
//    labs.erase( labs[lab].begin() + comp );
//    
//}

int main() {
    
    ComputerLabs lab;
    lab.show_labs();
    
    cout << "\nAdd a lab." << endl;
    lab.addLab();
    lab.show_labs();
    
    cout << "\nAdd a computer." << endl;
    lab.addComp();
    lab.show_labs();
    
//    cout << "Attempting a login." << endl;
//    lab.login();
//    lab.show_labs();
//    
//    cout << "Attempting a logoff." << endl;
//    lab.logoff();
//    lab.show_labs();
    
    return 0;
}

