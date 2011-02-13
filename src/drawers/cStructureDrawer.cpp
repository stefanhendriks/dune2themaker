/*
 * cStructureDrawer.cpp
 *
 *  Created on: 23-okt-2010
 *      Author: Stefan
 */

#include "../include/d2tmh.h"

cStructureDrawer::cStructureDrawer() {
}

cStructureDrawer::~cStructureDrawer() {
}

void cStructureDrawer::drawStructuresFirstLayer() {
	drawStructuresForLayer(0);
}

void cStructureDrawer::drawStructuresSecondLayer() {
	drawStructuresForLayer(2);
}

void cStructureDrawer::drawStructuresHealthBars() {

	cGameControlsContext * context = player[HUMAN].getGameControlsContext();

    // DRAW HEALTH
    if (context->isMouseOverStructure())
    {
        int i = context->getIdOfStructureWhereMouseHovers();
        drawStructureHealthBar(i);
    }
}

void cStructureDrawer::drawRectangeOfStructure(cAbstractStructure * theStructure, int color) {
	assert(theStructure);
	int drawX = getDrawXForStructure(theStructure->getCell());
	int drawY = getDrawYForStructure(theStructure->getCell());
	int width_x = structures[theStructure->getType()].bmp_width-1;
	int height_y = structures[theStructure->getType()].bmp_height-1;
	rect(bmp_screen, drawX, drawY, drawX + width_x, drawY + height_y, color);
}

void cStructureDrawer::drawStructurePrebuildAnimation(cAbstractStructure * structure) {
	int iDrawPreBuild = determinePreBuildAnimationIndex(structure);

	int drawX = getDrawXForStructure(structure->getCell());
	int drawY = getDrawYForStructure(structure->getCell());

    // Draw prebuild
    draw_sprite(bmp_screen, (BITMAP *)gfxdata[iDrawPreBuild].dat, drawX, drawY);

    // Draw shadow of the prebuild animation
    if (iDrawPreBuild != BUILD_PRE_CONST) {
        set_trans_blender(0,0,0,128);
        draw_trans_sprite(bmp_screen, (BITMAP *)gfxdata[iDrawPreBuild + 1].dat, drawX, drawY);
    }

}

int cStructureDrawer::getDrawYForStructure(int cell) {
	assert(structure);
	cCellCalculator * cellCalculator = map.getCellCalculator();
	int y = cellCalculator->getY(cell);
	return (y * TILESIZE_HEIGHT_PIXELS) - (mapCamera->getY() * TILESIZE_HEIGHT_PIXELS) + 42;
}

int cStructureDrawer::getDrawXForStructure(int cell) {
	assert(structure);
	cCellCalculator * cellCalculator = map.getCellCalculator();
	int x = cellCalculator->getX(cell);
	return (x * TILESIZE_WIDTH_PIXELS) - (mapCamera->getX() * TILESIZE_WIDTH_PIXELS);
}

void cStructureDrawer::drawStructureAnimation(cAbstractStructure * structure) {
	assert(structure);

	cStructureUtils structureUtils;

	int widthInPixels = structureUtils.getStructureWidthInPixels(structure);
	int heightInPixels = structureUtils.getStructureHeightInPixels(structure);

    // structures are animated within the same source bitmap. The Y coordinates determine
    // what frame is being drawn. So multiply the height of the structure size times frame
    int iSourceY = heightInPixels * structure->getFrame();

	BITMAP *temp=create_bitmap_ex(8, widthInPixels, heightInPixels);
	BITMAP *temp_shadow=create_bitmap(widthInPixels, heightInPixels);

	clear(temp);

	clear_to_color(temp_shadow, makecol(255,0,255));

	blit(structure->getBitmap(), temp, 0, iSourceY, 0, 0, widthInPixels, heightInPixels);

	// in case shadow, prepare shadow bitmap in memory
	if (structure->getShadowBitmap()) {
		blit(structure->getShadowBitmap(), temp_shadow, 0, iSourceY, 0, 0, widthInPixels, heightInPixels);
	}

	int drawX = getDrawXForStructure(structure->getCell());
	int drawY = getDrawYForStructure(structure->getCell());

	// draw normal structure
	draw_sprite(bmp_screen, temp, drawX, drawY);

	// in case shadow, draw shadow now using fBlend.
	if (structure->getShadowBitmap()) {
		fblend_trans(temp_shadow, bmp_screen, drawX, drawY, 128);
	}

	// destroy used bitmaps
	destroy_bitmap(temp);
	destroy_bitmap(temp_shadow);
}

