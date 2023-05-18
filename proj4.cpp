/**

*File Name: proj4.cpp

*Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines (Links to an external site.) at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines (Links to an external site.)

*Assisted by and Assisted line numbers:


*Your Name: Cory Drangel

*Your PSU user ID:  cjd209

*Course title: CMPSC465 Summer 2022 

*Due Time: 11:59 pm, Sunday, July 3, 2022

*Time of Last Modification: 10:20 pm, Saturday, July 2, 2022

*Description: Determines the number of moves on a chessboard that it takes a knight to move from one given spot to another

*/

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

const int N = 8;  //constant global variable for each side of the chessboard

int knightMoves(int start[], int end[]);

int main() {
  int start[2], end[2];
  ifstream inFile;
  string str;

  //opens the input file
  inFile.open("input.txt");

  //if statement to ensure the file opened correctly
  if(inFile){
    //while statement for as long as the file contains text
    while(inFile >> str){
      int x, y;  //variables to store the location of the start and end points

      cout << "To get from " << str;

      //getting the letter of the start point
      string s1 = str.substr(0,1);

      //switch statement to convert the letter of the start point to a number
      switch(s1.at(0)){
        case 'a' :
          x = 1;
          break;
        case 'b' :
          x = 2;
          break;
        case 'c' :
          x = 3;
          break;
        case 'd' :
          x = 4;
          break;
        case 'e' :
          x = 5;
          break;
        case 'f' :
          x = 6;
          break;
        case 'g' :
          x = 7;
          break;
        case 'h' :
          x = 8;
          break;
      }
      //getting the number of the start point
      s1 = str.substr(1);
      y = stoi(s1);

      start[0] = x;
      start[1] = y;

      //getting the end point
      inFile >> str;

      cout << " to " << str;

      //getting the letter of the end point
      s1 = str.substr(0, 1);
      //switch statement to convert the letter of the end point to a number
      switch(s1.at(0)){
        case 'a' :
          x = 1;
          break;
        case 'b' :
          x = 2;
          break;
        case 'c' :
          x = 3;
          break;
        case 'd' :
          x = 4;
          break;
        case 'e' :
          x = 5;
          break;
        case 'f' :
          x = 6;
          break;
        case 'g' :
          x = 7;
          break;
        case 'h' :
          x = 8;
          break;
      }

      //getting the number of the endpoint
      s1 = str.substr(1);
      y = stoi(s1);
      end[0] = x;
      end[1] = y;      

      cout << " takes " << knightMoves(start, end) << " knight moves."<< endl;
    }
  }
  else{
    cout << "Input file did not work properly.";
  }
}

int knightMoves(int start[], int end[]) {
  int board[N][N];  //int array representing the board
  int x, y, x1, y1;

  //two for loops to assign 0 to all points on the board
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      board[i][j] = 0;
    }
  }

  x = start[0];
  y = start[1];

  //initializing the queue
  queue<int> q;

  //pushing the x and y values of the start point onto the queue
  q.push(start[0]);
  q.push(start[1]);

  //while statement for as long as the queue is not empty
  while (!q.empty()) {

    //assigning the values at the front of the queue to x and y
    //then popping them off the front of the queue
    x = q.front();
    q.pop();
    y = q.front();
    q.pop();

    //if statement to determine if the x and y values are the endpoint
    if (x == end[0] && y == end[1]) {
      //returning the value of the board if the end point has been reached
      return board[x -1][y -1];
    }

    //assigning 1 to the startint point on the board
    board[start[0] - 1][start[1] - 1] = 1;

    //for loop to do the neighbor checking of all the reachable values of the knight
    for (int i = 0; i < N; i++) {
      //switch statement for each of the reachable positions of the knight
      switch (i) {
        case 0:
          x1 = x + 1;
          y1 = y + 2;
          break;
        case 1:
          x1 = x + 2;
          y1 = y + 1;
          break;
        case 2:
          x1 = x + 2;
          y1 = y - 1;
          break;
        case 3:
          x1 = x + 1;
          y1 = y - 2;
          break;
        case 4:
          x1 = x - 1;
          y1 = y - 2;
          break;
        case 5:
          x1 = x - 2;
          y1 = y - 1;
          break;
        case 6:
          x1 = x - 2;
          y1 = y + 1;
          break;
        case 7:
          x1 = x - 1;
          y1 = y + 2;
          break;
      }

      //if the new position is within bounds and it hasn't been visited yet
      if (x1 >= 1 && x1 <= N && y1 >= 1 && y1 <= N && board[x1 -1][y1 -1] == 0) {

        //pusing the x and y values onto the queue
        q.push(x1);
        q.push(y1);

        //if the x and y are the start values
        if (x == start[0] && y == start[1]) {
          //assign 1 to the new position
          board[x1 - 1][y1 - 1] = 1;
        }
        else {
          //otherwise assign the new position to the value of it's parent + 1
          board[x1 - 1][y1 - 1] = board[x -1][y -1] + 1;
        }
      }
    }
  }
}
