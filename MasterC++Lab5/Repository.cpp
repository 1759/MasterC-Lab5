#include "Repository.h"
using namespace std;

void Repository::addTutorial(const Tutorial & tutorial)
{
	this->tutorials.add(tutorial);	
}

Tutorial Repository::find(double id) {
	DynamicVector v = getTutorials();
	Tutorial* tutorials = v.getAllElems();

	for (int i = 0; i < v.getSize(); i++) {
		Tutorial t = tutorials[i];
		if (t.getId() == id)
			return t;	
	}
	return Tutorial();
}

void Repository::remove(Tutorial t)
{
	Tutorial tut = find(t.getId());
	if(tut == t)
		this->tutorials  = this->tutorials - t;
}

void Repository::update(const double id, const std::string & title, const std::string & presenter, const Duration & duration, const int & noLikes, const std::string & link)
{
	Tutorial t = this->tutorials.getElem(id);
	t.setPresenter(presenter);
	t.setDuration(duration);
	t.setNoLikes(noLikes);
	t.setLink(link);
}

DynamicVector Repository::getTutorialsByPresenter(const std::string& presenter) {
	DynamicVector v = getTutorials();
	DynamicVector resultList{};
	Tutorial* tutorials = v.getAllElems();
	for (int i = 0; i < v.getSize(); i++) {
		Tutorial t = tutorials[i];
		if (t.getPresenter() == presenter)
			resultList.add(t);
	}
	return resultList;
}