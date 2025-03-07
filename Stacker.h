/**
 * @file Stacker.h
 * @author alfonsowolski
 * @date 2025-03-05
 * @brief Definition of Stacker class
 * 
 * Definition of Stacker class
 */

#include <vector>
#include <string>
#include "Pixel.h"

#ifndef STACKER_H
#define STACKER_H

class Stacker{
 public:
  

/**
 * Constructor for Stacker 
 * 
 * @post height = 100, width = 100, pixels and contents are initialized
 * 
 */
  Stacker();

/**
 * Deconstructor for Stacker
 *
 * @pre pixels is initialized
 * @post pixels is deallocated
 * 
 */
  ~Stacker();
  
/**
 * Reads a .ppm file and goes one by one through each pixel, replacing the existing pixels in "pixels" with an average of the new and old pixel. if there is no existing pixel in the spot, it will simply overwrite
 *
 * @param string Path the path to the desired image
 * @pre Path is set to an existing .ppm file, pixels vector has been initialized, each Pixel object in pixels has been initialized
 * @return void 
 * @post pixels has been changed to contain an average of the old and new images
 * 
 */
  void ReadImage(std::string Path);


/**
 * Creates a .ppm file that represents the current image stack
 *
 * @param string Path the path & filename to save image to (will append .ppm if not present)
 * @pre pixels is initialized. all Pixel objects in pixels are initialized
 * @return void 
 * @post a .ppm file is created in this directory
 * 
 */
  void printStack(std::string Path);
    
 private:
  std::string magic_number;
  int width;
  int height;
  int max_color;
  int timesStacked;
  std::vector<std::vector<Pixel>> pixels;
};

#endif
