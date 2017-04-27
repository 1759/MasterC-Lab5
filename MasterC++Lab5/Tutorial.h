#pragma once
#include <iostream>

class Duration {
private:
	int seconds;
	int minutes;

public:
	Duration() : minutes(0), seconds(0) {}
	Duration(int min, int sec) : minutes(min), seconds(sec) {}

	int getMinutes() const { return minutes; }
	int getSeconds() const { return seconds; }
	void setMinutes(int minutes) {
		this->minutes = minutes;
	}
	void setSeconds(int seconds) {
		this->seconds =seconds;
	}
};

class Tutorial {
private:
	double id;
	std::string title;
	std::string presenter;
	Duration duration;
	int noLikes;
	std::string link;

public:
	Tutorial(){}
	Tutorial(const std::string& title, const std::string& presenter,
		const Duration& duration, const int noLikes, const std::string& link);

	double getId() const { return id; }
	std::string getTitle() const { return title; }
	std::string getPresenter() const { return presenter; }
	std::string getLink() const { return link; }
	Duration getDuration() { return duration; }
	int getLikes() { return noLikes; }

	std::string toString();

	bool Tutorial::operator==(Tutorial& t);

	void setPresenter(std::string p) { presenter = p; }
	void setLink(std::string l) { link = l; }
	void setNoLikes(int likes) { noLikes = likes; }
	void setDuration(Duration d) { duration = d; }

	void play();

};