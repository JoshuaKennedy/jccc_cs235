#include "Shark.h"
// ======================
// Shark constructor
// ======================
Shark::Shark() : Organism()
{
	starveTicks = 0;
}

Shark::Shark(World *world, int x, int y) : Organism(world,x,y)
{
	starveTicks = 0;
}

// ======================
// Shark move
// Look up, down, left or right for a bug.  If one is found, move there
// and eat it, resetting the starveTicks counter.
// ======================
void Shark::move()
{
	// Look in each direction and if a bug is found move there
	// and eat it.
	
	if ((x>0) && (world->getAt(x-1,y)!=NULL) &&
		     (world->getAt(x-1,y)->getType() == ANT))
	{
		delete (world->grid[x-1][y]);  // Kill ant
		world->grid[x-1][y] = this;    // Move to spot
		world->setAt(x,y,NULL);
		starveTicks =0 ;	  	// Reset hunger
		x--;
		return;
	}
	else if ((x<WORLDSIZE-1) && (world->getAt(x+1,y)!=NULL) &&
		     (world->getAt(x+1,y)->getType() == ANT))
	{
		delete (world->grid[x+1][y]);  // Kill ant
		world->grid[x+1][y] = this;    // Move to spot
		world->setAt(x,y,NULL);
		starveTicks =0 ;	  	// Reset hunger
		x++;
		return;
	}


	// If we got here, then we didn't find food.  Move
	// to a random spot if we can find one.
	int dir = rand() % 4;
	// Try to move up, if not at an edge and empty spot
	if (dir==0)
	{
		if ((y>0) && (world->getAt(x,y-1)==NULL))
		{
		 world->setAt(x,y-1,world->getAt(x,y));  // Move to new spot
		 world->setAt(x,y,NULL);
		 y--;
		}
	}
	// Try to move down
	else if (dir==1)
	{
		if ((y<WORLDSIZE-1) && (world->getAt(x,y+1)==NULL))
		{
		 world->setAt(x,y+1,world->getAt(x,y));  // Move to new spot
		 world->setAt(x,y,NULL);  // Set current spot to empty
		 y++;
		}
	}

	starveTicks++;		// Increment starve tick since we didn't
				// eat on this turn
}

// ======================
// Shark getType
// This virtual function is used so we can determine
// what type of organism we are dealing with.
// ======================
int Shark::getType()
{
	return SHARK;
}

// ======================
// Shark breed
// Creates a new doodlebug adjacent to the current cell
// if the breedTicks meets the threshold.
// ======================
void Shark::breed()
{
	breedTicks++;
	if (breedTicks == DOODLEBREED)
	{
		breedTicks = 0;
		// Try to make a new Doodlebug either above, left, right, or down
		if ((y>0) && (world->getAt(x,y-1)==NULL))
		{
			Shark *newDoodle = new Shark(world, x, y-1);
		}
		else if ((y<WORLDSIZE-1) && (world->getAt(x,y+1)==NULL))
		{
			Shark *newDoodle = new Shark(world, x, y+1);
		}
		else if ((x>0) && (world->getAt(x-1,y)==NULL))
		{
			Shark *newDoodle = new Shark(world, x-1, y);
		}
		else if ((x<WORLDSIZE-1) && (world->getAt(x+1,y)==NULL))
		{
			Shark *newDoodle = new Shark(world, x+1, y);
		}
	}
}

// ======================
// Shark starve
// Returns true or false if a doodlebug should die off
// because it hasn't eaten enough food.
// ======================
bool Shark::starve()
{
	// Starve if no food eaten in last SHARKSTARVE time ticks
	if (starveTicks > SHARKSTARVE)      // changed SH
	{
		return true;
	}
	else
	{
		return false;
	}
}




