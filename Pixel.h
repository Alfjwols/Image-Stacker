/**
 * @file Pixel.h
 * @author alfonsowolski
 * @date 2025-03-05
 * @brief Definition of the Pixel class
 * 
 * The definition of the Pixel class
 */
#ifndef PIXEL_H
#define PIXEL_H

class Pixel{
 public:

  /**
   * default Constructor for Pixel
   *
   * @post red, green, blue = -1
   * 
   */
  Pixel();


  /**
   * Constuctor for pixel
   *
   * @param int r the desired red value of pixel
   * @param int g the desired green value of pixel
   * @param int b the desired blue value for pixel
   * @pre r, g, b are numbers 1-255 or -1
   * @post red = r,  green = g,  blue = b
   * 
   */
  Pixel(int r, int g, int b);


  /**
   * destructor for Pixel
   * 
   */
  ~Pixel();


  /**
   * return the red value of Pixel
   *
   * @pre red is initialized
   * @return int the value of red 1-255
   * 
   */
  int getRed();


  /**
   * return the blue value of the Pixel
   *
   * @pre green is initialized
   * @return int the value of green 1-255
   * 
   */
  int getGreen();

  /**
   * return the blue value of the pixel
   *
   * @pre blue it initialized
   * @return int the value of blue 1-255
   * 
   */
  int getBlue();

  /**
   * returns a pixel with the average color between this pixel and another
   *
   * @param Pixel pix other pixel 
   * @pre red, green, blue are initialized.  pix's red green and blue are initialized
   * @return Pixel the new pixel that is the average color of this and pix
   * 
   */
  Pixel avgOf(Pixel pix);

 private:
  int red;

  int green;

  int blue;
};

#endif
