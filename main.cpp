#include <SFML\Graphics.hpp>
#include <iostream>
#include <math.h>
#include <list>
#include <Windows.h>
#include "Vector.h"
#include "Point.h"

#define G 10

using namespace std;

int main() {
	float energyLose;
	float timeStepInSeconds;
	//float timeStepInMinutes;
	float x, y, z;
	unsigned int steps;
	list<float> listOfX;
	list<float> listOfY;
	list<float> listOfZ;

	cout << "Podaj wspolrzedne punktu startowego:" << endl;
	cin >> x >> y >> z;

	cout << "Podaj strate energii przy uderzeniu:" << endl;
	cin >> energyLose;

	Point *startPoint = new Point(x, y, z);

	cout << "Podaj wspolrzedne konca wektoru:" << endl;
	cin >> x >> y >> z;

	cout << "Podaj czas kroku w sekundach:" << endl;
	cin >> timeStepInSeconds;

	//timeStepInMinutes = (float)(timeStepInSeconds / 60.0);

	cout << "Podaj liczbe krokow:" << endl;
	cin >> steps;

	Vector *forceVector = new Vector(new Point(x, y, z));

	cout << "Pozycja 0 (" << startPoint->getX() << ", " << startPoint->getY() << ", " << startPoint->getZ() << ")" << endl;
	listOfX.push_back(startPoint->getX());
	listOfY.push_back(startPoint->getY());
	listOfZ.push_back(startPoint->getZ());
	unsigned int factor = 1;
	bool hit = false;
	for (unsigned int i = 1; i < steps; i++) {
		startPoint->setX(forceVector->getXLength() * i * timeStepInSeconds);
		startPoint->setY(forceVector->getYLength() * i * timeStepInSeconds);
		float zPosition;
		if (!hit) {
			zPosition = forceVector->getZLength() * factor * timeStepInSeconds - (G * pow(factor * timeStepInSeconds, 2) / 2);
			//zPosition += startPoint->getZ();
		}
		else
			zPosition = forceVector->getZLength() * factor * timeStepInSeconds - (G * pow(factor * timeStepInSeconds, 2) / 2);
		if (zPosition <= 0) {
			factor = 1;
			hit = true;
			forceVector->setZLength(forceVector->getZLength() * (1 - energyLose));
			zPosition = forceVector->getZLength() * factor * timeStepInSeconds - (G * pow(factor * timeStepInSeconds, 2) / 2);
		}
		startPoint->setZ(zPosition);
		//cout << "Pozycja " << i << " (" << startPoint->getX() << ", " << startPoint->getY() << ", " << startPoint->getZ() << ")" << endl;
		factor++;
		listOfX.push_back(startPoint->getX());
		listOfY.push_back(startPoint->getY());
		listOfZ.push_back(startPoint->getZ());
	}

	delete startPoint;
	delete forceVector;

	sf::RenderWindow window(sf::VideoMode(1300, 400), "Symulator");
	sf::RenderWindow window1(sf::VideoMode(1300, 400), "Symulator");
	sf::RectangleShape horizontal[38];

	sf::RectangleShape vertical[129];

	for (int i = 0; i < 38; i++) {
		horizontal[i] = sf::RectangleShape(sf::Vector2f(1300, 1));
		horizontal[i].setFillColor(sf::Color(255,255,255,30));
		horizontal[i].setPosition(0, 10 * (i + 1));
	}

	for (int i = 0; i < 129; i++) {
		vertical[i] = sf::RectangleShape(sf::Vector2f(1, 400));
		vertical[i].setFillColor(sf::Color(255, 255, 255, 30));
		vertical[i].setPosition(10 * (i + 2),0);
	}

	sf::CircleShape shape(4.f);
	sf::RectangleShape xLine(sf::Vector2f(1300, 2));
	xLine.setPosition(0, 390);
	sf::RectangleShape yLine(sf::Vector2f(2, 400));
	yLine.setPosition(10, 0);
	xLine.setFillColor(sf::Color::Red);
	yLine.setFillColor(sf::Color::Red);
	shape.setPosition(0, 388);
	shape.setFillColor(sf::Color::Green);

	list<float>::iterator itX = listOfX.begin();
	list<float>::iterator itY = listOfY.begin();
	list<float>::iterator itZ = listOfZ.begin();

	sf::CircleShape *plot = new sf::CircleShape [steps];
	for (int i = 0; i < steps; i++) {
		plot[i] = sf::CircleShape(1.f);
		plot[i].setPosition(12 + *itX * 10, 392 - *itZ*10);
		plot[i].setFillColor(sf::Color::Green);
		itX++;
		itY++;
		itZ++;
	}
	itX = listOfX.begin();
	itY = listOfY.begin();
	itZ = listOfZ.begin();

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		if (itX == listOfX.end()) {
			itX = listOfX.begin();
			itY = listOfY.begin();
			itZ = listOfZ.begin();
		}
		shape.setPosition(12 + *itX * 10, 382 - *itZ * 10);
		window.draw(xLine);
		window.draw(shape);
		window.draw(yLine);
		for (int i = 0; i < 38; i++)
			window.draw(horizontal[i]);
			for (int i = 0; i < 129; i++)
				window.draw(vertical[i]);
			window.display();

			itX++;
			itY++;
			itZ++;

			Sleep(10);
		

		
		window1.clear();
		for (unsigned int i = 0; i < steps; i++) {
			window1.draw(plot[i]);
		}
		window1.draw(xLine);
		window1.draw(yLine);
		for (int i = 0; i < 38; i++)
			window1.draw(horizontal[i]);
		for (int i = 0; i < 129; i++)
			window1.draw(vertical[i]);
		window1.display();
		Sleep(10);
	}

	//delete[] plot;
	
	return 0;
}
