//Aidan Ahmad
//p3.cpp

//Purpose: To emulate the child's game Chutes and Ladders.

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void welcome();
void goodbye();
int spinner();
int check(int square); // Check for Chute or Ladder
int takeTurn(int pSpin, int pSquare, string name);

const int MAX_SPIN = 6;
const char YES = 'y';

int main()
{
  string p1, p2;
  int p1Space = 0, p2Space = 0;
  bool win = false;
  bool turn1 = true, turn2 = false;
  int spinnerReturn;
  char again = YES;
  
  srand(time(0));
  cout << endl << endl;
  welcome();

  cout << endl << "Please provide player one's name: ";
  cin >> p1;
  cout << endl << "Please provide player two's name: ";
  cin >> p2;
  cout << endl << "Shall we begin? ";
  cin.get();
  cout << endl;
  
  while(again == YES){
    while(win == false){
      while(turn1 == true && win == false){
        cout << endl;
        spinnerReturn = spinner();
        p1Space = takeTurn(spinnerReturn, p1Space, p1);
        if(p1Space == 100){
          win = true;
          cout << endl << endl << "The winner is " << p1 << ".";
        }
        turn1 = false;
        turn2 = true;
        }
      while(turn2 == true && win == false){
        cout << endl << endl;
        spinnerReturn = spinner();
        p2Space = takeTurn(spinnerReturn, p2Space, p2);
        cout << endl;
        turn1 = true;
        turn2 = false;
        if(p2Space == 100){
          win = true;
          cout << "The winner is " << p2 << ".";
        }
      }
    }
    cout << endl << endl;
    cout << "Would you like to play again? (y/n): ";
    cin >> again;
    p1Space = 0;
    p2Space = 0;
    win = false;
  }
  cout << endl << endl;

  goodbye();
  
  return 0;
}
void welcome()
{
  cout << "Welcome to Chutes and Ladders. This is a game where you " << endl
       << "will try to reach the top of the board using a spinner. " << endl
       << "There are different chutes and ladders that may move you " << endl
       << "higher or lower spaces. The goal is to reach space 100 " << endl
       << "exactly. Good luck!";

  cout << endl;
}
void goodbye()
{
  cout << "I hope you had fun. Goodbye now!" << endl;
}
int spinner()
{
  int spin;
  spin = rand()% MAX_SPIN+1;
  return spin;
}
int takeTurn(int pSpin, int pSquare, string name)
{
   cout << endl << "Press enter to spin " << name << "...";
   cin.get();
   cout << endl;
   cout << "You rolled a " << pSpin << " " << name << "." << endl;
   if(pSquare <= 94){
     pSquare += pSpin;
    }
    else if(pSquare == 95){
      if(pSpin <= 5){
        pSquare += pSpin;
      }else
        cout << "You rolled too high to move." << endl;
    }
    else if(pSquare == 96){
      if(pSpin <= 4){
        pSquare += pSpin;
        }else
        cout << "You rolled too high to move." << endl;
    }
    else if(pSquare == 97){
      if(pSpin <= 3){
        pSquare += pSpin;
      }else
        cout << "You rolled too high to move." << endl;
    }
    else if(pSquare == 98){
      if(pSpin <= 2){
        pSquare += pSpin;
      }else
        cout << "You rolled too high to move." << endl;
    }
    else if(pSquare == 99){
      if(pSpin == 1){
        pSquare += pSpin;
      }else
        cout << "You rolled too high to move." << endl;
    }
   cout << "You landed on " << pSquare << "." << endl;
   cout << "Press enter to check for a ladder/chute: ";
   cin.get();
   if(check(pSquare) > 0){
     cout << "Hooray! You landed on a square with a ladder!" << endl;
   }else if(check(pSquare) < 0){
     cout << "Oh no. You landed on a square with a chute!" << endl;
   }else
     cout << "Sorry, nothing on this square." << endl;
   pSquare += check(pSquare);
   cout << "You are on the square " << pSquare << ".";
   
   return pSquare;
}
int check(int square)
{
  if(square == 1){
    return 37;
  }
  else if(square == 4){
    return 10;
  }
  else if(square == 9){
    return 12;
  }
  else if(square == 23){
    return 21;
  }
  else if(square == 28){
    return 56;
  }
  else if(square == 36){
    return 8;
  }
  else if(square == 51){
    return 15;
  }
  else if(square == 71){
    return 19;
  }
  else if(square == 80){
    return 20;
  }
  else if(square == 98){
    return -20;
  }
  else if(square == 95){
    return -20;
  }
  else if(square == 93){
    return -20;
  }
  else if(square == 87){
    return -63;
  }
  else if(square == 64){
    return -4;
  }
  else if(square == 62){
    return -43;
  }
  else if(square == 56){
    return -3;
  }
  else if(square == 49){
    return -38;
  }
  else if(square == 48){
    return -22;
  }
  else if(square == 16){
    return -10;
  }
  else
    return 0;
}
