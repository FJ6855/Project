#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Game.h"
#include "MenuSystem.h"

const int SCREEN_WIDTH = 896;
const int SCREEN_HEIGHT = 512;

bool init();
void drawGame();
void clearScreen();
void quitGame();

TTF_Font* gFont = nullptr;
SDL_Renderer* gRenderer = nullptr;
SDL_Window* gWindow = nullptr;

InputHandler* input;
ResourceManager* rm;
HighScore* highScore;
Game* game;
MenuSystem* menuSystem;

int main(int argc, char* argv[])
{
    if (!init())
    {		
	return 1;
    }

    input = new InputHandler();
    rm = new ResourceManager(gRenderer, gFont);
    highScore = new HighScore(rm);
    game = new Game(input, rm, highScore, gRenderer);
    menuSystem = new MenuSystem(input, rm, highScore, gRenderer);

    int fps{0};
    int timeStart = SDL_GetTicks();

    while (!input->isQuit())
    {
	input->update();
      
	clearScreen();

	game->run();
	menuSystem->run();

	drawGame();

	//Enkel fpsr�knare
	fps++;
	if (SDL_GetTicks() - timeStart >= 1000)
	{
	    //std::cout << "Fps: " << fps << std::endl;
	    timeStart = SDL_GetTicks();
	    fps = 0;
	}
    }

    highScore->saveScores(rm);

    quitGame();
    
    return 0;
}

void drawGame()
{
    SDL_RenderPresent(gRenderer);
}

void clearScreen()
{
    SDL_RenderClear(gRenderer);
}

bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
	printf("SDL could not initialize SDL_Error: %s\n", SDL_GetError());
	return false;
    }
    //Create Window
    gWindow = SDL_CreateWindow("SaftEngine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL)
    {
	printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
	return false;
    }
    //Create renderer for window
    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (gRenderer == NULL)
    {
	printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
	return false;
    }
  
    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags))
    {
	printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
	return false;
    }

    //Initialize SDL_ttf
    if (TTF_Init() == -1)
    {
	printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
	return false;
    }

    gFont = TTF_OpenFont("./res/fonts/alphbeta.ttf", 20);
    if (gFont == NULL)
    {
	printf("Failed to load lazy font! SDL_ttf Error: %s\n", TTF_GetError());
	return false;
    }
  
    //Initialize renderer color
    SDL_SetRenderDrawColor(gRenderer, 0x0, 0x0, 0x0, 0x0);

    return true;
}

void quitGame()
{
    TTF_CloseFont(gFont);
    gFont = nullptr;
    
    SDL_DestroyRenderer(gRenderer);
    gRenderer = nullptr;

    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    
    delete input;
    input = nullptr;

    delete rm;
    rm = nullptr;

    delete highScore;
    highScore = nullptr;

    delete game;
    game = nullptr;

    delete menuSystem;
    menuSystem = nullptr;

    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}
