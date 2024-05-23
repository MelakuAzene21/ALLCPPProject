#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void startGame();
void newGame();
int getRandNum();
int getMyGuess();
bool isCorrectGuess(int,int);
int totalplayed=0;
int win=0;
int loss=0;
//===========================================================================================================
int main()
{
    startGame();
    return 0;
}
//===============================================================================================================
void startGame()
{
    char ch;
    while(true)

        {
            totalplayed++;
            cout<<"\n      Game-"<<totalplayed<<endl;
          cout<<"-------------------------------------------------------------------------------------------------\n";
            newGame();
          cout<<"-------------------------------------------------------------------------------------------------\n";

    cout<<"do you want to play again [yes/no]\n";
    cin>>ch;
    if(ch=='y'||ch=='Y')
    continue;
    else if
    (ch=='n'||ch=='N')
    {
    cout<<"the total score you get in this Game is recording as follwing\n";
      cout<<"-------------------------------------------------------------------------------------------------\n";

       cout<<"total game played="<<totalplayed<<endl;
       cout<<"toal win="<<win<<endl;
       cout<<"total loss="<<loss<<endl;

        break;
    }
}
}
//================================================================================================================
void newGame()
{
    int randNum,myGuess;
    randNum=getRandNum();
    bool success=false;
    for(int i=0;i<3;i++)
    {
        myGuess=getMyGuess();
          if(isCorrectGuess(randNum,myGuess))
          {
           success=true;
           break;
          }
          else{
            if(i!=2)
            cout<<"incorrect guess.please try again\n";
          }
    }
    if(success)
    {
        win++;

    }
    else
    {
        loss++;
    }

    if(isCorrectGuess(randNum,myGuess))

    cout<<"CONGRATULATION\n";
    else
        cout<<"You have Lost the game\n"<<"the number is:"<<randNum<<endl;

}
//===============================================================================================================
int getRandNum()
{
srand(time(NULL));
return rand()%10;
}
//=================================================================================================================
  int getMyGuess()
{
    int myGuess;
    cout<<"guess a number[0-9]\n";
    cin>>myGuess;
    return myGuess;
}
bool isCorrectGuess(int randNum,int myGuess)
{
    if(randNum==myGuess)
        return true;
    return false;

}
