#pragma once

#include <utility>
#include <stdexcept>
#include <cmath>

namespace queen_attack {

    class chess_board {
    public:
        // Constructor that takes positions for white and black queens
        chess_board(std::pair<int, int> white_position, std::pair<int, int> black_position);

        // Returns the position of the white queen
        std::pair<int, int> white() const;

        // Returns the position of the black queen
        std::pair<int, int> black() const;

        // Determines if the queens can attack each other
        bool can_attack() const;

    private:
        std::pair<int, int> white_position_;
        std::pair<int, int> black_position_;

        // Helper method to validate queen positions
        void validate_position(const std::pair<int, int>& position) const;
    };

}