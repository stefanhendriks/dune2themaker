/*
 * cParticleDrawer.h
 *
 *  Created on: 11-aug-2010
 *      Author: Stefan
 */

#ifndef CPARTICLEDRAWER_H_
#define CPARTICLEDRAWER_H_

class ParticleDrawer {
	public:
		ParticleDrawer();
		~ParticleDrawer();

		void drawLayerBeneathUnits();
		void drawHigherLayer();

	protected:
		void drawLayer(int layer);

	private:

};

#endif /* CPARTICLEDRAWER_H_ */
