#include "WatchList.h"

void WatchList::likeTutorial(const Tutorial& tutorial)
{
	this->tutorials.add(tutorial);
}

Tutorial WatchList::getCurrentTutorial()
{
	if (this->current == this->tutorials.getSize())
		this->current = 0;
	Tutorial* elems = this->tutorials.getAllElems();
	if (elems != NULL)
		return elems[this->current];
	return Tutorial{};
}

void WatchList::play()
{
	if (this->tutorials.getSize() == 0)
		return;
	this->current = 0;
	Tutorial currentTutorial = this->getCurrentTutorial();
	currentTutorial.play();
}

void WatchList::next()
{
	if (this->tutorials.getSize() == 0)
		return;
	this->current = 0;
	Tutorial currentTutorial = this->getCurrentTutorial();
	currentTutorial.play();
}

bool WatchList::isEmpty()
{
	return this->tutorials.getSize() == 0;
}