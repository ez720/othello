# Development Log

## Week 1

### 11/15 - 11/16
* Learned how to use ofxDatGui (external library)
  * Made a rough menu panel with options for choosing strategies and resetting the game
* Learned how to draw circles from user mouse input
  * Need to map user input coords to a tile center

### 11/18 - 11/19
* Worked on board functionality
  * Created methods to return a list of valid moves and flip tiles
  * Created multiple helper methods (getting indexes of "flanking" tiles, checking valid moves, etc.)

## Week 2 (Thanksgiving)
 * Researched minimax and openframeworks

## Week 3

### 12/2 - 12/3
* Added boundaries for board
  * Fixed bug where flipping tiles would "wrap around" the edges of the board
* Created minimax strategy
  * Strategy can determine best move according to player
  * Attempted a C++ abstract class
 
## Week 4

### 12/5
* Integration with openframeworks
  * Added gameplay for GUI
  * Added human vs minimax gameplay

### 12/8
* Fixed minimax bug
  * Minimax method was choosing black as maximizing player, fixed it so method would choose the "original" player as the maximizing player
  
### 12/10-11
* Improved extendability
  * Can play on any size board
* Added option for player to be human or minimax