int cStructureDrawer::determinePreBuildAnimationIndex(cAbstractStructure * structure) {
	assert(structure);
	int iBuildFase = structure->getBuildingFase();
	int height = structure->getHeight();
	int width = structure->getWidth();

    // prebuild
    if (iBuildFase == 1 ||
        iBuildFase == 3 ||
        iBuildFase == 5 ||
        iBuildFase == 7 ||
        iBuildFase == 9) {

        // determine what kind of prebuild picture should be used.
		if (width == 1 && height == 1) {
			return BUILD_PRE_1X1;
		}

		if (width == 2 && height == 2) {
            return BUILD_PRE_2X2;
		}

		if (width == 3 && height == 2) {
            return BUILD_PRE_3X2;
		}

		if (width == 3 && height == 3) {
           return BUILD_PRE_3X3;
		}
    }

    return -1;
}

void cStructureDrawer::drawStructureAnimationWindTrap(cAbstractStructure * structure) {
	assert(structure);
	assert(structure->getType() == WINDTRAP);

	cWindTrap * windtrap = dynamic_cast<cWindTrap*>(structure);

	assert(structure);

	cStructureUtils structureUtils;

	int widthInPixels = structureUtils.getStructureWidthInPixels(structure);
	int heightInPixels = structureUtils.getStructureHeightInPixels(structure);

	int drawX = getDrawXForStructure(structure->getCell());
	int drawY = getDrawYForStructure(structure->getCell());

    // structures are animated within the same source bitmap. The Y coordinates determine
    // what frame is being drawn. So multiply the height of the structure size times frame
    int iSourceY = heightInPixels * structure->getFrame();

	int fade = windtrap->getFade();

	BITMAP *temp=create_bitmap_ex(8, widthInPixels, heightInPixels);
	BITMAP *temp_shadow=create_bitmap(widthInPixels, heightInPixels);
    BITMAP *wind=create_bitmap(widthInPixels, heightInPixels);

	clear(temp);
    clear_to_color(wind, makecol(255,0,255));
	clear_to_color(temp_shadow, makecol(255,0,255));

	blit(structure->getBitmap(), temp, 0, iSourceY, 0, 0, widthInPixels, heightInPixels);

	// in case shadow, prepare shadow bitmap in memory
	if (structure->getShadowBitmap()) {
		blit(structure->getShadowBitmap(), temp_shadow, 0, iSourceY, 0, 0, widthInPixels, heightInPixels);
	}

//	// draw normal structure
//	draw_sprite(bmp_screen, temp, drawX, drawY);

	// windtrap animation
	draw_sprite(wind, temp, 0, 0);
	lit_windtrap_color(wind, makecol(0, 0, fade));
	draw_sprite(bmp_screen, wind, drawX, drawY);

	// in case shadow, draw shadow now using fBlend.
	if (structure->getShadowBitmap()) {
		fblend_trans(temp_shadow, bmp_screen, drawX, drawY, 128);
	}


	// destroy used bitmaps
	destroy_bitmap(temp);
	destroy_bitmap(temp_shadow);
    destroy_bitmap(wind);
}

void cStructureDrawer::drawStructureAnimationTurret(cAbstractStructure * structure) {
	assert(structure);
	assert(structure->getType() == TURRET || structure->getType() == RTURRET);

	int iHeadFacing = -1;
	if (structure->getType() == TURRET) {
		cGunTurret * gunTurret = dynamic_cast<cGunTurret *>(structure);
		iHeadFacing = gunTurret->getHeadFacing();
	} else if (structure->getType() == RTURRET) {
		cRocketTurret * rocketTurret = dynamic_cast<cRocketTurret *>(structure);
		iHeadFacing = rocketTurret->getHeadFacing();
	}
	assert(iHeadFacing > -1);

	structure->setFrame(convert_angle(iHeadFacing));

	drawStructureAnimation(structure);
}

void cStructureDrawer::drawStructureAnimationRefinery(cAbstractStructure * structure) {
	assert(structure);
	assert(structure->getType() == REFINERY);

	int oldFrame = structure->getFrame();

	// Refinery has content, then the frame is a bit different
	if (structure->hasUnitWithin()) {
		structure->setFrame(structure->getFrame() + 5);
	}

	drawStructureAnimation(structure);

	// restore iFrame again
	structure->setFrame(oldFrame);
}

