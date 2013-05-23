#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
   // Check arguments
   if(argc != 2) {
      cout << "usage: ./cludy [filename]" << endl;
      return -1;
   }

   // Check if file is open
   fstream file(argv[1]);
   if(!file.good() || !file.is_open()) {
      cout << "unable to open file" << endl;
      return -1;
   }

   // Read input file line by line into out stream
   ostringstream out;
   vector<string> includes;
   while(true) {
      // Read line
      string buffer;
      getline(file, buffer);
      if(!file.good())
         break;

      // If it is an include line remember it
      if(buffer.find("#include") == 0) {
         includes.push_back(buffer);
      } else {
         // Flush at first non-include line
         if(!includes.empty()) {
            sort(includes.begin(), includes.end(), [](string lhs, string rhs) {
               transform(lhs.begin(), lhs.end(), lhs.begin(), [](int c) {return tolower(c);});
               transform(rhs.begin(), rhs.end(), rhs.begin(), [](int c) {return tolower(c);});
               return lhs < rhs;
            });
            for(auto& iter : includes)
               out << iter << endl;
            includes.clear();
         }

         // Output normal line
         out << buffer << endl;
      }
   }

   // Flush remaining includes
   sort(includes.begin(), includes.end());
   for(auto& iter : includes)
      file << iter << endl;

   // Write buffered stream back to file
   file.clear();
   file.seekg(0, ios::beg);
   file.write(out.str().c_str(), out.str().size());
}