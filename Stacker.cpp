/**
 * @file Stacker.cpp
 * @author alfonsowolski
 * @date 2025-03-05
 * @brief Implementation of the Stacker class
 * 
 * Implementation of the stacker class
 */

#include "Stacker.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

using namespace std;

Stacker::Stacker(){
  pixels = vector<vector<Pixel>>();
  magic_number = "";
  width = 0;
  height = 0;
}  

Stacker::~Stacker(){
  pixels.clear();
}

void Stacker::ReadImage(string Path){

  ifstream file;
  file.open(Path, std::ios::in);

  string temp;

  file >> temp;

  if ( magic_number == "" ){
    magic_number = temp;
  }
  else if ( magic_number != temp){
    cout << "Error: Magic Number does not match for " << Path << endl;
    return;
  }

  file >> temp;

  // check if pixels needs to be wider
  if ( width < stoi(temp) ){
    cout << "Image was wider than Stacker" << endl << "| "<< Path << endl;
    
    for ( int i = width; i < stoi(temp); i++){ // expanding width
      pixels.push_back(vector<Pixel>()); // adding new collum
      for (int j = 0; j < height; j++){
	pixels[i].push_back(Pixel()); // adding element to collum
      }
    }
    width = stoi(temp); // set the new width
  }
  else if ( width > stoi(temp)){ // is the image smaller? (just for info)
    cout << "Stacker is wider than Image" << endl << "| " << Path << endl;
  }

  file >> temp;

  // check if pixels needs to be taller
  if ( height < stoi(temp) ){
    cout << "Image is taller than Stacker" << endl << "| " << Path << endl;
    for (int i = 0; i < width; i++){ // don't need to add new rows (just cycling)
      for (int j = height; j < stoi(temp); j++){
	pixels[i].push_back(Pixel()); // adding element to collum
      }
    }
    height = stoi(temp);
  }
  else if ( height > stoi(temp) ){
    cout << "Stacker is taller than Image" << endl << "| " << Path << endl;
  }

  // set max_color
  file >> temp;
  max_color = stoi(temp);
  
  for(int i = 0; i < width; i++){
    for(int j = 0; j < height; j++){

      Pixel p = Pixel();

      int r, g, b;
      
      file >> r >> g >> b;

      p = Pixel(r,g,b);
      
	if( pixels[i][j].getRed() == -1){ //assumes if red is initialized, green and blue are 
	pixels[i][j] = p;
      }
      else{
	pixels[i][j] = pixels[i][j].avgOf(p);
      }
      
    }
  }
  
  file.close();
}

void Stacker::printStack(string Path){
  ofstream file(Path);

  file << magic_number << endl;
  file << width << " " << height << endl;
  file << max_color << endl;

  // width on the inside because we go left-to-right not top-to-bottom
  for(int j = 0; j < height; j++){
    for(int i = 0; i < width; i++){
      file << setw(3) << pixels[i][j].getRed() << " "
	   << setw(3) << pixels[i][j].getGreen() << " "
	   << setw(3) << pixels[i][j].getBlue() << " ";
    }
  }

  file.close();
}
