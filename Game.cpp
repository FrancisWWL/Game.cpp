echo # Game.cpp >> README.md
git init
git add README.md
git commit -m "first commit"
git remote add origin https://github.com/FrancisWWL/Game.cpp.git
git push -u origin master

// This is the main file for the game logic and function
//
//
#include "game.h"
#include "Framework\console.h"
#include <iostream>
#include <iomanip>

double	g_dElapsedTime;
double	g_dDeltaTime;
bool	g_abKeyPressed[K_COUNT];
COORD	g_cConsoleSize;
int map1[10][10];
int map2[10][10];
int map3[10][10];
int map4[10][10];
int layout[79][28];

//p1 data
int p1heart,p1coordx,p1coordy;
//p2 data
int p2heart,p2coordx,p2coordy;

//bullet(20)
int b1directx,b1directy,b1coordx,b1coordy;
int b2directx,b2directy,b2coordx,b2coordy;
int b3directx,b3directy,b3coordx,b3coordy;
int b4directx,b4directy,b4coordx,b4coordy;
int b5directx,b5directy,b5coordx,b5coordy;
int b6directx,b6directy,b6coordx,b6coordy;
int b7directx,b7directy,b7coordx,b7coordy;
int b8directx,b8directy,b8coordx,b8coordy;
int b9directx,b9directy,b9coordx,b9coordy;
int b10directx,b10directy,b10coordx,b10coordy;
int b11directx,b11directy,b11coordx,b11coordy;
int b12directx,b12directy,b12coordx,b12coordy;
int b13direct,b13directy,b13coordx,b13coordy;
int b14directx,b14directy,b14coordx,b14coordy;
int b15directx,b15directy,b15coordx,b15coordy;
int b16directx,b16directy,b16coordx,b16coordy;
int b17directx,b17directy,b17coordx,b17coordy;
int b18directx,b18directy,b18coordx,b18coordy;
int b19directx,b19directy,b19coordx,b19coordy;
int b20directx,b20directy,b20coordx,b20coordy;
bool b1autotarget = false,b1bullet = false;
bool b2autotarget = false,b2bullet = false;
bool b3autotarget = false,b3bullet = false;
bool b4autotarget = false,b4bullet = false;
bool b5autotarget = false,b5bullet = false;
bool b6autotarget = false,b6bullet = false;
bool b7autotarget = false,b7bullet = false;
bool b8autotarget = false,b8bullet = false;
bool b9autotarget = false,b9bullet = false;
bool b10autotarget = false,b10bullet = false;
bool b11autotarget = false,b11bullet = false;
bool b12autotarget = false,b12bullet = false;
bool b13autotarget = false,b13bullet = false;
bool b14autotarget = false,b14bullet = false;
bool b15autotarget = false,b15bullet = false;
bool b16autotarget = false,b16bullet = false;
bool b17autotarget = false,b17bullet = false;
bool b18autotarget = false,b18bullet = false;
bool b19autotarget = false,b19bullet = false;
bool b20autotarget = false,b20bullet = false;

//monster(4)
int m1heart,m1coordx,m1coordy;
int m2heart,m2coordx,m2coordy;
int m3heart,m3coordx,m3coordy;
int m4heart,m4coordx,m4coordy;
bool m1autotarget = false;
bool m2autotarget = false;
bool m3autotarget = false;
bool m4autotarget = false;

//bosses(1)
int boss1heart,boss1coordx,bosscoordy;
int bossb1bullet,bossb1directx,bossb1directy,bossb1coordx,bossb1coordy;
bool boss1autotarget = false;

//passive
enum charms
{
	
}

//active
enum items
{
	
}

//active
enum monsters
{
	
}

//active
enum bosses
{
	
}


