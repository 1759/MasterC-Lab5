#include "Tutorial.h"
#include <Windows.h>
#include <string>
#include <shellapi.h>
#include<iostream>

Tutorial::Tutorial(const std::string& title, const std::string& presenter,
	const Duration& duration, const int noLikes, const std::string& link) {
	this->title = title;
	this->presenter = presenter;
	this->duration = duration;
	this->noLikes = noLikes;
	this->link = link;
	this->id = title[title.length()-1] - title[0]%7 + noLikes % 5 + duration.getMinutes() - presenter.length() + duration.getSeconds();
}

bool Tutorial::operator==(Tutorial& t1) {
	if (this->id == t1.getId())
		return true;
	return false;
}

std::string Tutorial::toString()
{
	std::string s = std::to_string(id) + "	Tutorial: " + title + " by pesenter: " + presenter + " has: " + std::to_string(noLikes) + " likes.\n";
	return s;
}

void Tutorial::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->getLink().c_str(), NULL, SW_SHOWMAXIMIZED);
}