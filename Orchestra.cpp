#include "Orchestra.h"


// default constructor
Orchestra::Orchestra() {
    max_size = 0;
    current_size = 0;
}          

// constructor for an orchestra of given size
Orchestra::Orchestra(int size) {
    max_size = size;
    current_size = 0;
    members = new Musician[size];
}

Orchestra::~Orchestra(){
    delete[] members;
}

// returns the number of musicians who have joined the orchestra
int Orchestra::get_current_number_of_members() {
    return current_size;
}

// returns true if any musician in the orchestra plays the specified instrument
// otherwise returns false
bool Orchestra::has_instrument(std::string instrument){
    for (int i = 0; i < current_size; i++) {
        if (members[i].get_instrument() == instrument){
            return true;
        }
    }
    return false;
}

// returns the array of members of the orchestra
Musician *Orchestra::get_members(){
    return members;
}      

// returns true and adds new musician to the orchestra if the orchestra is not full
// otherwise returns false
bool Orchestra::add_musician(Musician new_musician){
    if (current_size < max_size) {
        members[current_size] = new_musician;
        current_size++;
        return true;
    }
    return false;
}

