cludy
=====

a tool for sorting includes in c++ projects.

Compile
-------

use make

Run
---

Sort includes in My.cpp by alphabet inplace.
./cludy My.cpp

Sort includes of all files in src directory.
find src/ -name "*pp" -exec ./cludy {} \;
