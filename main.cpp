#include <iostream>
#include <string>
#include "Stacker.h"

using namespace std;

int main() {
  string baseName;
  int numImages;

  // Prompt the user for the base image name and the number of images to stack
  cout << "Please enter the image you wish to stack: ";
  cin >> baseName;
  cout << "Please enter the number of images: ";
  cin >> numImages;

  // Create a Stacker object
  Stacker stacker;

  cout << "\nStacking images:" << endl;

  // Loop through each image using formatted numbering (e.g., 001, 002, etc.)
  for (int i = 1; i <= numImages; i++) {
    // Convert the image number to a three-digit string without using <cstdio>
    string numStr = to_string(i);
    while (numStr.length() < 3) {
      numStr = "0" + numStr;
    }
    // Construct the file path following the convention: baseName/baseName_XXX.ppm
    string filePath = baseName + "/" + baseName + "_" + numStr + ".ppm";

    cout << "\t" << filePath << endl;
    stacker.ReadImage(filePath);
  }

  cout << "\nStacking succeeded." << endl;

  // Write the final stacked image to an output file named baseName.ppm
  string outputFile = baseName + ".ppm";
  stacker.printStack(outputFile);
  cout << "Output written to: " << outputFile << endl;

  return 0;
}
