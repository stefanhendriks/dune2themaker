/*
 * TextDrawer.cpp
 *
 *  Created on: 31-okt-2010
 *      Author: Stefan
 */

#include "../include/d2tmh.h"

cTextDrawer::cTextDrawer(ALFONT_FONT *theFont) {
	assert(theFont);
	font = theFont;
	applyShadow = true;
	textColor = makecol(255, 255, 255);
}

cTextDrawer::cTextDrawer() {
	font = small_font;
	applyShadow = true;
	textColor = makecol(255, 255, 255);
}

cTextDrawer::~cTextDrawer() {
	font = NULL;
}

void cTextDrawer::drawTextWithTwoIntegers(int x, int y, const char * msg, int var1, int var2) {
	if (applyShadow) {
		alfont_textprintf(bmp_screen, font, x + 1, y + 1, makecol(0, 0, 0), msg, var1, var2);
	}
	alfont_textprintf(bmp_screen, font, x, y, textColor, msg, var1, var2);
}

void cTextDrawer::drawTextWithOneInteger(int x, int y, const char * msg, int var) {
	if (applyShadow) {
		alfont_textprintf(bmp_screen, font, x + 1, y + 1, makecol(0, 0, 0), msg, var);
	}
	alfont_textprintf(bmp_screen, font, x, y, textColor, msg, var);
}

void cTextDrawer::drawText(int x, int y, const char * msg, int color) {
	if (applyShadow) {
		alfont_textprintf(bmp_screen, font, x + 1, y + 1, makecol(0, 0, 0), msg);
	}
	alfont_textprintf(bmp_screen, font, x, y, color, msg);
}

void cTextDrawer::drawText(int x, int y, const char * msg) {
	drawText(x, y, msg, textColor);
}

void cTextDrawer::drawTextCentered(const char *msg, int y) {
	drawTextCentered(msg, y, textColor);
}

void cTextDrawer::drawTextCentered(const char * msg, int y, int color) {
	int lenghtInPixels = getLenghtInPixelsForChar(msg);
	int half = lenghtInPixels / 2;
	int xPos = (game.getScreenResolution()->getWidth() / 2) - half;
	drawText(xPos, y, msg, color);
}



void cTextDrawer::drawTextBottomRight(const char * msg) {
	int x = getXCoordinateForBottomRight(msg);
	int y = getYCoordinateForBottomRight();
	drawText(x, y, msg);
}

int cTextDrawer::getXCoordinateForBottomRight(const char * msg) {
	return game.getScreenResolution()->getWidth() - getLenghtInPixelsForChar(msg);
}

int cTextDrawer::getLenghtInPixelsForChar(const char * msg) {
	return alfont_text_length(font, msg);
}

int cTextDrawer::getYCoordinateForBottomRight() {
	return game.getScreenResolution()->getHeight() - alfont_text_height(font);
}

void cTextDrawer::drawTextBottomLeft(const char * msg) {
	int y = game.getScreenResolution()->getHeight() - alfont_text_height(font);
	drawText(0, y, msg);
}