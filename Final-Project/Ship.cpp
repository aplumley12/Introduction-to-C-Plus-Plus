//////////// PACKAGES ////////////
#include <iostream>
#include <iomanip>
#include <istream>
#include <string>
#include <vector>
#include <windows.h>

//////////// NAMESPACE ////////////
using namespace std;

//////////// CLASS DEFINITION ////////////
class Ship {
    //////////// ATTRIBUTES ////////////
    private:
        // ship characterisitics //
        string ship_class;
        int size;
        int hits = 0;
        bool sunk = false;

        // positioning //
        int head_row;
        char head_col;

        // horizontal or vertical // 
        string orientation;

    //////////// CONSTRUCTOR METHOD ////////////
    public: Ship(string ship_class, string orientation, int head_row, char head_col) {
        this->ship_class = ship_class;
        this->orientation = orientation;
        this->head_row = head_row;
        this->head_col = head_col;
        // set the size attribute based on the ship's class upon initialization //
        setSize();
    }

    //////////// SET METHODS ////////////
    private: void setSize() {
        /*
        Sets the size attribute based on the ship's class
        Parameters: n/a
        Returns: void
        */
        if (ship_class == "CARRIER") {
            size = 5;
        } 
        if (ship_class == "BATTLESHIP") {
            size = 4;
        }
        if (ship_class == "CRUISER") {
            size = 3;
        }
        if (ship_class == "SUBMARINE") {
            size = 3;
        }
        if (ship_class == "DESTROYER") {
            size = 2;
        }
    }
    public: void hitShip() {
        /*
        Adds one hit to the ship and determines if it has sunk by comparing the
        current number of hits to the ship's size
        Parameters: n/a
        Returns: void
        */
        hits++;
        if(hits == size) {
            sunk = true;
        }
    }
    //////////// GET METHODS ////////////
    public: int getHits() {
        return hits;
    }
    public: string getOrientation() {
        return orientation;
    }
    public: int getSize() {
        return size;
    }
    public: int getHeadRow() {
        return head_row;
    }
    public: char getHeadCol() {
        return head_col;
    }
    public: string getShipClass() {
        return ship_class;
    }
    public: bool getSunk() {
        return sunk;
    }
};