void cStructureDrawer::drawStructureForLayer(cAbstractStructure * structure, int layer) {
	assert(structure);

	cStructureUtils structureUtils;

	// always select proper palette (of owner)
    select_palette(player[structure->getOwner()].pal);

	// when layer is <= 1 the building is just being placed. The prebuild
	// animation should be be drawn or, the normal drawing is shown (ie the
	// structure is not in action, like deploying harvester etc).

	// when stage == 2, it means only to draw the repair animation above the structure
	// this is done after all the structures have been drawn with stage 1 or lower. Causing
	// the repair icons to always overlap other structures. This is ugly, the repair icons
	// should be 'particles' (like smoke etc) instead of being hacked here!

	if (layer <= 1) {
        int iDrawPreBuild = determinePreBuildAnimationIndex(structure);

        // if no prebuild picture is selected, than we should draw the building
		// itself. The reason why the above if uses only buildfase 1, 3, 5, 7 and 9 means
		// that it will cause the switching between pre-build/building state as if the
		// building is being 'readied' after placement.
        if (iDrawPreBuild < 0) {
        	if (structure->getType() == WINDTRAP) {
        		// draw windtrap
        		drawStructureAnimationWindTrap(structure);
        	} else if (structure->getType() == TURRET || structure->getType() == RTURRET) {
        		drawStructureAnimationTurret(structure);
        	} else if (structure->getType() == REFINERY) {
        		drawStructureAnimationRefinery(structure);
        	} else {
        		drawStructureAnimation(structure);
        	}
        } else {
        	drawStructurePrebuildAnimation(structure);
        }
	}
	else if (layer == 2) {
		// TODO: REMOVE THIS CODE AND create particles for this
		// now draw the repair alpha when repairing
		if (structure->isRepairing()) {
			if (structure->getRepairAlpha() > -1) {
				set_trans_blender(0, 0, 0, structure->getRepairAlpha());
				int drawX = getDrawXForStructure(structure->getCell());
				int drawY = getDrawYForStructure(structure->getCell());
				int repairX = structure->getRepairX();
				int repairY = structure->getRepairY();
				draw_trans_sprite(bmp_screen, (BITMAP *)gfxdata[MOUSE_REPAIR].dat, drawX+repairX, drawY + repairY);
			} else {
				structure->setRepairAlpha(rnd(255));
			}
		}
	}
}

void cStructureDrawer::drawStructuresForLayer(int layer) {
	// draw all structures
	cStructureUtils structureUtils;

	for (int i=0; i < MAX_STRUCTURES; i++) {
		cAbstractStructure * theStructure = structure[i];

		if (theStructure) {

			structureUtils.putStructureOnDimension(MAPID_STRUCTURES, theStructure);

			if (structureUtils.isStructureOnScreen(theStructure))
			{
				// draw
				drawStructureForLayer(theStructure, layer);
				//theStructure->draw(layer);

				if (player[0].iPrimaryBuilding[theStructure->getType()] == i) {
					int color = theStructure->getPlayer()->getMinimapColor();
					// TODO: change it into fading color or something other than this ugly rectangle.
					drawRectangeOfStructure(theStructure, color);
				}

				if (i == game.selected_structure) {
					drawRectangeOfStructure(theStructure, makecol(game.fade_select, game.fade_select, game.fade_select));
				}
			}

		}

	}

	rectfill(bmp_screen, (game.screen_x-160), 0, game.screen_x, game.screen_y, makecol(0,0,0));
}

void cStructureDrawer::drawStructureHealthBar(int iStructure) {

	cAbstractStructure * theStructure = structure[iStructure];

	// Draw structure health
	int draw_x = getDrawXForStructure(theStructure->getCell()) - 1;
	int draw_y = getDrawYForStructure(theStructure->getCell()) - 5;

	int widthBmp = theStructure->getS_StructuresType().bmp_width;
	int width_x = widthBmp - 1;

	int height_y = 4;

	if (draw_y < 30) {
		draw_y = 30;
	}

	int w = health_structure(iStructure, widthBmp);

	int step = (255/widthBmp);
	int r = 255-(w*step);
	int g = w*step;

	if (g > 255)
		g = 255;
	if (r < 0) r= 0;


	// shadow
   // rectfill(bmp_screen, draw_x+2, draw_y+2, draw_x + width_x + 2, draw_y + height_y + 2, makecol(0,0,0));

	// bar itself
	rectfill(bmp_screen, draw_x, draw_y, draw_x + width_x+1, draw_y + height_y+1, makecol(0,0,0));
	rectfill(bmp_screen, draw_x, draw_y, draw_x + (w-1), draw_y + height_y, makecol(r,g,32));

	// bar around it
	rect(bmp_screen, draw_x, draw_y, draw_x + width_x, draw_y + height_y, makecol(255, 255, 255));
}
