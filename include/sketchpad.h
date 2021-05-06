#pragma once

#include "cinder/gl/gl.h"
#include "game_board.h"

using std::vector;
namespace checkers {

namespace visualizer {

/**
 * A sketchpad which will be displayed in the Cinder application and respond to
 * mouse events. Furthermore, the sketchpad can output its current state in the
 * same format as the Naive Bayes image data files.
 */
class Sketchpad {
public:
  /**
   * Creates a sketchpad.
   * (Note that sketchpad pixels are larger than screen pixels.)
   *
   * @param top_left_corner     the screen coordinates of the top left corner of
   *                            the sketchpad
   * @param num_pixels_per_side the number of sketchpad pixels in one row/column
   *                            of the sketchpad
   * @param sketchpad_size      the side length of the sketchpad, measured in
   *                            screen pixels
   */
  Sketchpad(const glm::vec2 &top_left_corner, size_t num_pixels_per_side,
            double sketchpad_size);

  /**
   * Displays the current state of the game board in the Cinder application.
   */
  void Draw(GameBoard &game_board) const;

private:
  glm::vec2 top_left_corner_;

  size_t num_pixels_per_side_;

  /** Number of screen pixels in the width/height of one sketchpad pixel */
  double pixel_side_length_;
};

} // namespace visualizer

} // namespace checkers
