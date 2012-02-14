#ifndef MAPCAMERA_H
#define MAPCAMERA_H

class MapCamera {

	public:
		MapCamera();
		MapCamera(int x, int y);
		~MapCamera();
		
		int getX() { return x; }
		int getY() { return y; }

		void moveTo(int x, int y);

	private:
		int x, y;

	
};

#endif