#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main(int argc, char *argv[]) {
    std::vector<std::string> arguments(argv, argv + argc);
    for (int i = 1; i < arguments.size(); i++) {
        std::string file_name = arguments[i];
        std::ifstream infile;
        std::ofstream outfile;
        infile.open(file_name, std::ios::binary);
        if(file_name.substr(file_name.size() - 3) != ".uc") {
            std::cerr << "The file " << file_name << "is not a .uc file!" << std::endl;
            return 1;
        }
        if(!infile.is_open()) {
            std::cerr << "Error opening input file which name is " << file_name << std::endl;
            return 1;
        }
        std::string output_file_name = file_name.substr(0,file_name.size() - 2) + "mp3";
        outfile.open(output_file_name, std::ios::binary);
        char byte;
        while(infile.get(byte)) {
            byte ^= 0xa3;
            outfile << byte;
        }
        infile.close();
        outfile.close();
        std::cout << file_name << "already transfered to " << output_file_name << std::endl;
    }
    return 0;
}