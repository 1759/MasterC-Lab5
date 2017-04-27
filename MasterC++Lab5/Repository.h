#pragma once
#include "Tutorial.h"
#include "DynamicVector.h"

class Repository {
private:
	DynamicVector tutorials;
public:
	Repository(){}
	void addTutorial(const Tutorial& tutorial);
	Tutorial Repository::find(double id);
	void remove(const Tutorial t);
	void update(const double id, const std::string& title, const std::string& presenter, const Duration& duration, const int& noLikes, const std::string& link);

	DynamicVector getTutorials() const { return tutorials; }
	DynamicVector getTutorialsByPresenter(const std::string& presenter);
};

