# CEN3078-Computer-Security-Project
A simple text-based program developed for my Programming 2 final under Professor Allen. \
The scope is rather limited due to Hurricane Ian hitting prior to its assignment.  
\
The main file is ShapesProject.cpp, the rest are all its header files. 

# Ver 1.1.0
Two new features added for this update to the ShapesProject.cpp file 
\
1.) Program now checks to ensure input for coordinates and dimensions is an integer, and outputs an error message if it is not. \
Previously, inputting a non-integer caused the program to go into an infinite output loop.
\
2.) Program now limits the total number of saved shapes to 256 so as to preserve memory. \
Should you wish to modify the cap, only the const MAX_SHAPES needs modified at the top of the program.
