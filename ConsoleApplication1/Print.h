#pragma once
#include <cstdlib>
void printFigures()
{
	char a[100];
	int k;
	int j;
	char* p;

	std::ifstream index;
	index.open("FiguresFileLineNumbers.txt");
	if (!index)
	{
		cout << "ERROR!! Exiting the printing  process..." << endl;
		return;
	}
	index >> k;
	index.close();

	std::ifstream printFile;
	printFile.open("Figures.txt");
	if (!printFile)
	{
		cout << "ERROR!! Exiting the printing  process..." << endl;
		return;
	}

	for (int i = 0; i < k - 1; ++i)
	{
		j = 1;
		printFile.getline(a, 100, '\n');
		if (i >= 1)
		{
			cout << i << ". ";
			p = strtok(a, "=\"");
			while (p != NULL)
			{
				if (j % 2 == 0)
				{
					cout << p << " ";
				}
				else
				{
					if (j == 1)
					{
						if (a[3] == 'r')
						{
							cout << "rectangle ";
						}
						else if (a[3] == 'c')
						{
							cout << "circle ";
						}
						else if (a[3] == 'l')
						{
							cout << "line ";
						}
					}
				}
				p = strtok(NULL, "=\"");
				++j;
			}
			cout << endl;
		}
	}
}