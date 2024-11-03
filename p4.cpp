//Aidan Ahmad
//p4.cpp

//Purpose: To emulate a memory game where you must choose matching cards.

#include<iostream>
#include<ctime>
#include<fstream>
#include<iomanip>

using namespace std;

const string FILE1 = "/home/fac/sreeder/class/cs1420/p4data1.dat";
const string FILE2 = "/home/fac/sreeder/class/cs1420/p4data2.dat";
const int ROWS = 2;
const int COLS = 6;
const int SPACE = 60;
const int WIDTH = 6;
const int WIDTH2 = 4;
const char YES = 'y';
const int AMATEUR = 8;
const int EXPERT = 4;

void wait(int seconds); // pauses the program for seconds
void screen(string memory [][COLS], string field[][COLS], int one, int two,
            int three, int four);
int main()
{
  ifstream infile;
  string cards[ROWS][COLS];
  string board[ROWS][COLS];
  char again = YES;
  int choice1;
  int choice2;
  int choice3;
  int choice4;
  bool win = 0;
  bool same = 1;
  int time;
  int difficulty = 0;
  int turns = 0;
  int match = 0;
  string FILENAME = FILE1;

  cout << endl << endl;

  cout << "Welcome to the memory game. In this game, you will be" << endl;
  cout << "presented with a field of cards. You will flip them over" << endl;
  cout << "and they will have letters on them. You will try to match" << endl;
  cout << "the cards together. Good luck!" << endl;

  cout << "Press enter to begin... ";
  cin.get();

  while(difficulty > 2 || difficulty < 1){
    cout << "Would you like to play amateur or expert?(1/2): ";
    cin >> difficulty;
  }
  if(difficulty == 1){
    time = AMATEUR;
    cout << "You've chosen Amateur! Press enter to continue... ";
    getchar();
    cin.ignore();
  }else{
    time = EXPERT;
    cout << "You've chosen Expert! Press enter to continue... ";
    getchar();
    cin.ignore();
  }
  cout << endl;

  while(again == YES){
    infile.open(FILENAME);
    if(infile.fail()){
      cout << "File has failed to open. Closing program..." << endl;
      return 0;
    }

    for(int r = 0; r < ROWS; r++){
    for(int c = 0; c < COLS; c++){
      infile >> cards[r][c];
      }
    }
    infile.close();

    win = 0;
    turns = 0;
    match = 0;
    for( int r = 0; r < ROWS; r++){
      for(int c = 0; c < COLS; c++){
        board[r][c] = "*";
      }
    }
    while(win == 0){
      choice1 = 11;
      choice2 = 9;
      choice3 = 10;
      choice4 = 8;
      
      screen(cards, board, choice1, choice2, choice3, choice4);
      while(choice1 > 1 || choice1 < 0){
        cout << "Row: ";
        cin >> choice1;
      }
      while(choice2 > 5 || choice2 < 0){
        cout << "Column: ";
        cin >> choice2;
      }
      if(board[choice1][choice2] == "_"){
        cout << "Cannot choose that card again... ";
        cin.get();
        cin.ignore();
        board[choice1][choice2] = "_";
      }else{
        same = true;
        screen(cards, board, choice1, choice2, choice3, choice4);
        while(same == true){
          while(choice3 > 1 || choice3 < 0){
            cout << "Row: ";
            cin >> choice3;
          }
          while(choice4 > 5 || choice4 < 0){
            cout << "Column: ";
            cin >> choice4;
          }
          if(board[choice3][choice4] == "_"){
            cout << "Cannot choose that card again... ";
            cin.get();
            cin.ignore();
            board[choice3][choice4] = "_";
            choice3 = 10;
            choice4 = 8;
          }else{
            if(choice3 == choice1 && choice4 == choice2){
              cout << "Cannot choose same card...";
            }else{
              same = false;
              screen(cards, board, choice1, choice2, choice3, choice4);
              if(board[choice1][choice2] == board[choice3][choice4]){
                cout << "Match!" << endl;
                cout << "Press enter to continue... ";
                cin.get();
                cin.ignore();
                board[choice1][choice2] = "_";
                board[choice3][choice4] = "_";
                match++;
              }else{
                cout << "Not a match... " << endl;
                board[choice1][choice2] = "*";
                board[choice3][choice4] = "*";
                wait(time);
              }
            }
          }
        }
      }
      turns++;
      if(match == 6)
        win = 1;
    }
    cout << "You took " << turns << " turns to win." << endl;
    cout << "Would you like to play again? (y/n): ";
    cin >> again;
    if(FILENAME == FILE1)
      FILENAME = FILE2;
    else
      FILENAME = FILE1;    
  }

  cout << endl << "Thanks for playing. Have a wonderful day!";

  cout << endl << endl;
  return 0;
}
void screen(string memory[][COLS], string field[][COLS], int one, int two,
            int three, int four)
{
  int c = 0;
  int r = 0;
  for(int index = 0; index < SPACE; index++)
    cout << endl;
  for(c = 0; c < COLS; c++){
    cout << setw(WIDTH) << c;
  }
  cout << endl;
  for(r = 0; r < ROWS; r++){
    for(c = -1; c < COLS; c++){
      if(c == -1)
        cout << r;
      else{
        if(r == one){
          if(c == two){
            field[r][c] = memory[r][c];
          }
        }
        if(r == three){
          if(c == four){
            field[r][c] = memory[r][c];
          }
        }
        cout << setw(WIDTH2) << "[" << field[r][c] << "]";
      }
    }
    cout << endl;
  }
}
void wait(int seconds)
{
  clock_t endwait;
  endwait = clock() + seconds * CLOCKS_PER_SEC;
  while (clock() < endwait){}
}
