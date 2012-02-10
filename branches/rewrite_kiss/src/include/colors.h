#ifndef COLORS_H
#define COLORS_H

class Colors {
	public:
		static Uint32 black(SDL_Surface * surface) {
			return SDL_MapRGB(surface->format, 0, 0, 0); 
		}

};

#endif