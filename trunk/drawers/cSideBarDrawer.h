/*
 * cSideBarDrawer.h
 *
 *  Created on: Aug 2, 2009
 *      Author: Stefan
 */

#ifndef CSIDEBARDRAWER_H_
#define CSIDEBARDRAWER_H_

class cSideBarDrawer {
	public:
		cSideBarDrawer();
		virtual ~cSideBarDrawer();

		void drawSideBar(cPlayer * player);

		cBuildingListDrawer * getBuildingListDrawer() { return buildingListDrawer; }

		bool isMouseOverScrollUp();
		bool isMouseOverScrollDown();

	protected:
		void drawHouseGui(cPlayer * thePlayer);
		void drawBuildingLists();
		void drawCapacities();
		void drawScrollButtons();

		void drawCandybar();

		// get
		int getScrollButtonUpX();
		int getScrollButtonY();
		int getScrollButtonDownX();
		bool isOverScrollButton(int buttonX, int buttonY);

		void drawMinimap();
		void drawOptionsBar();
		void drawIconsListBackground();

	private:
		cBuildingListDrawer * buildingListDrawer;

		// the 'candybar' is the bar with the ball at the top. Colored with the house color.
		BITMAP *candybar;
		BITMAP *optionsBar;

		int sidebarColor;

};

#endif /* CSIDEBARDRAWER_H_ */
