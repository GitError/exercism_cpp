#include "speedywagon.h"

namespace speedywagon {
	int uv_light_heuristic(std::vector<int>* data_array) {
		double avg{};
		for (auto element : *data_array) {
			avg += element;
		}
		avg /= data_array->size();
		int uv_index{};
		for (auto element : *data_array) {
			if (element > avg) ++uv_index;
		}
		return uv_index;
	}

	bool connection_check(pillar_men_sensor* sensor)
	{
		return sensor != nullptr;
	}

	int activity_counter(pillar_men_sensor* first_sensor, int capacity) {
		int total_activity = 0;
		for (pillar_men_sensor* sensor = first_sensor; sensor < first_sensor + capacity; ++sensor) {
			total_activity += sensor->activity;
		}
		return total_activity;
	}

	bool alarm_control(pillar_men_sensor* sensor)
	{
		return connection_check(sensor) && sensor->activity > 0;
	}

	bool uv_alarm(pillar_men_sensor* sensor)
	{
		return connection_check(sensor) && uv_light_heuristic(&sensor->data) > sensor->activity;
	}
}