#ifndef COLORS_H
#define COLORS_H

class Colors {
	public:
		static Uint32 black(SDL_Surface * surface) {
			return SDL_MapRGB(surface->format, 0, 0, 0); 
		}

		static Uint32 purple(SDL_Surface * surface) {
			return SDL_MapRGB(surface->format, 255, 0, 255); 
		}

};

#endif