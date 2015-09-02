#include "neighborhood.h"

Neighborhood::Neighborhood(vector<int> _current_configuration)
    : current_configuration(_current_configuration),
      configuration_changed(_current_configuration.size())
{}
