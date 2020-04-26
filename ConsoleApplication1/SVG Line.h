#pragma once
#include <fstream>
using std::cout;
using std::cin;
using std::endl;

class SVGline
{
private:
	double xAxis;
	double yAxis;
	double lenght;
	char* colour;

	void enterAttributes(double xAxis, double yAxis, double lenght, const char* colour)
	{
		this->xAxis = xAxis;
		this->yAxis = yAxis;
		this->lenght = lenght;

		this->colour = new char[strlen(colour) + 1];
		strcpy(this->colour, colour);
	}
public:
	SVGline()
	{
		enterAttributes(0, 0, 0, "");
	}

	SVGline(double xAxis, double yAxis, double lenght, const char* colour)
	{
		enterAttributes(xAxis, yAxis, lenght, colour);
	}

	~SVGline()
	{
		delete[] colour;
	}

	void enterFigureLine()
	{
		char a[100];
		char b[100];

		std::ifstream index;
		index.open("FiguresFileLineNumbers.txt");
		if (!index)
		{
			cout << "ERROR!! Exiting the creation process..." << endl;
			return;
		}
		int k;
		index >> k;
		index.close();

		std::ifstream printFiguresFromFile;
		std::ofstream copyFile;
		printFiguresFromFile.open("Figures.txt");
		copyFile.open("CopyFile.txt");

		if (!printFiguresFromFile)
		{
			cout << "ERROR!! Exiting the creation process..." << endl;
			return;
		}
		if (!copyFile)
		{
			cout << "ERROR!! Exiting the creation process..." << endl;
			return;
		}

		for (int i = 0; i < k; ++i)
		{
			if (i != (k - 1))
			{
				printFiguresFromFile.getline(a, 1000, '\n');
				copyFile << a << endl;
			}
			else
			{
				copyFile << "  <line lx=\"" << this->xAxis <<"\" ly=\"" << this->yAxis << "\" lenght=\""<< this->lenght <<"\" fill=\""<< this->colour <<"\" />" << endl;
			}
		}
		copyFile << "</svg>";

		printFiguresFromFile.close();
		copyFile.close();

		std::ofstream printFiguresFromFile1;
		std::ifstream copyFile1;
		printFiguresFromFile1.open("Figures.txt");
		copyFile1.open("CopyFile.txt");

		if (!printFiguresFromFile1)
		{
			cout << "ERROR!! Exiting the creation process..." << endl;
			return;
		}
		if (!copyFile1)
		{
			cout << "ERROR!! Exiting the creation process..." << endl;
			return;
		}

		for (int i = 0; i < k + 1; ++i)
		{
			copyFile1.getline(b, 1000, '\n');
			printFiguresFromFile1 << b << endl;
		}

		printFiguresFromFile1.close();
		copyFile1.close();

		std::ofstream index1;
		index1.open("FiguresFileLineNumbers.txt");
		index1 << k + 1;
		cout << "Successfully created a Line!" << endl;
	}
};
