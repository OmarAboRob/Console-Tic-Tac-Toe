#include <bits/stdc++.h>
using namespace std;
vector <char> values={'1','2','3','4','5','6','7','8','9'};
void board() {
    cout<<" "<<values[0]<<" | "<<values[1]<<" | "<<values[2]<<endl;
    cout<<"---+---+---"<<endl;
    cout<<" "<<values[3]<<" | "<<values[4]<<" | "<<values[5]<<endl;
    cout<<"---+---+---"<<endl;
    cout<<" "<<values[6]<<" | "<<values[7]<<" | "<<values[8]<<endl;

}
bool isWinner(vector<char> a) {
    //to check the winner
    if (a[0] == a[1] && a[1] == a[2]) return true;
    if (a[3] == a[4] && a[4] == a[5]) return true;
    if (a[6] == a[7] && a[7] == a[8]) return true;
    if (a[0] == a[4] && a[4] == a[8]) return true;
    if (a[2] == a[4] && a[4] == a[6]) return true;
    if (a[0] == a[3] && a[3] == a[6]) return true;
    if (a[1] == a[4] && a[4] == a[7]) return true;
    if (a[2] == a[5] && a[5] == a[8]) return true;
    return false;
}
void regenerate() {
    // to regenerate the gameboard
    values = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
}
void game() {
  //to start the game
  int i; // the counter for moves
  for (i = 0; i < 9; i++) {
    // only from 0 to 9 because its the max number of turns
    if (i%2==0) {
      //to choose player one to play i used isEven function to make the turn switched
          cout<<"Player 1,please enter the number of the square you want to place your x:"<<endl;
      int choise ;
        cin>>choise;// to read the input
      if (choise>9||choise<=0) {
        cout<<"Invalid input please enter a number"<<endl;
        cin>>choise;
      }
      if ((choise > 9) ||
          (values[choise - 1] == 'O') ||
          (values[choise - 1] == 'X')) //to check the input if its valid or not
      {
        cout<<"Invalid input please enter new choise"<<endl;
        i--;
        continue;
      }
      values[choise - 1] = 'X'; //to change the value of gameboard
      if (isWinner(values)) {
        // to check if x is the winner
        cout<<"winner winner chicken dinner the winner is: X"<<endl;
        board();
        break;
      }
    } else {
      //to choose  player two to play
      cout<<"Player 2,please enter the number of the square you want to place your O:"<<endl;
      int choise ;
      cin>>choise;// to read the input
      if (choise>9||choise<=0) {
        cout<<"Invalid input please enter a number"<<endl;
        cin>>choise;
      }
      if ((choise > 9) ||
          (values[choise - 1] == 'O') ||
          (values[choise - 1] == 'X')) //to check the input
      {
       cout<<"Invalid input please enter new choise"<<endl;
        i--; //to make the player able to repeat his move
        continue;
      }
      values[choise - 1] = 'O'; //to change the value of gameboard
      if (isWinner(values)) {
        // to check if o is the winner
       cout<<"winner winner chicken dinner the winner is: O"<<endl;
        board();
        break;
      }
    }
    board(); //to display the change of gameboard
  }
  if (i == 9) // to check if its a draw
    cout<<"Draw match!....."<<endl;
    cout<<"Enter 1 to play again \nEnter 2 to end game"<<endl; //to choose end game or play again

  for (;;) {
    // this loop to apply it to play forever
    int choise1 ;
    cin>>choise1;// to read the input
    if (choise1!=1&&choise1!=2) {
      cout<<"Invalid input please enter new choise"<<endl;
      continue;
    }
    if (choise1 == 1) {
      //to play again start the game from zero
      regenerate();
      board();
      game();
    } else {
      // to end the game
     cout<<"Thanks For Playing";
      return;
    }
  }
}
int main() {
    board();
    game();
    return 0;
}