//--------------------------------------------------------------
// Purpose	: Initialisation function
// Input	: Void
// Output	: void
//--------------------------------------------------------------
void init( void )
{
    // Set precision for floating point output
    std::cout << std::fixed << std::setprecision(3);

	// set the name of your console window
    SetConsoleTitle(L"SP1 Framework");

    // Sets the console size, this is the biggest so far.
    setConsoleSize(79, 28);

    // Get console width and height
    CONSOLE_SCREEN_BUFFER_INFO csbi; /* to get buffer info */     

    /* get the number of character cells in the current buffer */ 
    GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );
    g_cConsoleSize.X = csbi.srWindow.Right + 1;
    g_cConsoleSize.Y = csbi.srWindow.Bottom + 1;
    
    for(int i=0;i<79;++i)
    {
        for(int j=0;j<24;++j)
        {
            layout[i][j]=0;
        }
    }

    for(int i=0;i<79;++i)
    {
        layout[i][0]=1;
    }
    for(int i=0;i<24;++i)
    {
       layout[0][i]=1;
        
       layout[78][i]=1;
    }
    for(int i=0;i<79;++i)
    {
         layout[i][23]=1;
    }

   p1coordx = 10; 
   p1coordy = 10;
    p2coordx = 11;
    p2coordy = 11;

    g_dElapsedTime = 0.0;
}

//--------------------------------------------------------------
// Purpose	: Reset before exiting the program
// Input	: Void
// Output	: void
//--------------------------------------------------------------
void shutdown( void )
{
    // Reset to white text on black background
	colour(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED);
}

//--------------------------------------------------------------
// Purpose	: Getting all the key press states
// Input	: Void
// Output	: void
//--------------------------------------------------------------
void getInput( void )
{    
   	//Player 1
	g_abKeyPressed[0x57] = isKeyPressed(0x57); //W --> Up 
	g_abKeyPressed[0x41] = isKeyPressed(0x41); //A --> Left
	g_abKeyPressed[0x53] = isKeyPressed(0x53); //S --> Down
	g_abKeyPressed[0x44] = isKeyPressed(0x44); //D --> Right
	g_abKeyPressed[0x56] = isKeyPressed(0x56); //V --> Shoot
	g_abKeyPressed[0x42] = isKeyPressed(0x42); //B --> Item
	g_abKeyPressed[0x4E] = isKeyPressed(0x4E); //N --> Bomb
	//Player 2
	g_abKeyPressed[0x26] = isKeyPressed(0x26); //Arrow Key Up --> Up 
	g_abKeyPressed[0x25] = isKeyPressed(0x25); //Arrow Key Left --> Left
	g_abKeyPressed[0x28] = isKeyPressed(0x28); //Arrow Key Down --> Down
	g_abKeyPressed[0x27] = isKeyPressed(0x27); //Arrow Key Right --> Right
	g_abKeyPressed[0x49] = isKeyPressed(0x49); //I --> Shoot
	g_abKeyPressed[0x4F] = isKeyPressed(0x4F); //O --> Item
	g_abKeyPressed[0x50] = isKeyPressed(0x50); //P --> Bomb
}

