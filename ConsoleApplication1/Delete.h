#pragma once
void deleteFigure(int n)
{
	char a[100];
	char b[100];;

	bool isRectangle = false;
	bool isCircle = false;
	bool isLine = false;

	std::ifstream index;
	index.open("FiguresFileLineNumbers.txt");
	if (!index)
	{
		cout << "ERROR!! Exiting the erasing process..." << endl;
		return;
	}
	int k;
	index >> k;
	index.close();

	if ((n < 1) || (n > k - 2))
	{
		cout << "There is no such number of Figure to delete! Exiting the erasing process!" << endl;
		return;
	}

	std::ifstream printFiguresFromFile;
	std::ofstream copyFile;
	printFiguresFromFile.open("Figures.txt");
	copyFile.open("CopyFile.txt");

	if (!printFiguresFromFile)
	{
		cout << "ERROR!! Exiting the erasing process..." << endl;
		return;
	}
	if (!copyFile)
	{
		cout << "ERROR!! Exiting the erasing process..." << endl;
		return;
	}

	for (int i = 0; i < k; ++i)
	{
		printFiguresFromFile.getline(a, 1000, '\n');
		if (i != n)
		{
			copyFile << a << endl;
		}
		else 
		{
			if (a[3] == 'r')
			{
				isRectangle = true;
			}
			else if (a[3] == 'c')
			{
				isCircle = true;
			}
			else if (a[3] == 'l')
			{
				isLine = true;
			}
		}
	}

	printFiguresFromFile.close();
	copyFile.close();

	std::ofstream printFiguresFromFile1;
	std::ifstream copyFile1;
	printFiguresFromFile1.open("Figures.txt");
	copyFile1.open("CopyFile.txt");

	if (!printFiguresFromFile1)
	{
		cout << "ERROR!! Exiting the erasing process..." << endl;
		return;
	}
	if (!copyFile1)
	{
		cout << "ERROR!! Exiting the erasing process..." << endl;
		return;
	}

	for (int i = 0; i < k ; ++i)
	{
		copyFile1.getline(b, 1000, '\n');
		printFiguresFromFile1 << b << endl;
	}

	printFiguresFromFile1.close();
	copyFile1.close();

	std::ofstream index1;
	index1.open("FiguresFileLineNumbers.txt");
	index1 << k - 1;
	index1.close();

	if (isRectangle)
	{
		cout << "Successfully erased a Rectangle" << endl;
	}
	else if (isCircle)
	{
		cout << "Successfully erased a Circle" << endl;
	}
	else if (isLine)
	{
		cout << "Successfully erased a Line" << endl;
	}
}