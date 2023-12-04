#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "Player.h"
#include "GameMechs.h"
#include "objPosArrayList.h"
#include <cstdlib>

using namespace std;

#define DELAY_CONST 100000
char input;
bool exitFlag;
Player* myplayer;
GameMechs* mygm;




void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(mygm->getExitFlagStatus() == false)  //checking exit status
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}


void Initialize(void)
{
   
    MacUILib_init();
    MacUILib_clearScreen();
    srand(time(0));
    mygm=new GameMechs(30,26); //initializing using gamemech constructor
    myplayer=new Player(mygm); //passing constructed elements into player initializing constructor
    objPos temppos{-1,-1,'o'};
    mygm->generateFood(temppos); //generating food
}

void GetInput(void)
{
    mygm->getInput();// obatining input
        
    
    
   
}

void RunLogic(void)
{   
    
    //call update pl dir
    myplayer->updatePlayerDir();//updating direction based on input
    myplayer->movePlayer();//moving the snake base on direction

    mygm->clearInput(); // clearing input

    
  
}

void DrawScreen(void)
{
    MacUILib_clearScreen(); 
    bool draw; 

    objPosArrayList* playerbody=myplayer->getPlayerPos(); // gets player position
    objPos tempbody;
    objPos tempfoodpos;
    mygm->getFoodPos(tempfoodpos);//gets food position
    
 for (int i = 0; i < mygm->getBoardSizeY(); i++) //loops to verify coordinates
 {
    for (int j = 0; j < mygm->getBoardSizeX(); j++)
    {   
        draw = false;

            for(int k=0; k< playerbody->getSize(); k++)
            {
                playerbody->getElement(tempbody,k);
                if(tempbody.x==j && tempbody.y==i)
                {
                    MacUILib_printf("%c",tempbody.symbol);//printing snake
                    
                    draw=true;
                    
                    break; //breaks loop if snake is fully printed
                }
            }
           
            if(draw)
            {
                continue;

            }
           
            if (i == 0 || i == mygm->getBoardSizeY()-1 || j == 0 || j == mygm->getBoardSizeX()-1)
            {
                MacUILib_printf("%c",'#');// Print border character

            } 
            else if (i==(tempfoodpos.y && j==tempfoodpos.x))
            {
                MacUILib_printf("%c",tempfoodpos.symbol);
            }
            else
            {

                MacUILib_printf("%c",' '); // Empty space within the border
            }
            
        }
        MacUILib_printf("\n");
    }
    MacUILib_printf("SCORE: %d\n", mygm->getScore());
    MacUILib_printf("<%d,%d>",playerbody);

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();
    
    delete myplayer;//prevents memory leak
    delete mygm;
}
