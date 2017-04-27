#include "Tutorial.h"
#include "UI.h"
#include <Windows.h>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	system("color f4");

	Repository repo{};

	// add some songs
	Tutorial s1{ "vid1", "presenter1", Duration{ 4, 54 }, 12, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	Tutorial s2{ "vid2", "presenter1", Duration{ 4, 54 }, 12, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	Tutorial s3{ "vid3", "presenter3", Duration{ 4, 54 }, 12, "https://www.youtube.com/watch?v=2fngvQS_PmQ" };
	repo.addTutorial(s1);
	repo.addTutorial(s2);
	repo.addTutorial(s3);
	DynamicVector v = repo.getTutorials();
	v = v - s1;
	Tutorial* tutorials = v.getAllElems();
	for (int i = 0; i < v.getSize(); i++) {
		Tutorial t = tutorials[i];
		cout << t.toString();
	}

	if (s1 == s2)
		cout << "s1 and s2 are equal";
	else
		cout << "not equal";

	Controller ctrl{ repo };
	UI ui{ ctrl };
	ui.run();

	return 0;
}