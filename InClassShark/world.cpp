//   PROBLEM 11 - page 878 of the Savitch Textbook
#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

const int WORLDSIZE = 20;
const int INITIALANTS = 100;
const int INITIALBUGS = 1;
const int INITIALSHARK = 1;

const int DOODLEBUG = 1;
const int ANT = 2;
const int SHARK =1;    //   added SH
const int ANTBREED = 3;
const int DOODLEBREED = 8;
const int DOODLESTARVE = 3;
const int SHARKBREED = 9;      // added SH
const int SHARKSTARVE = 10;     // added SH

// Forward declaration of Organism classes so we can reference it
// in the World class
class Organism;
class Doodlebug;
class Ant;
class Shark;        // added SH
#include "Organism.h"
//#include "Ant.h"
//#include "Doodlebug.h"

// ==========================================
// The World class stores data about the world by creating a
// WORLDSIZE by WORLDSIZE array of type Organism.
// NULL indicates an empty spot, otherwise a valid object
// indicates an ant or doodlebug.  To determine which,
// invoke the virtual function getType of Organism that should return
// ANT if the class is of type ant, and DOODLEBUG otherwise.
// ==========================================

class World
{
friend class Organism;			// Allow Organism to access grid
friend class Doodlebug;			// Allow Doodlebug to access grid
friend class Ant;			    // Allow Ant to access grid

friend class Shark;			// Allow Shark to access grid

public:
	World();
	~World();
	Organism* getAt(int x, int y);
	void setAt(int x, int y, Organism *org);
	void Display();
	void SimulateOneStep();
private:
	Organism* grid[WORLDSIZE][WORLDSIZE];
};
#endif



