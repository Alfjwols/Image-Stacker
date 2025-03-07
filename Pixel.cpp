/**
 * @file Pixel.cpp
 * @author alfonsowolski
 * @date 2025-03-05
 * @brief Implementation of Pixel class
 * 
 * Implementation of the Pixel Class.
 */

#include "Pixel.h"

Pixel::Pixel() {
  red = -1;
  green = -1;
  blue = -1;
}

Pixel::Pixel(int r, int g, int b) {
  red = r;
  green = g;
  blue = b;
}

Pixel::~Pixel() {
  // No dynamic memory to free
}

int Pixel::getRed() {
  return red;
}

int Pixel::getGreen() {
  return green;
}

int Pixel::getBlue() {
  return blue;
}

Pixel Pixel::avgOf(Pixel pix) {
  int r, g, b;
  r = (red + pix.getRed()) / 2;
  g = (green + pix.getGreen()) / 2;
  b = (blue + pix.getBlue()) / 2;
  Pixel p(r, g, b);
  return p;
}
