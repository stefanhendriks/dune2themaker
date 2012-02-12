#include <iostream>
#include <string>

using namespace std;

#include "tileset.h"

void assertThat(string testDescription, int expected, int actual) {
	bool expression = (expected == actual);
	cout << "--- TEST CASE --- [" << testDescription << "] RESULT --> ";

	if (expression) {
		cout << "PASSED";
	} else {
		cout << "FAILED";
		cout << ", the actual is [" << actual << "]";
	}

	cout << "!!!" << endl;
}


void mustReturnZerosForIndexZero() {
	Tileset * tileset = new Tileset(NULL, 32, 32);
	tileset->init(640, 640);

	SDL_Rect rect = tileset->get(0);
	assertThat("For tileset.get(0) rect.x should be 0", 0, rect.x);
	assertThat("For tileset.get(0) rect.y should be 0", 0, rect.y);
}

void mustReturnZeroForXAndOneForYForIndexTwentyOne() {
	Tileset * tileset = new Tileset(NULL, 32, 32);
	tileset->init(640, 640);

	SDL_Rect rect = tileset->get(20);
	assertThat("For tileset.get(20) rect.x should be 0", 0, rect.x);
	assertThat("For tileset.get(21) rect.y should be 32", 32, rect.y);
}



// TEST SUITE
void tilesetTestSuite() {
	cout << "==== testTilesetIndexCalculation ==== BEGIN" << endl;

	mustReturnZerosForIndexZero();
	mustReturnZeroForXAndOneForYForIndexTwentyOne();

	cout << "==== testTilesetIndexCalculation ==== END" << endl;
}


int main(int argc, char **argv) {
	// test cases
	tilesetTestSuite();

	return 0;
}

