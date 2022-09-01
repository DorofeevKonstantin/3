#pragma once

template <class data_t, template <class> class container_t>
container_t<data_t>
create_container(int count)
{
	container_t<data_t> result;
	for (int i = 0; i < count; ++i)
		result.push_back(rand() % 100);
	return result;
}

void create_container_Samples();