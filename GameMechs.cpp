#include "GameMechs.h"
#include "MacUILib.h"




GameMechs::GameMechs()//gameboard constructor
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = 30;
    boardSizeY = 15;
    foodPos.setObjPos(-1,-1,'o');//sets food away from board so its not visible before start

}

GameMechs::GameMechs(int boardX, int boardY)
{
    input = 0;
    exitFlag = false;
    loseFlag = false;
    score = 0;
    boardSizeX = boardX;
    boardSizeY = boardY;
    foodPos.setObjPos(-1,-1,'o');
}

// do you need a destructor?
GameMechs::~GameMechs()
{

}


bool GameMechs::getExitFlagStatus()
{
    return exitFlag;//gets flag status

}

bool GameMechs::getLoseFlagStatus()
{
    return loseFlag;//gets flag status
}

char GameMechs::getInput()
{ 
    if (MacUILib_hasChar())
    {
        input= MacUILib_getChar();
    }
    return input;//gets user input and stores it in input
    
}

int GameMechs::getBoardSizeX()
{
    return boardSizeX;//gets fboardsize
}

int GameMechs::getBoardSizeY()
{
    return boardSizeY;//gets boardsize
}

int GameMechs::getScore()
{
    return score;//gets scvore
}

void GameMechs::setExitTrue()
{
    exitFlag = true;//sets flag status
}

void GameMechs::setLoseFlag()
{
    loseFlag = true;//sets flag status
}
void GameMechs::generateFood(objPos blockOff)//implement blockoff
{   int xindex=0;
    int yindex=0;
    bool val=0;
   objPosArrayList* playerPosList=new objPosArrayList();
    while(val=0)
    {
        
        foodPos.x = rand() % (getBoardSizeX()-2) + 1;//generates random coord for food to be placed
        foodPos.y = rand() % (getBoardSizeY()-2) + 1;
        if(foodPos.x==(boardSizeX-1) || foodPos.y==(boardSizeY))
        {
            continue;

        }
        for(int check=1; check < playerPosList->getSize(); check++)
        {
            objPos temppos;
            playerPosList->getElement(temppos,check);
            if(foodPos.y==temppos.y && foodPos.x==temppos.y)//checks for overalp
            {
                val=0;
            }
           
        }
        break;
    }// might have to implement for every element

        
    

}
void GameMechs::getFoodPos(objPos &returnPos)
{

    returnPos.setObjPos(foodPos.x,foodPos.y,foodPos.symbol); //gets and generates food object
    

}

void GameMechs::setInput(char this_input)
{
    input = this_input;//set input

}

void GameMechs::clearInput()
{
    input = 0;//claear inpout
}

void GameMechs::incrementScore()
{
    score++;//increases score
}
