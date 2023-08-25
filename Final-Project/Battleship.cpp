//////////// PACKAGES ////////////
#include <random>
#include <map>

//////////// IMPORTS ////////////
#include "Grid.cpp"

//////////// GLOBAL VARIABLES ////////////
vector<Ship> u_ships; // player ships
vector<Ship> o_ships; // opponent ships

int anchor_point[2] = {-1, -1};
string anchor_marker = "";

int prev_target[2] = {-1, -1};
int dir = -1;

string displayRules() {
    /*
    Displays the game rules in the console
    Paramaters: n/a
    Returns: string (rules)
    */
    string rules =  "\nSUMMARY:\n"
                    "C++ Battleship is a single-player, strategic guessing game played on a\n" 
                    "coordinate grid. Before starting the game, the player and computer opponent\n" 
                    "each place 5 ships of varying sizes on their grids. They then take turns\n"
                    "calling out coordinates and attempting to sink each other's fleet.\n\n"
                    "RULES:\n"
                    "   * Each player has 5 ships of different lengths: a CARRIER (5), a BATTLESHIP (4),\n"
                    "     a CRUISER (3), a SUBMARINE (3), and a DESTROYER (2).\n"
                    "   * If a player hits a target, their opponent must call out the coordinate and\n"
                    "     name of the ship.\n"
                    "   * To win, a player must sink their opponent's entire fleet\n\n";
    return rules;
}

string openGame() {
    /*
    Welcomes the player, prompts them to input their name, and asks whether they 
    would like to see the rules
    Parameters: n/a
    Returns: string (player's name)
    */
    string name;
    cout << "Welcome to C++ Battleship!\n\nEnter your name: ";
    cin >> name;
    string ans;
    do {
        cout << "\n" << name << ", would you like to see the rules? (y/n) ";
        cin >> ans;
    } while(!(ans == "y" || ans == "Y" || ans == "n" || ans == "N"));

    if(ans == "y" || ans == "Y") {
        cout << displayRules();
    }
    return name;
}

void placePlayerShips(Grid &grid) {
    /*
    Cycles through the five ship classes and prompts the player to place them on their 
    grid by choosing an orientation, row, and column
    Parameters: Grid object
    Returns: void
    */
    string ship_classes[5] = {"CARRIER", "BATTLESHIP", "CRUISER", "SUBMARINE", "DESTROYER"};
    string ortn;
    int row;
    char col;
    bool valid_input;
    bool valid_placement;
    for(string s : ship_classes) {
        cout << grid.displayGrid() << endl;
        do {
            cout << "Please place your " << s << "\n\n";
            do {
                cout << "ORIENTATION (H/V): ";
                cin >> ortn;
                cout << "ROW (0-9): ";
                cin >> row;
                cout << "COLUMN (A-J): ";
                cin >> col;
                col = toupper(col);

                valid_placement = (ortn == "H" || ortn == "V") && (row >= 0 || row <= 9) && (charToInt(col) >= 0 || charToInt(col) <= 9);
                if (!valid_placement) {
                    cout << "It seems the information you entered is not valid..." << endl;
                }
            } while(!valid_placement);
            if(ortn == "H") {
                ortn = "HORIZONTAL";
            }
            if(ortn == "V") {
                ortn = "VERTICAL";
            }

            Ship ship = Ship(s, ortn, row, col);
            valid_placement = grid.validPlacement(ship);
            if(valid_placement) {
                grid.setPosition(ship);
                u_ships.push_back(ship);
            } else {
                cout << "PLACEMENT FAILED!\nMake sure your ship does not fall off the grid or overlap with another ship!" << endl;
            }

        } while(!valid_placement);
    }
}
int randomNumberGenerator(int min, int max) {
    /*
    Generates a random number between the given minimum and maximum inclusive
    Parameters: int lower bound, int upperbound
    Returns int
    */
    random_device seed;
    mt19937 rng(seed());

    uniform_int_distribution<int> gen(min, max);

    int r = gen(rng);

    return r;
}
void placeOpponentShips(Grid &grid) {
    /*
    Cycles through the five ship classes and randomly places them on the opponent's grid
    --> continues to try placing a ship until it does not overflow the grid or overlap with
        another ship
    Parameters: Grid object
    Returns: void
    */
    string ship_classes[] = {"CARRIER", "BATTLESHIP", "CRUISER", "SUBMARINE", "DESTROYER"};
    int ortn;
    int row;
    char col;
    bool valid_placement;
    for(string s : ship_classes) {
        ortn = randomNumberGenerator(0, 1);
        switch(ortn) {
            case 0: // horizontal placement
                do {
                    row = randomNumberGenerator(0, 9);
                    col = intToChar(randomNumberGenerator(0, 10));
                    Ship ship = Ship(s, "HORIZONTAL", row, col);
                    valid_placement = grid.validPlacement(ship);
                    if(valid_placement) {
                        grid.setPosition(ship);
                        o_ships.push_back(ship);
                    }
                } while(!valid_placement);
                break;
            case 1: // vertical placement
                do {
                    row = randomNumberGenerator(0, 10);
                    col = intToChar(randomNumberGenerator(0, 9));
                    Ship ship = Ship(s, "VERTICAL", row, col);
                    valid_placement = grid.validPlacement(ship);
                    if(valid_placement) {
                        grid.setPosition(ship);
                        o_ships.push_back(ship);
                    }
                } while(!valid_placement);
                break;
        }
    } 
}

