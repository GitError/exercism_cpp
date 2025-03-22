#include "beer_song.h"
#include <sstream>

namespace beer_song {
	std::string verse(int bottle_count) {
		std::stringstream verse_stream;
		if (bottle_count == 0) {
			verse_stream << "No more bottles of beer on the wall, no more bottles of beer.\n"
				<< "Go to the store and buy some more, 99 bottles of beer on the wall.\n";
		}
		else if (bottle_count == 1) {
			verse_stream << "1 bottle of beer on the wall, 1 bottle of beer.\n"
				<< "Take it down and pass it around, no more bottles of beer on the wall.\n";
		}
		else if (bottle_count == 2) {
			verse_stream << "2 bottles of beer on the wall, 2 bottles of beer.\n"
				<< "Take one down and pass it around, 1 bottle of beer on the wall.\n";
		}
		else {
			verse_stream << bottle_count << " bottles of beer on the wall, " << bottle_count << " bottles of beer.\n"
				<< "Take one down and pass it around, " << (bottle_count - 1) << " bottles of beer on the wall.\n";
		}
		return verse_stream.str();
	}

	std::string sing(int start, int end) {
		std::stringstream song;
		for (int i = start; i >= end; i--) {
			song << verse(i);
			if (i > end) {
				song << "\n";
			}
		}
		return song.str();
	}
}