//--------------------------------------------------------------
// Purpose	: Update function
// Input	: dt = deltatime
// Output	: void
//--------------------------------------------------------------
void update(double dt)
{
    // get the delta time
    g_dElapsedTime += dt;
    g_dDeltaTime = dt;

    // Updating the location of the character based on the key press
	// providing a beep sound whenver we shift the character
    	//Player 1
    if (g_abKeyPressed[0x57])	//W --> Up
    {
		p1coordy--;
    }
    if (g_abKeyPressed[0x41]) //A --> Left
    {
		p1coordx--;
    }
    if (g_abKeyPressed[0x53])	 //S --> Down
    {
		p1coordy++;
    }
    if (g_abKeyPressed[0x44])	//D --> Right
    {
		p1coordx++;
    }
    
    
    //shooting p1
    

if (g_abKeyPressed[0x56])	//V --> Shoot
	{
		if (b1bullet == false)
		{

		}
		else if (b2bullet == false)
		{

		}
		else if (b3bullet == false)
		{

		}
		else if (b4bullet == false)
		{

		}
		else if (b5bullet == false)
		{

		}
		else if (b6bullet == false)
		{

		}
		else if (b7bullet == false)
		{

		}
		else if (b8bullet == false)
		{

		}
		else if (b9bullet == false)
		{

		}
		else if (b10bullet == false)
		{

		}
		else
		{
			//no effects
		}
	}
	
	

	//Player 2
	if (g_abKeyPressed[0x26])	//Arrow Key Up --> Up
	{
		p2coordy--;
	}
	if (g_abKeyPressed[0x25]) //Arrow Key Left --> Left
	{
		p2coordx--;
	}
	if (g_abKeyPressed[0x28])	 //Arrow Key Down --> Down
	{
		p2coordy++;
	}
	if (g_abKeyPressed[0x27])	//Arrow Key Right --> Right
	{
		p2coordx++;
	} 
    }


//shooting p2
if (g_abKeyPressed[0x56])	//V --> Shoot
	{
		if (b11bullet == false)
		{

		}
		else if (b12bullet == false)
		{

		}
		else if (b13bullet == false)
		{

		}
		else if (b14bullet == false)
		{

		}
		else if (b15bullet == false)
		{

		}
		else if (b16bullet == false)
		{

		}
		else if (b17bullet == false)
		{

		}
		else if (b18bullet == false)
		{

		}
		else if (b19bullet == false)
		{

		}
		else if (b20bullet == false)
		{

		}
		else
		{
			//no effects
		}
	}

}

//--------------------------------------------------------------
// Purpose	: Render function is to update the console screen
// Input	: void
// Output	: void
//--------------------------------------------------------------
void render( void )
{
    // clear previous screen
    colour(0x0F);
    cls();

    //render the game
     for(int i=0;i<79;++i)
    {
        std::cout<< "*";
    }
    std::cout << std::endl;
    for(int i=0;i<22;++i)
    {
        std::cout<<"*";
        for(int k=0;k<77;++k)
        {
            std::cout<< " ";
        }
        std::cout << "*";
        std::cout << std::endl;
    }
    for(int i=0;i<79;++i)
    {
        std::cout<<"*";
    }
    std::cout << std::endl;

    //render test screen code (not efficient at all)
    /*const WORD colors[] =   {
	                        0x1A, 0x2B, 0x3C, 0x4D, 0x5E, 0x6F,
	                        0xA1, 0xB2, 0xC3, 0xD4, 0xE5, 0xF6
	                        };
	                        */
	
gotoXY(p1coordx, p1coordy);
    colour(0x1A);
    std::cout << (char)236;
  
     gotoXY(p2coordx, p2coordy);
    colour(0x2B);
    std::cout << (char)2;

	if (b1bullet == false)
		{

		}
	if (b2bullet == false)
		{

		}
	if (b3bullet == false)
		{

		}
	if (b4bullet == false)
		{

		}
	if (b5bullet == false)
		{

		}
	if (b6bullet == false)
		{

		}
	if (b7bullet == false)
		{

		}
	if (b8bullet == false)
		{

		}
	if (b9bullet == false)
		{

		}
	if (b10bullet == false)
		{

		}
	if (b11bullet == false)
		{

		}
	if (b12bullet == false)
		{

		}
	if (b13bullet == false)
		{

		}
	if (b14bullet == false)
		{

		}
	if (b15bullet == false)
		{

		}
	if (b16bullet == false)
		{

		}
	if (b17bullet == false)
		{

		}
	if (b18bullet == false)
		{

		}
	if (b19bullet == false)
		{

		}
	if (b20bullet == false)
		{

		}

    gotoXY(0, 25);
    colour(0x59);
    std::cout << g_dElapsedTime << "secs" << std::endl;
}