string markerToClass(string marker) {
    /*
    Converts a grid marker to the corresponding ship class using conditionals
    Paramters: string (marker)
    Returns: string (ship class)
    */
    string ship_class;
    if(marker == "C" ) {
        ship_class = "CARRIER";
    }
    if(marker == "B") {
        ship_class = "BATTLESHIP";
    }
    if(marker == "R") {
        ship_class = "CRUISER";
    }
    if(marker == "S") {
        ship_class = "SUBMARINE";
    }
    if(marker == "D") {
        ship_class = "DESTROYER";
    }
    return ship_class;
}

void attackShip(string marker, vector<Ship> &ships) {
    /*
    Attacks a ship based on its marker on the grid
    Parameters: string (marker), vector of Ship objects 
    Returns: void
    */
    if(marker == "C" ) {
        ships[0].hitShip();
    }
    if(marker == "B") {
        ships[1].hitShip(); 
    }
    if(marker == "R") {
        ships[2].hitShip(); 
    }
    if(marker == "S") {
        ships[3].hitShip(); 
    }
    if(marker == "D") {
        ships[4].hitShip();
    }
}

int markerToIndex(string marker) {
    /*
    Converts a grid marker to the corresponding ship in a player's ship vector using 
    conditionals and index values
    Parameters: string (marker)
    Returns: int (the index of a ship in the player's ship vector)
    */
    if(marker == "C" ) {
        return 0;
    }
    if(marker == "B") {
        return 1; 
    }
    if(marker == "R") {
        return 2; 
    }
    if(marker == "S") {
        return 3; 
    }
    if(marker == "D") {
        return 4;
    }
}

//////////// PLAYER TURN ////////////
void playerTurn(Grid &grid) {
    /*
    Prompts the player to choose a coordinate (row and column) on the computer opponent's grid
    to attack
    --> if the attack misses, "MISS" is printed to the console and the coordinate is marked with a "■" character
    --> if the attack hits, "HIT" and the ship class is displayed in the console (the coordinate is marked with an 'X' character)
    Parameters: Grid object
    Returns: void 
    */
    int row;
    char col;
    bool valid_coord;
    bool valid_attack = false;
    int index;
    string ship_class;
    do {
        do {
            cout << "Choose a coordinate to attack...\n";
            cout << "ROW (0-9): ";
            cin >> row;      
            cout << "COLUMN (A-J): ";
            cin >> col;
            col = toupper(col); // make sure the input is a capital letter 
            valid_coord = ((row >= 0 || row <= 9) && (charToInt(col) >= 0 || charToInt(col) <= 9));
                if (!valid_coord) {
                    cout << "It seems the information you entered is not valid..." << endl;
                }
        } while(!valid_coord);

        if(grid.getCoordinate(row, col) == "X" || grid.getCoordinate(row, col) == "■") {
            cout << "You have already attacked this location!" << endl;
        } else {
            valid_attack = true;
        }
    } while(!valid_attack);

    // if there is a ship at the inputed location, check what kind and update it
    string marker = grid.getCoordinate(row, col);

    // update the grid
    grid.updateGrid(row, col, "HIT");

    // determine console message
    if(grid.getCoordinate(row, col) == "■") {
        cout << "MISS!" << endl;
    } else if(grid.getCoordinate(row, col) == "X") {
        cout << "HIT! " << markerToClass(marker) << endl;
        attackShip(marker, o_ships);
        index = markerToIndex(marker);
        if(o_ships[index].getSunk()) {
            cout << "The opponent's " << markerToClass(marker) << " has sunk!" << endl;
        }
    }
}

