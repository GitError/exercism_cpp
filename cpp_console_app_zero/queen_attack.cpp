#include "queen_attack.h"

namespace queen_attack {

    chess_board::chess_board(std::pair<int, int> white_position, std::pair<int, int> black_position)
        : white_position_(white_position), black_position_(black_position) {

        // Validate both queen positions
        validate_position(white_position_);
        validate_position(black_position_);

        // Check that queens are not on the same position
        if (white_position_ == black_position_) {
            throw std::domain_error("Queens cannot occupy the same position");
        }
    }

    std::pair<int, int> chess_board::white() const {
        return white_position_;
    }

    std::pair<int, int> chess_board::black() const {
        return black_position_;
    }

    bool chess_board::can_attack() const {
        // Same row
        if (white_position_.first == black_position_.first) {
            return true;
        }

        // Same column
        if (white_position_.second == black_position_.second) {
            return true;
        }

        // On a diagonal - check if the absolute difference in rows equals 
        // the absolute difference in columns
        int row_diff = std::abs(white_position_.first - black_position_.first);
        int col_diff = std::abs(white_position_.second - black_position_.second);

        return row_diff == col_diff;
    }

    void chess_board::validate_position(const std::pair<int, int>& position) const {
        // Check row bounds (valid rows are 0-7)
        if (position.first < 0 || position.first > 7) {
            throw std::domain_error("Queen's row must be between 0 and 7");
        }

        // Check column bounds (valid columns are 0-7)
        if (position.second < 0 || position.second > 7) {
            throw std::domain_error("Queen's column must be between 0 and 7");
        }
    }
}