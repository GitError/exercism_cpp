#pragma once

namespace space_age {
	class space_age {
	private:
		long int secs;
		static constexpr float EARTH_YEAR_IN_SECONDS = 31557600.0f;
		static constexpr float MERCURY_YEAR_RATIO = 0.2408467f;
		static constexpr float VENUS_YEAR_RATIO = 0.61519726f;
		static constexpr float MARS_YEAR_RATIO = 1.8808158f;
		static constexpr float JUPITER_YEAR_RATIO = 11.862615f;
		static constexpr float SATURN_YEAR_RATIO = 29.447498f;
		static constexpr float URANUS_YEAR_RATIO = 84.016846f;
		static constexpr float NEPTUNE_YEAR_RATIO = 164.79132f;

	public:
		explicit space_age(long int seconds);
		long int seconds() const;
		float on_earth() const;
		float on_mercury() const;
		float on_venus() const;
		float on_mars() const;
		float on_jupiter() const;
		float on_saturn() const;
		float on_uranus() const;
		float on_neptune() const;
	};
}