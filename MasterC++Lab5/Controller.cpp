#include "Controller.h"
#include <iostream>
#include <string>
using namespace std;

void Controller::addTutorialAdmin(const std::string& title, const std::string& presenter, const int minutes, const int seconds, const int noLikes, const std::string link) {
	Duration duration = Duration(minutes, seconds);
	Tutorial t{ title, presenter, duration, noLikes, link };
	this->repo.addTutorial(t);
}

void Controller::removeTutorialAdmin(const double id) {
	Tutorial t= this->repo.find(id);
	this->repo.remove(t);
}

void Controller::updateTutorialAdmin(const double id, const std::string& title, const std::string& presenter, const int minutes, const int seconds, const int& noLikes, const std::string& link) {
	Duration duration = Duration(minutes, seconds);
	this->repo.update(id, title, presenter, duration, noLikes, link);

}