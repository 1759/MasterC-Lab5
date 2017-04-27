#pragma once
#include "Repository.h"
#include "WatchList.h"

class Controller {
private:
	Repository repo;
	
public:
	Controller(const Repository& repo):repo(repo){}
	Repository getRepo()const { return repo; }

	//administrator
	void addTutorialAdmin(const std::string& title, const std::string& presenter, const int minutes, const int seconds, const int noLikes, const std::string link);
	void removeTutorialAdmin(const double id);
	void updateTutorialAdmin(const double id, const std::string & title, const std::string & presenter, const int minutes, const int seconds, const int & noLikes, const std::string & link);

};