#include <iostream>
#include <sketchpad.h>
namespace checkers {

namespace visualizer {

using glm::vec2;
using std::vector;

Sketchpad::Sketchpad(const vec2 &top_left_corner, size_t num_pixels_per_side,
                     double sketchpad_size,
                     double brush_radius)

    : top_left_corner_(top_left_corner),
      num_pixels_per_side_(num_pixels_per_side),
      pixel_side_length_(sketchpad_size / num_pixels_per_side)
   {
  pixels_ = vector<vector<char>>(num_pixels_per_side_,
                                 vector<char>(num_pixels_per_side_, 0));
}

void Sketchpad::Draw(GameBoard& game_board) const {
  for (size_t row = 0; row < num_pixels_per_side_; ++row) {
    for (size_t col = 0; col < num_pixels_per_side_; ++col) {
      // Set Colors for squares
      if (game_board.GetGameBoard()[row][col].GetSquareColor() == "black") {
        ci::gl::color(ci::Color("black"));
      } else {
        ci::gl::color(ci::Color("white"));
      }

      // Determine coordinates
      vec2 pixel_top_left = top_left_corner_ + vec2(col * pixel_side_length_,
                                                    row * pixel_side_length_);
      vec2 pixel_bottom_right =
          pixel_top_left + vec2(pixel_side_length_, pixel_side_length_);

      // Set range of square
      vec2 x_lim = {pixel_top_left.x, pixel_bottom_right.x};
      vec2 y_lim = {pixel_bottom_right.y, pixel_top_left.y};
      game_board.GetGameBoard()[row][col].SetSquareLimits(x_lim, y_lim);
      
      // Draw Squares
      ci::Rectf pixel_bounding_box(pixel_top_left, pixel_bottom_right);
      ci::gl::drawSolidRect(pixel_bounding_box);

      // Draw GamePieces
      ci::gl::color(ci::Color("black"));
      ci::gl::drawStrokedRect(pixel_bounding_box);
      if (game_board.GetGameBoard()[row][col].GetContainsGamePiece()) {
        vec2 midpoint = (pixel_top_left + pixel_bottom_right);
        midpoint.x /= 2;
        midpoint.y /= 2;
        if (game_board.GetGameBoard()[row][col].GetPieceIsRedColor()) {
          ci::gl::color(255, 0, 0);
          ci::gl::drawSolidCircle(midpoint, 20.0f);

        } else {
          ci::gl::color(125, 125, 125);
          ci::gl::drawSolidCircle(midpoint, 20.0f);
        }
      }
    }
  }
}

void Sketchpad::Clear() {
  pixels_.clear();
  pixels_ = vector<vector<char>>(num_pixels_per_side_,
                                 vector<char>(num_pixels_per_side_, 0));
}

const vector<vector<char>> &Sketchpad::GetPixels() const { return pixels_; }

} // namespace visualizer

} // namespace checkers
