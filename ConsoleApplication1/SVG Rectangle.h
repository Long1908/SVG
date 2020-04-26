#pragma once
#include <fstream>
using std::cout;
using std::cin;
using std::endl;

class SVGrectangle
{
private:
	double xAxis;
	double yAxis;
	double height;
	double width;
	char* colour;

	void enterAttributes(double xAxis, double yAxis, double height, double width, const char* colour)
	{
		this->xAxis = xAxis;
		this->yAxis = yAxis;
		this->height = height;
		this->width = width;

		this->colour = new char[strlen(colour) + 1];
		strcpy(this->colour, colour);
	}
public:
	SVGrectangle()
	{
		enterAttributes(0, 0, 0, 0, "");
	}

	SVGrectangle(double xAxis, double yAxis, double height, double width, const char* colour)
	{
		enterAttributes(xAxis, yAxis, height, width, colour);
	}

	~SVGrectangle()
	{
		delete[] colour;
	}

	void enterFigureRectangle()
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
				copyFile << "  <rect x=\"" << this->xAxis << "\" y=\"" << this->yAxis << "\" height=\"" << this->height << "\" width=\"" << this->width << "\" fill=\"" << this->colour << "\" />" << endl;
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
		cout << "Successfully created a Rectangle!" << endl;
	}

	void withinTheFigure(double x, double y, double h, double w)
	{
		//double xAxis;
		//double yAxis;
		//double height;
		//double width;
		//double radius;

		//double parameter[4];
		//bool hasThatFigure = false;

		//char a[100];
		//int k;
		//int j;
		//int q = 0;
		//char* p;

		//std::ifstream index;
		//index.open("FiguresFileLineNumbers.txt");
		//if (!index)
		//{
		//	cout << "ERROR!! Exiting the printing  process..." << endl;
		//	return;
		//}
		//index >> k;
		//index.close();

		//std::ifstream printFile;
		//printFile.open("Figures.txt");
		//if (!printFile)
		//{
		//	cout << "ERROR!! Exiting the printing  process..." << endl;
		//	return;
		//}

		//for (int i = 0; i < k - 1; ++i)
		//{
		//	j = 1;
		//	q = 0;
		//	printFile.getline(a, 100, '\n');
		//	if (i >= 1)
		//	{
		//		if (a[3] == 'r')
		//		{
		//			hasThatFigure = true;
		//			p = strtok(a, "=\"");
		//			while (p != NULL)
		//			{
		//				if ((j % 2 == 0) && (q <= 4))
		//				{
		//					parameter[q] = atoi(p);
		//					++q;
		//				}
		//				p = strtok(NULL, "=\"");
		//				++j;
		//			}
		//			xAxis = abs(parameter[0]);
		//			yAxis = abs(parameter[1]);
		//			height = abs(parameter[2]);
		//			width = abs(parameter[3]);

		//			x = abs(x);
		//			y = abs(y);
		//			h = abs(h);
		//			w = abs(w);

		//			if ((xAxis > x) && (yAxis > y))
		//			{
		//				cout << "There is no figure within you given figure." << endl;
		//			}
		//			else
		//			{
		//				if ((x >= xAxis + width) && (y >= yAxis + height))
		//				{
		//					cout << "rectangle " << " " << xAxis << " " << yAxis << " " << height << " " << width << endl;
		//				}
		//			}
		//		}
		//		else if (a[3] == 'c')
		//		{
		//			hasThatFigure = true;
		//			p = strtok(a, "=\"");
		//			while (p != NULL)
		//			{
		//				if ((j % 2 == 0) && (q < 4))
		//				{
		//					parameter[q] = atoi(p);
		//					++q;
		//				}
		//				p = strtok(NULL, "=\"");
		//				++j;
		//			}
		//			xAxis = abs(parameter[0]);
		//			yAxis = abs(parameter[1]);
		//			radius = abs(parameter[2]);

		//			x = abs(x);
		//			y = abs(y);
		//			h = abs(h);
		//			w = abs(w);

		//			if ((xAxis > x) && (yAxis > y))
		//			{
		//				cout << "There is no figure within you given figure." << endl;
		//			}
		//			else
		//			{
		//				if ((x >= xAxis + radius) && (y >= yAxis + radius))
		//				{
		//					cout << "circle " << " " << xAxis << " " << yAxis << " " << radius << endl;
		//				}
		//			}
		//		}
		//	}
		//}
	}
};
