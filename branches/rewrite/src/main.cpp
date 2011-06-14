// THIS IS JUST A TEST APPLICATION TO SEE IF SDL WORKS AND SUCH.

#include <iostream>

#include <SDL/SDL.h>

using namespace std;

SDL_Surface *screen;

void drawGraphic(SDL_Surface *graphic, int x, int y) {
  //initialize SDL_Rect struct to hold destination blitting data
  SDL_Rect dst;

  //fill dst with relevant information
  dst.x=x;
  dst.y=y;
  dst.w=graphic->w;
  dst.h=graphic->h;

  //blit the graphic to the screen
  SDL_BlitSurface(graphic,NULL,screen,&dst);
}

int main(int argc, char **argv) {
  //declare pointer to reference the graphic (done here for plain C compatibility)
  SDL_Surface *my_graphic;

  //e stores the event union which is fetched from the event queue
  SDL_Event e;

  //initialize SDL and the video subsytem
  SDL_Init(SDL_INIT_VIDEO);

  //set a 640x480x32 double-buffered window
  screen = SDL_SetVideoMode(640,480,32,SDL_HWSURFACE|SDL_DOUBLEBUF);

  //load the graphic from a file
  my_graphic = SDL_LoadBMP("some_graphic_file.bmp");


  int running=1;
  while (running) {
    //clear the screen
    SDL_FillRect(screen,NULL,SDL_MapRGB(screen->format,0,0,0));

    //draw the graphic
    drawGraphic(my_graphic,10,10);

    //update the screen
    SDL_Flip(screen);

    //check the event queue
    while (SDL_PollEvent(&e)) {
      switch (e.type) {
      case SDL_KEYDOWN:
        if (e.key.keysym.sym==SDLK_ESCAPE) running=0;
        break;
      case SDL_QUIT:
        running=0;
        break;
      }
    }
  }

  //deinitialize SDL
  SDL_FreeSurface(my_graphic);
  SDL_Quit();
  return 0;
}
