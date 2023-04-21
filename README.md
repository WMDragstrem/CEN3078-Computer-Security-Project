# CEN3078-Computer-Security-Project
A simple text-based program developed for my Programming 2 final under Professor Allen. \
The scope is rather limited due to Hurricane Ian hitting prior to its assignment.
\
The main file is ShapesProject.cpp, the rest are all its header files. 
\
## TERMS OF USE
\
This application is intended for educational purposes only. This project is a work-in-progress and as such is not guaranteed to function perfectly. By downloading any files within this repository, you assume full responsibility for any damages to your device or network that may incur from running this application. We are not responsible for improper and irresponsible usage of these files. Input only what is requested by the program.



## Ver 1.1.0
*Two new features added for this update to the ShapesProject.cpp file* \
\
1.) Program now checks to ensure input for coordinates and dimensions is an integer, and outputs an error message if it is not. \
Previously, inputting a non-integer caused the program to go into an infinite output loop. \
\
2.) Program now limits the total number of saved shapes to 256 so as to preserve memory. \
Should you wish to modify the cap, only the const MAX_SHAPES needs modified at the top of the program.
