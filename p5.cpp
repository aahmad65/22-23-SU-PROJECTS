// Aidan Ahmad
// p5.cpp

#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<ctime>

using namespace std;

const string FILENAME = "/home/fac/sreeder/class/cs1420/p5input.dat";
const int BOARD_SIZE = 45;
const int SINGLE_SPIN = 6;
const int PLAYER_COUNT = 7;
const int MAX_SPIN = 11;
const char YES = 'y';
const string CHAPEL = "Chapel of St. Ignatius";
const string CHANCE = "Chance";

struct boardGame
{
  string name;
  int owner;
  int purchase;
  int cost;
};
struct players
{
  string name;
  int position = 0;
  int money = 1500;
  bool goFirst = 1;
};

void property(boardGame board[], players list[], int space, int turn);
int spinner();
void welcome();
void goodbye();
void takeTurn(boardGame property[], players list[], int turn, int size,
              int chapel);
int chance(boardGame property[], players list[], int turn, int chapel);
int linSearch(players list[], int count);

int main()
{
  srand(time(0));
  cout << endl << endl;
  
  players list[PLAYER_COUNT];
  boardGame board[BOARD_SIZE];
  ifstream infile;
  int count = 0;
  int pc = 0; // player amount
  int amount = 1;
  bool win = 0;
  char again = YES;
  int turn = 1;
  int chapel;
  int winner;
  
  infile.open(FILENAME);
  if(infile.fail()){
    cout << "File failed to open... closing program...";
    return 0;
  }

  welcome();

  while(again == YES){
    while(count < BOARD_SIZE && getline(infile, board[count].name)){
      infile >> board[count].owner >> board[count].purchase
             >> board[count].cost;
      infile.ignore();
      count++;
    }

    for(int i = 0; i < count; i++){
      if(board[i].name == CHAPEL)
        chapel = i;
    }
  
    while(pc > PLAYER_COUNT || pc < 2){
      cout << "Please enter amount of players(2-6): ";
      cin >> pc;
    }
    cout << endl;

    while(amount < pc + 1){
      cout << "Enter player #" << amount << "'s name: ";
      cin >> list[amount].name;
      amount++;
    }
    
    while(win == 0){
      for(int i = 1; i < pc + 1; i++){
        for(int j = 1; j < pc + 1; j++){
          if(list[j].money <= 0){
            cout << list[j].name << " ran out of money!" << endl;
            win = 1;
            winner = linSearch(list, pc);
          }
          if(list[j].money >= 10000){
            cout << list[j].name << " reached $10000 or more!" << endl;
            winner = j;
          }

        }
        if(win == 0){
          turn = i;
          takeTurn(board, list, turn, count, chapel);
          list[i].goFirst = false;
        }
      }
      turn = 1;
    }
    cout << endl << endl;
    
    cout << "The winner is " << list[winner].name << endl;
    cout << "They had $" << list[winner].money << "." << endl;

    cout << endl << endl;
    cout << "Would you like to play again? (y/n): ";
    cin >> again;
    win = 0;
    pc = 1;
    amount = 1;
    for(int c = 1; c < PLAYER_COUNT; c++){
      list[c].money = 1500;
    }
  }
  
  goodbye();
  cout << endl << endl;
  infile.close();
  return 0;
}
int spinner()
{
  int spin;
  spin = rand() % MAX_SPIN;
  return spin + 2;
}
void property(boardGame property[], players list[], int space, int turn)
{
  char buy;
  if(property[space].owner == 0){
    cout << list[turn].name << ", you have $" << list[turn].money << ".";
    cout << endl;
    cout << "This property costs $" << property[space].purchase << "." << endl;
    cout << "Would you like to purchase this property? (y/n): ";
    cin >> buy;
    
    if(buy == 'y'){
      if(list[turn].money > property[space].purchase){
        list[turn].money = list[turn].money - property[space].purchase;
        cout << endl << "You bought the space " << property[space].name << ".";
        property[space].owner = turn;
      }else
        cout << "You don't have enough money for this property.";
    }
  }else if(property[space].owner > 0){
    cout << "You've landed on " << list[property[space].owner].name << "'s"
         << " space." << endl;
    cout << "You pay them $" << property[space].cost << ".";
    list[property[space].owner].money += property[space].cost;
    list[turn].money -= property[space].cost;
  }else
    if(property[list[turn].position].name != CHANCE){
      cout << endl << "This property is not for purchase." << endl;
    }
  if(property[space].name == "Income Tax" || property[space].name == "Fees"){
    cout << "You pay the bank $200." << endl;
    list[turn].money = list[turn].money - 200;
  }
}
void welcome()
{
  cout << "Welcome to Seattle University Monopoly! In this program" << endl
       << "you will play monopoly among 2-6 players. Everyone starts" << endl
       << "with $1500. The game ends when a player runs out of money." << endl
       << "The player with the most money when the game ends wins!" << endl
       << "Good luck!" << endl << endl;
}
void goodbye()
{
  cout << "Thanks for playing. Have a good day!";
}
void takeTurn(boardGame board[], players list[], int turn, int size,
              int chapel)
{
  int spin;
  int pos;
  int extra;
  bool money = 0;
  
  cout << endl;
  cout << "It is " << list[turn].name << "'s turn." << endl << endl;
  cout << "Press enter to spin...";
  cin.get();
  cin.ignore();
  
  spin = spinner();
  cout << endl;
  cout << "You rolled a " << spin << "." << endl;
  list[turn].position += spin;

  if(board[list[turn].position].name == CHANCE){
    money = chance(board, list, turn, chapel);
  }
  
  if(list[turn].position >= size && money != 1){
    extra = list[turn].position - size;
    list[turn].position = 0;
    list[turn].position += extra;
    if(list[turn].goFirst == false){
      list[turn].money += 200;
      cout << "You got $200 for passing GO!" << endl;
    }
  }else if(money == 1){
    extra = list[turn].position;
    list[turn].position = 0;
    list[turn].position += extra;
  }
  
  pos = list[turn].position;

  if(board[list[turn].position].name != CHANCE){
    cout << endl << "You landed on " << board[pos].name << "." << endl;
  }
  
  cout << endl;
  property(board, list, pos, turn);
  cout << endl;
  cout << list[turn].name << ", you have $" << list[turn].money << ".";
  cout << endl;
}
int chance(boardGame property[], players list[], int turn, int chapel)
{
  int rest = 0;
  int spin;
  cout << endl << "You landed on a chance square!";
  cout << endl << "Press enter to spin...";
  cin.get();
  cin.ignore();
  
  spin = rand() % SINGLE_SPIN + 1;

  cout << "You rolled a " << spin << ".";
  if(spin > 0 && spin < 4){
    cout << endl << "You get $50." << endl;
    list[turn].money += 50;
  }else{
    cout << "You move to the " << CHAPEL << " for rest." << endl;
    rest = 1;
    list[turn].position = chapel;
  }
  return rest;
}
int linSearch(players list[], int count)
{
  int greatest = 1;

  for(int i = 1; i < count + 1; i++){
    if(list[i].money > list[greatest].money)
      greatest = i;
  }
  return greatest;
}
