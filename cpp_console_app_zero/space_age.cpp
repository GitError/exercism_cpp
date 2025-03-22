#include "space_age.h"

namespace space_age {
	space_age::space_age(long int seconds) : secs(seconds) {}

	long int space_age::seconds() const { return secs; }

	float space_age::on_earth() const { return secs / EARTH_YEAR_IN_SECONDS; }

	float space_age::on_mercury() const { return on_earth() / MERCURY_YEAR_RATIO; }

	float space_age::on_venus() const { return on_earth() / VENUS_YEAR_RATIO; }

	float space_age::on_mars() const { return on_earth() / MARS_YEAR_RATIO; }

	float space_age::on_jupiter() const { return on_earth() / JUPITER_YEAR_RATIO; }

	float space_age::on_saturn() const { return on_earth() / SATURN_YEAR_RATIO; }

	float space_age::on_uranus() const { return on_earth() / URANUS_YEAR_RATIO; }

	float space_age::on_neptune() const { return on_earth() / NEPTUNE_YEAR_RATIO; }
}