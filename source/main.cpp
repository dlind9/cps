#include "../headers/triangle.h"
#include <iostream>
#include <string>
using std::string;
#include <fstream>
using std::ofstream;

int main() {
    string output="";
    auto triangle = Triangle(100);
    ofstream f("../ps-example/test-triangle.ps");
    output = triangle.postscript(std::make_pair(0.0,0.0), output);
    if(f.is_open()) {
        f<<output<<std::endl;
                
        f.close();
    }
    return 1;
            
}
