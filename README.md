# Tic-Tac-Toe

## Usage 
make main.exe 
./main.exe

## AI
There are three types of AI:
1. Plays randomly
2. Plays randomly unless it sees an opprotuntiy to win in which case it takes it
3. Uses a minimax algorithm to find the optimal move at every turn.

## Notes
Currently, I feel that my implementation of the minimax algo is somewhat sloppy. While it works properly and quickly the issue is that the AI is currently spread across two different functions. One function makes the play that it is testing and if it is a win and the other function handles all the rest. I think there should be a way to simplify this. However, given that it is functional and fast in its current state, I will progess on to differet projects before coming back to this one.

## Futre plans
1. Implement a leaderboard that maintains state using a csv file.

## Atributinos
The unit testing framework used in this project is taken from the Univeristy of Michigan EECS 280 class, developed by the professors and reflects none of my own work.