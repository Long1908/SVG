// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SVG Rectangle.h"
#include "SVG Circle.h"
#include "SVG Line.h"
#include "Delete.h"
#include "Print.h"
#include "Translate.h"

int main()
{
	bool exit = false;

	char command[50];
	char figure[10];
	int lineToErase;

	double xAxis;
	double yAxis;
	double lenght;
	double radius;
	double height;
	double width;
	char colour[20];

	cout << "Welcome to out SVG program. Please enter the following commands to work with our Program:" << endl;

	do
	{
		cout << "/print/create/erase <n>/translate[<n>]/within/exit/" << endl;
		cin.getline(command, 50, '\n');
		if (!strcmp(command, "print"))
		{
			printFigures();
		}
		else if (!strcmp(command, "create"))
		{
			cout << "Which of the following figures do you want to create: \n/line/circle/rectangle/" << endl;
			do
			{
				cin.getline(figure, 10, ' ');
				if (!strcmp(figure, "line"))
				{
					cin >> xAxis >> yAxis >> lenght >> colour;
					SVGline figure = SVGline(xAxis, yAxis, lenght, colour);
					figure.enterFigureLine();
				}
				else if (!strcmp(figure, "circle"))
				{
					cin >> xAxis >> yAxis >> radius>> colour;
					SVGcircle figure = SVGcircle(xAxis, yAxis, radius, colour);
					figure.enterFigureCircle();
				}
				else if (!strcmp(figure, "rectangle"))
				{
					cin >> xAxis >> yAxis >> height >> width >> colour;
					SVGrectangle figure = SVGrectangle(xAxis, yAxis, height, width, colour);
					figure.enterFigureRectangle();
				}
				else
				{
					cout << "Invalid figure! Please try again with the following figures. \n/line/circle/rectangle/" << endl;
				}
			} while ((strcmp(figure, "line"))
				&& (strcmp(figure, "circle")) 
				&& (strcmp(figure, "rectangle")));
		}
		else if (!strcmp(command, "erase"))
		{
			cin >> lineToErase;
			deleteFigure(lineToErase);
		}
		else if (!strcmp(command, "translate"))
		{

		}
		else if (!strcmp(command, "within"))//there are errors, so the code is made like a comment
		{
			cin.getline(figure, 10, '\n');
			if (!strcmp(figure, "line"))
			{
				cout << "We are sorry but we cannot check if a figure is within a line." << endl;
				//cin >> xAxis >> yAxis >> lenght ;
				//SVGline figure = SVGline(xAxis, yAxis, lenght, "");
				//figure.withinTheFigure(xAxis, yAxis, lenght);
			}
			else if (!strcmp(figure, "circle"))
			{
				cin >> xAxis >> yAxis >> radius >> colour;
				SVGcircle figure = SVGcircle(xAxis, yAxis, radius, "");
				figure.withinTheFigure(xAxis, yAxis, radius);
			}
			else if (!strcmp(figure, "rectangle"))
			{
				cin >> xAxis >> yAxis >> height >> width >> colour;
				SVGrectangle figure = SVGrectangle(xAxis, yAxis, height, width, "");
				figure.withinTheFigure(xAxis, yAxis, height, width);
			}
			else
			{
				cout << "Invalid figure! Please try again with the following figures. \n/line/circle/rectangle/" << endl;
			}
		}
		else if (!strcmp(command, "exit"))
		{
			cout << "\nExiting program. Have a nice day!" << endl;
			exit = true;
		}
	} while (!exit);

	return 0;
}
