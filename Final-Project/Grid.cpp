//////////// PACKAGES ////////////
#include "Ship.cpp"

//////////// FUNCTIONS ////////////
int charToInt(char c) {
    /*
    Converts a char to an int such that 'A' = 0, 'B' = 1, 
    'C' = 2, etc.
    Parameters: char (the letter to be converted)
    Returns: int (the integer corresponding to the passed character)
    */
    int i = c - 65;
    return i;
};

char intToChar(int i) {
    char c = i + 65;
    return c;
}

//////////// CLASS DEFINITION ////////////
class Grid {
    //////////// ATTRIBUTES ////////////
    private:
        vector<vector<string>> grid;
        string type;
        
    //////////// CONSTRUCTOR METHOD ////////////
    public: Grid(string type) {
        this->type = type;
        buildGrid();
    }
    //////////// GET METHODS ////////////
    public: string getCoordinate(int row, char col) {
        /*
        Finds a coordinate given its row and column labels and returns its
        corresponding string marker
        */
        return grid[row][charToInt(col)];
    } 
    public: string getOwner() {
        /*
        Returns the owner of the grid ("USER" or "OPPONENT")
        */
        return type;
    }
    //////////// BUILDING AND UPDATING THE GRID ////////////
    public: void buildGrid() {
        /*
        Builds the Grid object by pushing strings (coordinates) onto a 2D vector
        Parameters: n/a
        Returns: void
        */
        for(int r = 0; r < 10; r++) {
            vector<string> row;
            for(int c = 0; c < 10; c++) {
                row.push_back("□");
            } grid.push_back(row);
        }
    }
    public: string displayGrid() {
        /*
        Converts a Grid object to a string that can be printed to the terminal
        Parameters: n/a
        Returns: string representation of the Grid object 
        */
        string char_coords[] = {"  A", "B", "C", "D", "E", "F", "G", "H", "I", "J"}; // column coordinates displayed as letters
        string num_coords[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}; // row coordinates displayed as numbers
        string strGrid = ""; // empty string grid container

        for(string elt : char_coords) {
            strGrid += elt + " ";
        } strGrid += "\n";
        for(int r = 0; r < 10; r++) {
            strGrid += num_coords[r] + " ";
            for(int c = 0; c < 10; c++) {
                if(grid[r][c] == "C" || grid[r][c] == "B" || grid[r][c] == "R" || grid[r][c] == "S" || grid[r][c] == "D") {
                    strGrid += "▲ ";
                } else {
                    strGrid += grid[r][c] + " ";
                }
            } strGrid += "\n";
        }
        return strGrid;
    }
    public: string displayHorizontal(Grid &o_grid) {
        /*
        Converts the player's and computer opponent's grids to a string that positions them side-by-side
        when printed to the terminal
        Parameters: Grid object (the opponent's grid)
        Returns: string representation of the two Grid objects
        */
        string char_coords[] = {"  A", "B", "C", "D", "E", "F", "G", "H", "I", "J"}; // column coordinates displayed as letters
        string num_coords[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}; // row coordinates displayed as numbers
        string strDualGrid = ""; // empty string grid container

        for(string elt: char_coords) {
            strDualGrid += elt + " ";
        }
        strDualGrid += "               " + strDualGrid + "\n";

        for(int r = 0; r < 10; r++) {
            strDualGrid += num_coords[r] + " ";
            for(int uc = 0; uc < 10; uc++) {
                if(grid[r][uc] == "C" || grid[r][uc] == "B" || grid[r][uc] == "R" || grid[r][uc] == "S" || grid[r][uc] == "D") {
                    strDualGrid += "▲ ";
                } else {
                    strDualGrid += grid[r][uc] + " ";
                }
            }

            strDualGrid = strDualGrid + "               " + num_coords[r] + " ";

            for(int oc = 0; oc < 10; oc ++) {
                if(o_grid.getCoordinate(r, intToChar(oc)) == "C" || o_grid.getCoordinate(r, intToChar(oc)) == "B" || o_grid.getCoordinate(r, intToChar(oc)) == "R" || o_grid.getCoordinate(r, intToChar(oc)) == "S" || o_grid.getCoordinate(r, intToChar(oc)) == "D") {
                    strDualGrid += "□ ";
                } else {
                    strDualGrid += o_grid.getCoordinate(r, intToChar(oc)) + " ";
                }
            } 
            
            strDualGrid += "\n";
        }

        return strDualGrid;
    }

