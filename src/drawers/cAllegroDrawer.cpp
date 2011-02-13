/*
 * cAllegroDrawer.cpp
 *
 *  Created on: 5 dec. 2010
 *      Author: Stefan
 */

#include "../include/d2tmh.h"

cAllegroDrawer::cAllegroDrawer() {
}

cAllegroDrawer::~cAllegroDrawer() {
}

void cAllegroDrawer::drawCenteredSprite(BITMAP *dest, BITMAP *src) {
	assert(src);
	assert(dest);
	int xPos = getCenteredXPosForBitmap(src);
	int yPos = getCenteredXPosForBitmap(src);
	draw_sprite(dest, src, xPos, yPos);
}

void cAllegroDrawer::drawSpriteCenteredRelativelyVertical(BITMAP *dest, BITMAP* src, float percentage) {
	int xPos = getCenteredXPosForBitmap(src);

	// we want to know the 'center' first. This is done in the percentage
	int wantedYPos = ((float)game.screen_y * percentage);

	// we need to know the height of the src
	int height = src->h;
	int halfOfHeight = height / 2;
	int yPos = wantedYPos - halfOfHeight;
	draw_sprite(dest, src, xPos, yPos);
}


void cAllegroDrawer::drawCenteredSpriteHorizontal(BITMAP *dest, BITMAP *src, int y) {
	assert(src);
	assert(dest);
	int xPos = getCenteredXPosForBitmap(src);
	draw_sprite(dest, src, xPos, y);
}

void cAllegroDrawer::drawCenteredSpriteVertical(BITMAP *dest, BITMAP *src, int x) {
	assert(src);
	assert(dest);
	int yPos = getCenteredXPosForBitmap(src);
	draw_sprite(dest, src, x, yPos);
}

int cAllegroDrawer::getCenteredXPosForBitmap(BITMAP *bmp) {
	assert(bmp);
	int width = bmp->w;
	int halfOfWidth = width / 2;
	return (game.screen_x / 2) - halfOfWidth;
}

int cAllegroDrawer::getCenteredYPosForBitmap(BITMAP *bmp) {
	assert(bmp);
	int height = bmp->h;
	int halfOfHeight = height / 2;
	return (game.screen_y / 2) - halfOfHeight;
}
