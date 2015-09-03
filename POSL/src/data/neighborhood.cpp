#include "neighborhood.h"

Neighborhood::Neighborhood(vector<int> _current_configuration)
    : current_configuration(_current_configuration),
      configuration_changed(_current_configuration.size())
{}

Neighborhood::Neighborhood(int _config_size)
    : current_configuration(_config_size),
      configuration_changed(_config_size)
{}
