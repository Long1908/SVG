# SVG
SVG is project for making Vector Graphics for the basic geometrical figures - Line, CIrcle and Rectangle.  
It's a C++ project that creates a txt file, which can then be opened like an html file and show the figures that we have created.  
We have a Main.cpp where we input:  
      -what figure are we entering  
      -based on he figure we input:  
           ~lenght  
           ~hight(if it's a rectangle)  
           ~radius(if it's a circle)  
           ~colour of the figure's outline  
      -we can print the figures data if we want  
      -erase a figure if want  
      -see if a figure is within another figure 
      -and of course exit the programm if we want  
Then we have the different header files where they work as our cpp files as well, where it checks if the figure that we have inputed is valid or not.  
All the figures data are saved in txt file called Figures.txt and if other changes are need to be done such as add or erase, the changes will be done, save in   
CopyFile.txt and then the changes will be then pasted in the Figures.txt.  
FigureFileLineNumbers.txt is a file that just show us how many rows are there in our txt files.
