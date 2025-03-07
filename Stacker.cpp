/**
 * @file Stacker.cpp
 * @author alfonsowolski
 * @date 2025-03-05
 * @brief Implementation of the Stacker class
 * 
 * Implementation of the stacker class
 */

#include "Stacker.h"
#include "Vector"
#include <fstream>

using namespace std;

Stacker::Stacker(){
  pixels = vector<vector<Pixel>>();
  magicNumber = "";
  width = 0;
  height = 0;
}  

Stacker::~Stacker(){
  delete pixels;
}

void Stacker::ReadImage(string Path){

  ifstream file;
  file.open(Path, in);

  string temp;

  file >> temp;

  if ( magic_number == "" ){
    magic_number = temp;
  }
  else if ( magic_number != temp){
    cout << "Error: Magic Number does not match for " << Path << endl;
    continue;
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
  
  if ( height < stoi(temp) ){
    cout << "Image is taller than Stacker" << endl << "| " << Path << endl;
    for (int i = 0; i < width; i++){
      for (int j = height; j < stoi(temp); j++){
	pixels[i].pushback(Pixel());
      }
    }
    height = stoi(temp);
  }
  else if ( height > stoi(temp) ){
    cout << "Stacker is taller than Image" << endl << "| " << Path << endl;
  }

  for(int i = 0; i < width; i++){
    for(int j = 0; j < height; j++){

      Pixel p = Pixel();

      file >> temp;
      p.red = temp;
      
      file >> temp;
      p.green = temp;

      file >> temp;
      p.blue = temp;

      if( pixels[i][j].red == -1){ //assumes if red is initialized, green and blue are too
	pixels[i][j] = p;
      }
      else{
	pixels[i][j] = pixels.avgOf(p);
      }
      
    }
  }
  
  file.close();
}

void printStack(){
  
}
