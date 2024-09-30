#include <vector>
#include "pixel.h"
#include <iostream>
#include <string>
#include <fstream>

Pixel make_pixel(std::string& line){
  Pixel pixel;

  pixel.x = stoi(line.substr(0, line.find(',')));
  line = line.substr(line.find(',')+1, line.length()-line.find(','));

  pixel.y = stoi(line.substr(0, line.find(',')));
  line = line.substr(line.find(',')+1, line.length()-line.find(','));

  pixel.r = stof(line.substr(0, line.find(',')));
  line = line.substr(line.find(',')+1, line.length()-line.find(','));

  pixel.g = stof(line.substr(0, line.find(',')));
  line = line.substr(line.find(',')+1, line.length()-line.find(','));

  pixel.b = stof(line.substr(0, line.find(',')));

  return pixel;
}

void average_colors(std::vector<Pixel> &pixel_list){
  float r = 0;
  float g = 0;
  float b = 0;

  for (int i = 0; i < pixel_list.size(); i++){
    r += pixel_list[i].r;
    g += pixel_list[i].g;
    b += pixel_list[i].b;
  }
  r /= pixel_list.size();
  g /= pixel_list.size();
  b /= pixel_list.size();
  std::cout << "Average value r: " << r << " g: " << g << " b: " << b << std::endl;
};

int main(const int argc, const char * argv[]) {
  std::cout << argv[0] << std::endl;

  std::vector<Pixel> pixel_list; //Pixel list struct
  std::string filename = (argc > 1) ? argv[1] : "pixels.dat";
  std::ifstream file(filename); //File to read
  std::string line; //Line in the file


  if (file.is_open()) {
    while (getline(file, line)) {
      std::cout << line << std::endl; //Read line by line
      pixel_list.push_back(make_pixel(line)); //Parse the line to a pixel Object
    }
    file.close();
    average_colors(pixel_list);

  } else {
    std::cout << "Unable to open file" << std::endl;
  }
  return 0;
}