cludy
=====

a tool for sorting includes in c++ projects.
feel free to complain if you find any issues.

Usage
-----

Sort includes in My.cpp by alphabet inplace.
./cludy My.cpp

Sort includes of all files in src directory.
find src/ -name "*pp" -exec ./cludy {} \;
