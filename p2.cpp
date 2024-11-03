//Aidan Ahmad
//p2.cpp

//Purpose: To emulate the child's game "Hi-Ho! Cherry-O".

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
  const int MAX_SPIN = 7;
  int bucket1 = 0, bucket2 = 0;
  bool win = 0;
  bool p1Turn = true;
  bool p2Turn = false;
  int spin, winner;
  int p1Spin, p2Spin;

  srand(time(0));
  cout << endl << endl;

  cout << "Welcome to Hi-Ho! Cherry-O. In this game you will each have "
       << endl << "a bucket and a tree. There are ten cherries on the tree "
       << endl << "and you want to get all ten of those in your bucket. "
       << endl << "Be careful of the dog and the bird. Don't spill!";

  cout << endl << "Let's begin!";
  while(win == 0){
    cout << endl << endl;
    if(p1Turn == true){
      cout << "It is player one's turn!" << endl << endl;
    }else if(p2Turn == true){
      cout << "It is player two's turn!" << endl << endl;
    }
    cout << "Press enter to spin... ";
    cin.ignore();    
    cout << endl;
    spin = rand()% MAX_SPIN+1;
    while(p1Turn == true){
      p1Spin = spin;
      switch(p1Spin)
        {
        case 1:
          cout << "You rolled a one. One cherry is taken off your tree and\n"
               << "put in your bucket.";
          bucket1 += 1;
          break;
        case 2:
          cout << "You rolled a two. Two cherries are taken off your tree\n"
               << "and put in your bucket.";
          bucket1 += 2;
          break;
        case 3:
          cout << "You rolled a three. All the cherries in your bucket\n"
               << "spill.";
          bucket1 = 0;
          break;
        case 4:
          cout << "You rolled a four. Four cherries are taken off your tree\n"
               << "and put in your bucket.";
          bucket1 +=4;
          break;
        case 5:
          if(bucket1 >= 2){
            cout << "You rolled a five. A dog takes two cherries from your\n"
                 << "bucket and puts them back on your tree.";
            bucket1 -= 2;
          }else if(bucket1 >= 1){
            cout << "You rolled a five. A dog takes one cherry from your\n"
                 << "bucket and put it back on the tree.";
            bucket1 -= 1;
          }else if(bucket1 <= 0){
            cout << "You rolled a five. Nothing happens.";
          }
          break;
        case 6:
          cout << "You rolled a six. Three cherries are taken off your tree\n"
               << "and placed in your bucket.";
          bucket1 += 3;
          break;
        case 7:
          if(bucket1 >= 2){
            cout << "You rolled a seven. A bird takes two cherries from your\n"
                 << "bucket and puts them back on your tree.";
            bucket1 -= 2;
          }else if(bucket1 >= 1){
            cout << "You rolled a seven. A bird takes one cherry from your\n"
                 << "bucket and puts it back on the tree.";
            bucket1 -= 1;
          }else if(bucket1 <= 0){
            cout << "You rolled a seven. Nothing happens.";
          }
          break;
        }
      if(bucket1 == 1){
        cout << endl << endl << "Player one has 1 cherry.";
      }else if(bucket1 >= 10){
        cout << endl << endl << "Player one has filled their bucket!";
      }else
        cout << endl << endl << "Player one has " << bucket1 << " cherries.";
      p1Turn = false;
    }
    while(p2Turn == true){
      p2Spin = spin;
      switch(p2Spin)
        {
        case 1:
          cout << "You rolled a one. One cherry is taken off your tree and\n"
               << "put in your bucket.";
          bucket2 += 1;
          break;
        case 2:
          cout << "You rolled a two. Two cherries are taken off your tree\n"
               << "and put in your bucket.";
          bucket2 += 2;
          break;
        case 3:
          cout << "You rolled a three. All the cherries in your bucket\n"
               << "spill. ";
          bucket2 = 0;
          break;
        case 4:
          cout << "You rolled a four. Four cherries are taken off your tree\n"
               << "and put in your bucket.";
          bucket2 +=4;
          break;
        case 5:
          if(bucket2 >= 2){
            cout << "You rolled a five. A dog takes two cherries from your\n"
                 << "bucket and puts them back on your tree.";
            bucket2 -= 2;
          }else if(bucket2 >= 1){
            cout << "You rolled a five. A dog takes one cherry from your\n"
                 << "bucket and put it back on the tree.";
            bucket2 -= 1;
          }else if(bucket2 <= 0){
            cout << "You rolled a five. Nothing happens.";
          }
          break;
        case 6:
          cout << "You rolled a six. Three cherries are taken off your tree\n"
               << "and placed in your bucket.";
          bucket2 += 3;
          break;
        case 7:
          if(bucket2 >= 2){
            cout << "You rolled a seven. A bird takes two cherries from your\n"
                 << "bucket and puts them back on your tree.";
            bucket2 -= 2;
          }else if(bucket2 >= 1){
            cout << "You rolled a seven. A bird takes one cherry from your\n"
                 << "bucket and puts it back on the tree.";
            bucket2 -= 1;
          }else if(bucket2 <= 0){
            cout << "You rolled a seven. Nothing happens.";
          }
          break;
        }
      if(bucket2 == 1){
        cout << endl << endl << "Player two has 1 cherry.";
      }else if(bucket2 >= 10){
        cout << endl << endl << "Player two has filled their bucket!";
      }else
        cout << endl << endl << "Player two has " << bucket2 << " cherries.";
      p2Turn = false;
      p1Turn = true;
    }
    if(p1Turn == false){
      p2Turn = true;
    }
    if(bucket1 >= 10){
      winner = 1;
      win = 1;
    }else if(bucket2 >= 10){
      winner = 2;
      win = 1;
    }
  }
  cout << endl << endl;
  cout << "Player number " << winner << " wins!" << endl << endl;
  
  cout << "Thanks for playing. Have a good day!" << endl;

  cout << endl << endl;
  return 0;
}
