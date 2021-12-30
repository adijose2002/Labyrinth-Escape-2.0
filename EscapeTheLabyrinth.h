#include <utility>
#include <random>
#include <set>
#include "grid.h"
#include "maze.h"
using namespace std;

/* Change this constant to contain your full first and last name (middle is ok too).
 *
 * WARNING: Once you've set set this constant and started exploring your maze,
 * do NOT edit the value of kYourName. Changing kYourName will change which
 * maze you get back, which might invalidate all your hard work!
 */
const string kYourName = "Adithya Jose";

/* Change these constants to contain the paths out of your mazes. */
const string kPathOutOfRegularMaze = "ESWEENEWSWWENSWEESSWW";
const string kPathOutOfTwistyMaze = "SWENNSWNSWWWEE";

bool isPathToFreedom(MazeCell* start, const string& moves) {  
    MazeCell* curMove = start;
    bool spellBook = false; bool potion = false; bool wand = false; // set items to false as default
  // to check if item is on the start move
    if (curMove != nullptr) { // if current move lands on item string value
      if (curMove->whatsHere == "Spellbook") {
        spellBook = true;
      } else if (curMove->whatsHere == "Potion") {
        potion = true;
      } else if (curMove->whatsHere == "Wand") {
        wand = true;
      }
    } else if (curMove == nullptr) {
      return false;
    }
  
    for (int i = 0; i < moves.length(); ++i) { // based char given in moves initiates which direction to head
      if (curMove != nullptr) {
        if (moves[i] == 'N') {
          curMove = curMove->north;
        } else if (moves[i] == 'S') {
          curMove = curMove->south;
        } else if (moves[i] == 'E') {
          curMove = curMove->east;
        } else if (moves[i] == 'W') {
          curMove = curMove->west;
        } else {
          return false;
        }
        
        if (curMove != nullptr) { // if current move lands on item string value
          if (curMove->whatsHere == "Spellbook") {
            spellBook = true;
          } else if (curMove->whatsHere == "Potion") {
            potion = true;
          } else if (curMove->whatsHere == "Wand") {
            wand = true;
          }
        } else if (curMove == nullptr) {
          return false;
        }
      } else {
        return false;
      }
    }
  
    if ((spellBook == true) && (potion == true) && (wand == true)) { // all items found hence path is valid
      return true;
    } else {
      return false;
    }
}
