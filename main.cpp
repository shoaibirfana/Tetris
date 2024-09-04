//          Name:Shoaib Irfan       Roll No:22i-1222                 Section:B
#include<iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <iostream>
#include "utils.h"
#include "pieces.h"
#include "functionality.h"

using namespace sf;
using namespace std;
int main()
{
    srand(time(0));
    RenderWindow window(VideoMode(440, 550), title);
    Texture obj1, obj2, obj3,obj4,obj5,obj6,obj7,obj8;
    
    obj1.loadFromFile("img/tiles.png");
    obj2.loadFromFile("img/background.png");    
    obj3 .loadFromFile("img/frame.png");
    obj4 .loadFromFile("img/tiles.png");
    obj5 .loadFromFile("img/bomb (2) (1).png");
    obj6 .loadFromFile("img/starting.png");
    obj7 .loadFromFile("img/pause.png");
    obj8 .loadFromFile("img/gameover.png");
    Sprite sprite(obj1), background(obj2), frame(obj3), shadow(obj4),bomb(obj5),startmenu(obj6),pause(obj7),gameover(obj8);
    Text text,leveldis;
    ////////////////////////////////Declaration & intialize(of some variable) of given variable//////////////////////
    
    int delta_x=0, colorNum=1;
    float timer=0, delay=0.3;
    int rotate=0;
    Clock clock;
    ////////////////////////////////Declaration & intialize(of some variable) of given self made variable///////////

         //////////////////checks variable/////////////////    

    int bombcheck=20;
    int bombcheck2=0,bombcheck3=1;
    int checkrotate=0; 
    int checkleft=0; 
    int checkright=0;
    int checkharddrop=0; 
    int checkgamepause=0,checkgamepause1=1,displaygamepause=0;
    int windowstartcheck=0;
    int checkgameover=0;
        //////////////////simple variable////////////////
   
    int score=0;
    double timelevel=0;
    float timer1=0,delay1=0.3; 
    int shadowarray[4][2];
    int xaxis=25,yaxis=0;
    int ncount=0;
    int level=1;
    int a1[4][0];
    int x=0;
    int bombcolor=2;
     
     ////////////////////font declare///////////////////
     Font font,shoaib;
     font.loadFromFile("font/Soul_Calibur.ttf");
     shoaib.loadFromFile("font/malgun_boot.ttf");
     /////for fist piece not to be not single block////
   
    int p=rand()%+1;
    
                for (int i=0;i<4;i++)
            {
                point_1[i][0] = BLOCKS[p][i] % 2;
                point_1[i][1] = BLOCKS[p][i] / 2;
            }
 

 
 
////////////////////////////////////////widow contineous display start from here//////////////////////////
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer+=time;
        timer1+=time;
        timelevel+=time;
    /////////////////////////////////////////part which cantain Keys retated work///////////////////////////////////
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
        Event e;
        while (window.pollEvent(e))
        {                     
            if (e.type == Event::Closed)                    
                window.close();                            
            if (e.type == Event::KeyPressed)
            {              
                if (e.key.code == Keyboard::Up)                           // this key is for rotation 
                {                                          
                    checkrotate=1;                       
                } 

                else if (e.key.code == Keyboard::Left)                           // this key is for left move ment 
                {      
                    checkleft=1;
                    delta_x=-1;
	            }                                             
                else if (e.key.code == Keyboard::Right)                           //this key is for right movement 
                {    
                    checkright=1;  
                    delta_x=1;    
	            } 
	            else if (e.key.code == Keyboard::Space)                            //this key is for hard drop 
	            {
                   checkharddrop=1;     
                }
	            else if (e.key.code == Keyboard::H)                            //this key is for pause 
	            { 
                   if(checkgamepause1==2)
                   {
                    checkgamepause=0; 
                    displaygamepause=0;                   
                   }                
                   if(checkgamepause1==1)
                   {
                    checkgamepause=1;
                    checkgamepause1=2;
                    displaygamepause=1;
                   }
 
 
                }
                else if (e.key.code == Keyboard::S)                            // this key is to start game in stat of game 
	            {                  
                    windowstartcheck=1;
                } 
                else if (e.key.code == Keyboard::X)                            // this key is for close the window of game  
	            {
                   window.close();                 	                                   
                }
                else if (e.key.code == Keyboard::R)                            //f this key is for restart 
	            {
                    timelevel=0;
                    level=1;
                    score=0;
                    for(int i=19;i>=0;i--)
                        for(int j=0;j<=9;j++)
                    gameGrid[i][j]=0;
                    displaygamepause=0;
                    checkgamepause=0;
                    checkgameover=0;
    int k=rand()%+1;
    
                for (int i=0;i<4;i++)
            {
                point_1[i][0] = BLOCKS[k][i] % 2;
                point_1[i][1] = BLOCKS[k][i] / 2;
            }                   
 


                }   
            }
        }    
        if (Keyboard::isKeyPressed(Keyboard::Down))                      //this key is for fast downward movement 
            delay=0.05;  
 
            
     //////////////////////////////////////////////////////////////////////////////////////////////
     //////////////////////////////////*** START CALLING YOUR FUNCTIONS HERE ***///////////////////
        if(checkgamepause==0 && windowstartcheck==1) 
        { 
                  if(checkgamepause1==2)
                   {
                    checkgamepause1=1;
                   }

            fallingPiece(timer, delay, colorNum); //faling piece function 

            removeline(ncount);                       //remove line function i use this to remove line on spwcific condion
                                                      // that is when all row is completed it is removed by working of this function
                                                      //ncount is to calculate number of lines destroyed at a time and we use it in another
                                                      //function to count score that is why we use it by bypass
            
            shadowfunction(shadowarray);                 //shadow falling function is for making shaodw according to coming
                                                         // block and shadowarray is its array which store coming block position
                                                         // and we use it to make shadow and we pass it by bypass mathod beacuse 
                                                         //we need it chage values to display it 

            if(checkrotate==1)
            Block_rotate(rotate);                   //rotate function is for block roatation according and we need rotate value 
                                                   //to start rotation except at some checks
            checkrotate=0;

            if(checkleft==1)
            left(delta_x);                          //left move function to move piece to left and delta_x is for how many unit we 
                                                    //have to use 
            checkleft=0;

            if(checkright==1)
            right(delta_x);                        //right move function to move piece to right and delta_x is for how many unit we 
                                                   //have to use 
            checkright=0;

            if(checkharddrop==1)
            harddrop();                           //haed drop function work according to + value in block till it reack to boundry or at back of a block
            checkharddrop=0;

            scorevalidation(ncount,score);           //this is score count funtion according to line remove so we give it name validation as we have  to
                                                     //increase according to remove line we use score as bypass beacase we need score vale to diplay in main after 
                                                     //changes and ncount value direct because we need it only in function and after it we need not to do change in it   

            bombfun(bombcheck,bombcheck2,bombcheck3,xaxis,yaxis,timer1,delay1,bombcolor);  //bomb function use three bomb check which are basically at diffrent step for its work
                                                                                           //x and y axis are the cordinates of the block bombcolor is used to check in which ways
                                                                                           // line have to be destroyed delay and timer are for its working 
            
            gameoverfun(checkgamepause,checkgameover);  //this is to stop game and display menue and score 
            tmerfunction(timelevel,delay,level);         //this is for increse level conditions 

        }

        ///////////////////////////////////////////////*** YOUR CALLING STATEMENTS END HERE ***///////////////////////////
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
            
            
 


        ////////////////////////////////////////////given display////////////////////////////////////////////            
             
       window.clear(Color::Black);
        window.draw(background);

        for (int i=0; i<M; i++)
        {
            for (int j=0; j<N; j++)
            {
                if (gameGrid[i][j]==0)
                    continue;
                sprite.setTextureRect(IntRect(gameGrid[i][j]*18,0,18,18));
                sprite.setPosition(j*18,i*18);
                sprite.move(28,31); //offset
                window.draw(sprite);
            }
        }
        for (int i=0; i<4; i++)
        {
            sprite.setTextureRect(IntRect(colorNum*18,0,18,18));
            sprite.setPosition(point_1[i][0]*18,point_1[i][1]*18);
            sprite.move(28,31);
            window.draw(sprite);
        }
 
        
        
       /////////////////////////////////////shadow display/////////////////////////////////////////////////////
        
        for (int i=0; i<4; i++)
        {
            shadow.setTextureRect(IntRect(colorNum*18,0,18,18));
            shadow.setPosition(shadowarray[i][0]*18,shadowarray[i][1]*18);
            shadow.move(28,31);
            shadow.setColor((Color(255,255,255,50)));
            window.draw(shadow);
             
        }             
                          
        /////////////////////////////////////////-bomb display///////////////////////////////////////////////            
             
            if(bombcolor==1)
            { 
            bomb.setColor(Color::Red);
            bomb.setPosition(xaxis*18,yaxis*18);
            bomb.move(28,31);
            window.draw(bomb);
            }
            if(bombcolor==2)
            {
            bomb.setColor(Color::Green);
            bomb.setPosition(xaxis*18,yaxis*18);
            bomb.move(28,31);
            window.draw(bomb);
            }
            if(bombcolor==3)
            {
            bomb.setColor(Color::Magenta);
            bomb.setPosition(xaxis*18,yaxis*18);
            bomb.move(28,31);
            window.draw(bomb);
            }
            if(bombcolor==4)
            {
            bomb.setColor(Color(255,120,0));
            bomb.setPosition(xaxis*18,yaxis*18);
            bomb.move(28,31);
            window.draw(bomb);
            }
            if(bombcolor==5)
            {
            bomb.setColor(Color::Cyan);
            bomb.setPosition(xaxis*18,yaxis*18);
            bomb.move(28,31);
            window.draw(bomb);
            }
            if(bombcolor==6)
            {            
            bomb.setColor(Color::Blue);
            bomb.setPosition(xaxis*18,yaxis*18);
            bomb.move(28,31);
            window.draw(bomb);
            }
            if(bombcolor==7)
            {            

            bomb.setColor(Color::Yellow);
            bomb.setPosition(xaxis*18,yaxis*18);
            bomb.move(28,31);
            window.draw(bomb);
            }
        /////////////////////////////////////////////////for score display///////////////////////////////////////////
        
 
            text.setFont(font);
            text.setString("Score");            
            text.setPosition(320,260);            
            text.setCharacterSize(70);  
            text.setFillColor(Color::Black);
            text.setStyle(Text::Bold | Text::Underlined);

        //////////////////////////////////////score dsplay////////////////////////////////////////////////////

        Text dis_score(std::to_string (score), font);
        dis_score.setPosition(320,300);
        dis_score.setCharacterSize(160);
        dis_score.setFillColor(Color::Black); 


        //////////////////////////////////////////////display written level///////////////////////////////////////////
            
            leveldis.setFont(font);
            leveldis.setString("Level");            
            leveldis.setPosition(320,20);            
            leveldis.setCharacterSize(90);  
            leveldis.setFillColor(Color::Black);
            leveldis.setStyle(Text::Bold | Text::Underlined);
        ///////////////////////////////////////////////display level/////////////////////////////////////////////////       
            
      
        Text leveltex(std::to_string (level), font);
        leveltex.setPosition(330,75);
        leveltex.setCharacterSize(150);
        leveltex.setFillColor(Color::Black); 
 





            
        ///////////////////////////////////////////draw of frame,text,score////////////////////////////////////////            
 
                    window.draw(frame);
                    window.draw(text);
                    window.draw(leveldis);                    
                    window.draw(dis_score);
                    window.draw(leveltex);                    
                    if(windowstartcheck==0)
                        window.draw(startmenu);
                    if(displaygamepause==1)
                        window.draw(pause);
                    if(checkgameover==1)
                    {
                        window.draw(gameover);
                        Text dis_score(std::to_string (score), shoaib);
                        dis_score.setPosition(200,327);
                        dis_score.setCharacterSize(40);
                        dis_score.setFillColor(Color::White); 
                        window.draw(dis_score);
                    }
        window.display();
   }
    return 0;
}
