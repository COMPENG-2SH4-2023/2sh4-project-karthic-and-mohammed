#include "Player.h"



Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;//constructor
    myDir = STOP;
    moveCount=0;
    

    // more actions to be included
    
    tempPos.setObjPos((mainGameMechsRef->getBoardSizeX()/2),(mainGameMechsRef->getBoardSizeY()/2),'*');
    PlayerPosList = new objPosArrayList();
    PlayerPosList->insertHead(tempPos);
}


Player::~Player()
{
    // delete any heap members here
    delete PlayerPosList;
    delete mainGameMechsRef;
}

objPosArrayList* Player::getPlayerPos()
{
    // return the reference to the playerPos arrray list
     return PlayerPosList;
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic    
        char userInput = mainGameMechsRef->getInput();
          switch(userInput)
        {                      
            
            case 'W':
            case 'w': //accepts lowercase letters too
                if (myDir != DOWN)
                {
                    myDir = UP;
                }
                break;


            // Add more key processing here
            case 'S':
            case 's':
                if (myDir != UP)
                {
                    myDir = DOWN;
                }
                break;

            // Add more key processing here 
            case 'A':
            case 'a':
                if (myDir != RIGHT)
                {
                    myDir = LEFT;
                }
                break;


            // Add more key processing here 
            case 'D': 
            case 'd':
                if (myDir != LEFT)
                {
                    myDir = RIGHT;
                } 
                break;

            default:
                break;
        }
        mainGameMechsRef->clearInput();
}       

void Player::movePlayer()
{
    objPos newhead;
    objPos currenthead;
    PlayerPosList->getHeadElement(currenthead);// gets snakes head position
    
 switch (myDir)
    {
        case UP:
            currenthead.y--;
            break;
        case DOWN:
            currenthead.y++;
            break;
        case LEFT:
            currenthead.x--;
            break;
        case RIGHT:
            currenthead.x++;
            break;
        default:
            break;
    }
    // PPA3 Finite State Machine logic
     if (currenthead.x <= 0)
    {
        currenthead.x = mainGameMechsRef->getBoardSizeY() - 2;
    }
    else if (currenthead.x >=  mainGameMechsRef->getBoardSizeY() - 1)
    {
        currenthead.x = 1;
    }
    else if (currenthead.y <= 0)
    {
        currenthead.y =  mainGameMechsRef->getBoardSizeX() - 2;
    }
    else if (currenthead.y >=  mainGameMechsRef->getBoardSizeX() - 1)
    {
        currenthead.y = 1;
    }
     if (myDir != STOP)
    {
        moveCount++;//increases movement count
    }
    //inserting new head
    PlayerPosList->insertHead(currenthead);//creates head to implement movement display


    //removing tail
    PlayerPosList->removeTail();//destroys tail to implement movement display


}

