#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <memory>

using namespace std;


std::vector<float> splitLineAndConvertToFloat(const std::string& line)
{
  std::stringstream ss(line);
  std::string word;
  std::vector<float> float_vector;

  while(getline(ss, word, ' '))
  {
    float_vector.push_back(std::stof(word));
  }

  return float_vector;
}

int  main()
{

string line;

// Read from the text file
ifstream texture_file("texture.txt");

getline(texture_file, line);
auto texture_number = std::stoi(line);
std::vector<float> vertices;
std::vector<float> normals;
std::vector<float> text_coords;

while (getline (texture_file, line)) {
  
  auto float_vector = splitLineAndConvertToFloat(line);

  vertices.insert(vertices.end(), float_vector.begin(), float_vector.begin() + 3);
  normals.insert(normals.end(), float_vector.begin() + 3, float_vector.begin() + 6);
  text_coords.insert(text_coords.end(), float_vector.begin() + 6, float_vector.end());
  
}

std::cout << vertices.size() << " " << normals.size() << " " << text_coords.size() << std::endl;

texture_file.close(); 

return 0;
}
