# Othello

## Background

Read the history and rules of Othello [here](https://en.wikipedia.org/wiki/Reversi). This project allows users to play against
a Minimax AI or watch two Minimax AIs play against each other. The player can choose to play on any even board size (8x8 is
the default board size).

**Library used** : [ofxDatGui](https://braitsch.github.io/ofxDatGui/) for the menu side panel

## Setting up

You must have Xcode on MacOS to build this project.

* [Install openframeworks][1]
* [Install ofxDatGui][2]

[1]:https://medium.com/@benwiz/how-to-install-openframeworks-on-a-mac-macos-high-sierra-a5a9b3f47ea1
[2]:https://braitsch.github.io/ofxDatGui/

## Playing

* If a human is playing, the red circles on the board represent valid moves
* Menu bar
  * Player : human vs minimax or minimax vs minimax
  * Reset
  * Change board size