//////////// OPPONENT TURN ////////////
// search for direction
void shipSighted(Grid &grid, int row, char col, string player_name) {
    /*
    Randomly targets coordinates adjacent to the initial hit on a ship (the anchor point)
    --> rerolls if the adjacent coordinate is off the grid or already hit
    Parameters: Grid object, int (row), char (column), string (player's name)
    Returns: void
    */
    int i_col;
    string marker;
    int index;
    bool valid_attack = false;
    do {
        dir = randomNumberGenerator(1, 4);
        switch(dir) {
            case 1: // UP
                row = anchor_point[0] - 1;
                col = intToChar(anchor_point[1]);
                // test for validity
                if(row >= 0) {
                    if(grid.getCoordinate(row, col) != "X" && grid.getCoordinate(row, col) != "■") {
                        valid_attack = true;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
                // set the previous marker and update the grid
                marker = grid.getCoordinate(row, col);
                grid.updateGrid(row, col, "HIT");

                // test if the coordinate is occupied
                if(grid.getCoordinate(row, col) == "■") {
                    cout << "THE OPPONENT HAS MISSED!" << endl;
                } else if (grid.getCoordinate(row, col) == "X") {
                    cout << "HIT! " << markerToClass(marker) << endl;
                    attackShip(marker, u_ships);
                    index = markerToIndex(marker);
                    if (marker == anchor_marker) {
                        prev_target[0] = row; prev_target[1] = charToInt(col);
                        dir = 1;
                    }
                    if(u_ships[index].getSunk()) {
                        cout << player_name << "'s "  << markerToClass(marker) << " has sunk!" << endl;
                    }
                }
                break;
            case 2: // DOWN
                row = anchor_point[0] + 1;
                col = intToChar(anchor_point[1]);
                // test for validity
                if(row <= 9) {
                    if(grid.getCoordinate(row, col) != "X" && grid.getCoordinate(row, col) != "■") {
                        valid_attack = true;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
                // set the previous marker and update the grid
                marker = grid.getCoordinate(row, col);
                grid.updateGrid(row, col, "HIT");

                // test if the coordinate is occupied
                if(grid.getCoordinate(row, col) == "■") {
                    cout << "THE OPPONENT HAS MISSED!" << endl;
                } else if (grid.getCoordinate(row, col) == "X") {
                    cout << "HIT! " << markerToClass(marker) << endl;
                    attackShip(marker, u_ships);
                    index = markerToIndex(marker);
                    if (marker == anchor_marker) {
                        prev_target[0] = row; prev_target[1] = charToInt(col);
                        dir = 2;
                    }
                    if(u_ships[index].getSunk()) {
                        cout << player_name << "'s "  << markerToClass(marker) << " has sunk!" << endl;
                    }
                }
                break;
            case 3: // LEFT
                row = anchor_point[0];
                i_col = anchor_point[1] - 1;
                col = intToChar(i_col);
                // test for validity
                if(i_col >= 0) {
                    if(grid.getCoordinate(row, col) != "X" && grid.getCoordinate(row, col) != "■") {
                        valid_attack = true;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
                // set the previous marker and update the grid
                marker = grid.getCoordinate(row, col);
                grid.updateGrid(row, col, "HIT");

                // test if the coordinate is occupied
                if(grid.getCoordinate(row, col) == "■") {
                    cout << "THE OPPONENT HAS MISSED!" << endl;
                } else if (grid.getCoordinate(row, col) == "X") {
                    cout << "HIT! " << markerToClass(marker) << endl;
                    attackShip(marker, u_ships);
                    index = markerToIndex(marker);
                    if (marker == anchor_marker) {
                        prev_target[0] = row; prev_target[1] = charToInt(col);
                        dir = 3;
                    }
                    if(u_ships[index].getSunk()) {
                        cout << player_name << "'s "  << markerToClass(marker) << " has sunk!" << endl;
                    }
                }
            case 4: // RIGHT
                row = anchor_point[0];
                i_col = anchor_point[1] + 1;
                col = intToChar(i_col);
                // test for validity
                if(i_col <= 9) {
                    if(grid.getCoordinate(row, col) != "X" && grid.getCoordinate(row, col) != "■") {
                        valid_attack = true;
                    } else {
                        break;
                    }
                } else {
                    break;
                }
                // set the previous marker and update the grid
                marker = grid.getCoordinate(row, col);
                grid.updateGrid(row, col, "HIT");

                // test if the coordinate is occupied
                if(grid.getCoordinate(row, col) == "■") {
                    cout << "THE OPPONENT HAS MISSED!" << endl;
                } else if (grid.getCoordinate(row, col) == "X") {
                    cout << "HIT! " << markerToClass(marker) << endl;
                    attackShip(marker, u_ships);
                    index = markerToIndex(marker);
                    if (marker == anchor_marker) {
                        prev_target[0] = row; prev_target[1] = charToInt(col);
                        dir = 4;
                    }
                    if(u_ships[index].getSunk()) {
                        // reset global variables
                        dir = -1;
                        anchor_point[0] = -1; anchor_point[1] = -1;
                        anchor_marker = "";
                        prev_target[0] = -1; prev_target[1] = -1;
                        // send console message
                        cout << player_name << "'s "  << markerToClass(marker) << " has sunk!" << endl;
                    }
                }
        }
    } while(!valid_attack);
}
void targetShip(Grid &grid, int row, char col, string player_name) {
    /*
    Targets coordinates in a line once the ship's orientation is discovered
    --> if the edge of the grid is reached, or an attack misses, the opponent will switch back to the anchor point
        and move in the opposite direction until the ship is sunk
    Parameters: Grid object, int (row), char (column), string (player's name)
    Returns: void
    */
    string marker;
    int index;
    int i_col;
    bool valid_attack = false;
    do{
        switch(dir) {
            case 1: // UP 
                row = prev_target[0] - 1;
                col = intToChar(prev_target[1]);
                // if the new target is not off the board
                if(row >= 0) {
                    // if the next target has not been hit
                    if(grid.getCoordinate(row, col) != "X" && grid.getCoordinate(row, col) != "■") {
                        valid_attack = true;
                    } else {
                        prev_target[0] = anchor_point[0]; prev_target[1] = anchor_point[1];
                        dir = 2;
                        break;
                    }
                } else {
                    prev_target[0] = anchor_point[0]; prev_target[1] = anchor_point[1];
                    dir = 2; // switch direction to down
                    break;
                }
                break;
            case 2: // DOWN
                row = prev_target[0] + 1;
                col = intToChar(prev_target[1]);
                // if the new target is not off the board
                if(row <= 9) {
                    // if the new target has not been hit
                    if(grid.getCoordinate(row, col) != "X" && grid.getCoordinate(row, col) != "■") {
                        valid_attack = true;
                    } else {
                        prev_target[0] = anchor_point[0]; prev_target[1] = anchor_point[1];
                        dir = 1;
                    }
                } else {
                    prev_target[0] = anchor_point[0]; prev_target[1] = anchor_point[1];
                    dir = 1; // switch direction to up 
                }
                break;
            case 3: // LEFT
                row = prev_target[0];
                i_col = prev_target[1] - 1;
                col = intToChar(i_col);
                // if the new target is not off the board
                if(i_col >= 0) {
                    // if the new target has not been hit
                    if(grid.getCoordinate(row, col) != "X" && grid.getCoordinate(row, col) != "■") {
                        valid_attack = true;
                    } else {
                        prev_target[0] = anchor_point[0]; prev_target[1] = anchor_point[1];
                        dir = 4; // switch direction to right
                    }
                } else {
                    prev_target[0] = anchor_point[0]; prev_target[1] = anchor_point[1];
                    dir = 4;
                }
                break;
            case 4: // RIGHT
                row = prev_target[0];
                i_col = prev_target[1] + 1;
                col = intToChar(i_col);
                // if the new target is not off the board
                if(i_col <= 9) {
                    // if the new target has not been hit
                    if(grid.getCoordinate(row, col) != "X" && grid.getCoordinate(row, col) != "■") {
                        valid_attack = true;
                    } else {
                        prev_target[0] = anchor_point[0]; prev_target[1] = anchor_point[1];
                        dir = 3; // switch direction to left
                    }
                } else {
                    prev_target[0] = anchor_point[0]; prev_target[1] = anchor_point[1];
                    dir = 3;
                }
                break;
        }
    } while(!valid_attack);

    marker = grid.getCoordinate(row, col);
    grid.updateGrid(row, col, "HIT");

    if(grid.getCoordinate(row, col) == "■") {
        cout << "THE OPPONENT HAS MISSED!" << endl;
        prev_target[0] = anchor_point[0]; prev_target[1] = anchor_point[1];
        if(dir == 1 || dir == 3) {
            dir += 1; // switch direction for next turn
        } else if(dir == 2 || dir == 4) {
            dir -= 1; // switch direction for next turn
        }
    } else if(grid.getCoordinate(row, col) == "X") {
        cout << "HIT! " << markerToClass(marker) << endl;
        attackShip(marker, u_ships);
        index = markerToIndex(marker);
        if(marker == anchor_marker) {
            // set previous target to current target
            prev_target[0] = row; prev_target[1] = charToInt(col);
        } else {
            prev_target[0] = anchor_point[0]; prev_target[1] = anchor_point[1];
            if(dir == 1 || dir == 3) {
                dir += 1; // switch direction for next turn
            } else if(dir == 2 || dir == 4) {
                dir -= 1; // switch direction for next turn
            }
        }
        if(u_ships[index].getSunk()) {
            // reset global variables
            dir = -1;
            anchor_point[0] = -1; anchor_point[1] = -1;
            anchor_marker = "";
            prev_target[0] = -1; prev_target[1] = -1;
            // console message
            cout << player_name << "'s " << markerToClass(marker) << "has sunk!" << endl;
        }
    }
}

void opponentTurn(Grid &grid, string player_name) {
    /*
    Chooses a random coordinate (row and column) on the player's grid to attack by calling the randomNumberGenerator() function
    --> if the attack misses, "MISS" is printed to the console and the coordinate is marked with a "■" character
    --> if the attack hits, "HIT" and the ship class is displayed in the console (the coordinate is marked with an 'X' character)
    Parameters: Grid object, string (player's name)
    Returns: void 
    */
    int row;
    char col;
    bool valid_attack = false;
    int index;
    if(dir != -1) {
        targetShip(grid, row, col, player_name);
        return;
    }
    if(anchor_point[0] != -1) { // if there is a defined anchor point...
        shipSighted(grid, row, col, player_name);
        return;
    }
    do{
        // generate random target
        row = randomNumberGenerator(0, 9);
        col = intToChar(randomNumberGenerator(0, 9));
        // test validity
        if (!(grid.getCoordinate(row, col) == "■" || grid.getCoordinate(row, col) == "X")) {
            valid_attack = true;
        }
    } while(!valid_attack);

    // test if the ship has sunk
    string marker = grid.getCoordinate(row, col);

    // update the player's grid
    grid.updateGrid(row, col, "HIT");

    // determine console message
    if(grid.getCoordinate(row, col) == "■") {
        cout << "THE OPPONENT HAS MISSED!" << endl;
    } else if(grid.getCoordinate(row, col) == "X") {
        cout << "HIT! " << markerToClass(marker) << endl;
        attackShip(marker, u_ships);
        index = markerToIndex(marker);
        // set anchor point information
        anchor_point[0] = row;
        anchor_point[1] = charToInt(col);
        anchor_marker = marker;
        if(u_ships[index].getSunk()) {
            cout << player_name << "'s " << markerToClass(marker) << " has sunk!" << endl;
        }
    }

}
bool fleetDestroyed(string player) {
    /*
    Tests if the game has ended by checking the sunk status of each ship in the player's or opponent's
    ships vector (determined by the argument)
    Parameters: string (player type: "USER" or "OPPONENT")
    Returns: boolean (true if the game has ended, false if it has not)
    */
    if(player == "USER") {
        for(Ship ship : u_ships) {
            if(!ship.getSunk()) {
                return false;
            }
        } 
        return true;
    }
    for(Ship ship : o_ships) {
        if(!ship.getSunk()) {
            return false;
        }
    } 
        return true;
}

main() {
    /*
    Main functin --> runs the game by calling the other functions
    */
    string player_name = openGame();
    // create grids //
    Grid u_grid = Grid("USER");
    Grid o_grid = Grid("USER"); 

    placePlayerShips(u_grid);
    cout << u_grid.displayGrid() << endl;

    placeOpponentShips(o_grid);

    // main gameplay //
    cout << "TIME TO ATTACK!" << endl;

    bool game_end = false;
    while(!game_end) {
        playerTurn(o_grid);
        game_end = fleetDestroyed("OPPONENT");
        if(!game_end) {
            opponentTurn(u_grid, player_name);
            cout << u_grid.displayHorizontal(o_grid) << endl;
            game_end = fleetDestroyed("USER");
            if(game_end) {
                cout << "Your fleet has been destroyed! Better luck next time!" << endl;
            }
        } else {
            cout << "Your opponent's fleet has been destroyed! YOU WIN!" << endl;
        }
    }
}
