#ifndef TERRAINTYPES_H
#define TERRAINTYPES_h

#include "terraintype.h"

class TerrainTypes {

	public:
		static TerrainType getSand() {
			TerrainType sand;
			sand.speedModifier = 1.0F;
			return sand;
		};
		
		static TerrainType getRock() {
			TerrainType rock;
			rock.speedModifier = 0.9F;
			return rock;
		};

		static TerrainType getSpice() {
			TerrainType spice;
			spice.speedModifier = 0.9F;
			return spice;
		};

};

#endif