    // update grid //
    public: void updateGrid(int row, char col, string action, string ship_type = "") {
        /*
        Updates the marker of a specific coordinate on the Grid given one of two actions. 
        --> When set to hit, the coordinate's marker is either changed to an "X" if there is a ship, or "■" if it is empty
        --> When set to occupied, the coordinate's marker is changed to an uppercase letter corresponding to the ship class
        Parameters: int (row label), char (column label), string ("HIT" or "OCCUPY"), string (ship class)
        Returns: void  
        */
        // hit occupied coordinate
        if(action == "HIT" && (grid[row][charToInt(col)] == "C" || grid[row][charToInt(col)] == "B" || grid[row][charToInt(col)] == "R" || grid[row][charToInt(col)] == "S" || grid[row][charToInt(col)] == "D")) {
            grid[row][charToInt(col)] = "X";
        // hit empty coordinate
        } else if(action == "HIT") {
            grid[row][charToInt(col)] = "■";
        } else if(action == "OCCUPY") {
            // set marker based on ship type
            if(ship_type == "CARRIER") {
                grid[row][charToInt(col)] = "C";
            }
            if(ship_type == "BATTLESHIP") {
                grid[row][charToInt(col)] = "B";
            }
            if(ship_type == "CRUISER") {
                grid[row][charToInt(col)] = "R";
            }
            if(ship_type == "SUBMARINE") {
                grid[row][charToInt(col)] = "S";
            }
            if(ship_type == "DESTROYER") {
                grid[row][charToInt(col)] = "D";
            }
        }
    }
    public: bool validCoordinate(int row, int col) {
        /*
        Tests if a coordinate given by the player is on the grid
        --> The row must be between 0 and 9 inclusive and the column must be between
            A and J (0 and 9) inclusive
        Parameters: int (row label), int (column label)
        Returns: Boolean (false if the input is invalid, true if the input is valid)
        */
        if ((row < 0 || row > 9) || (col < 0 || col > 9)) {
            return false;
        } 
        return true;
    }
    public: bool validPlacement(Ship ship) {
        /*
        Tests if a ship can be placed based on orientation and size
        --> A ship cannot be placed if it overflows the grid or overlaps another ship
        Parameters: Ship object
        Returns: Boolean (false if the placement is invalid, and true if the placement is valid)
        */
        // location
        int head_row = ship.getHeadRow();
        int head_col = charToInt(ship.getHeadCol());

        // check that the starting coordinate is on the grid
        if(!validCoordinate(head_row, head_col)) {
            return false;
        }
        // check if ship fits on the grid
        if(ship.getOrientation() == "HORIZONTAL" && ((head_col + ship.getSize()) > 10)) {
            return false;
        }
        if(ship.getOrientation() == "VERTICAL" && ((head_row + ship.getSize()) > 10)) {
            return false;
        }
        // check if the ship overlaps with another ship
        if(ship.getOrientation() == "HORIZONTAL") {
            for(int c = 0; c < ship.getSize(); c++) {
                if(grid[head_row][head_col + c] != "□") {
                    return false;
                }
            }
        }
        if(ship.getOrientation() == "VERTICAL") {
            for(int r = 0; r < ship.getSize(); r++) {
                if(grid[head_row + r][head_col] != "□") {
                    return false;
                }
            }
        }
        return true;
    }
    public: void setPosition(Ship ship) {
        /*
        Places a ship on the grid based on orientation and size
        Parameters: Ship object
        Returns: void
        */
        if(validPlacement(ship)) {
            if(ship.getOrientation() == "HORIZONTAL") {
                for(int i = 0; i < ship.getSize(); i++) {
                    updateGrid(ship.getHeadRow(), ship.getHeadCol() + i, "OCCUPY", ship.getShipClass());
                }
            }
            if(ship.getOrientation() == "VERTICAL") {
                for(int i = 0; i < ship.getSize(); i++) {
                    updateGrid(ship.getHeadRow() + i, ship.getHeadCol(), "OCCUPY", ship.getShipClass());
                }
            }
        } else {
            cout << "placement failed!" << endl;
        }
    }
};
