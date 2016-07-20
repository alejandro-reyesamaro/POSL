#include "configuration_set_iterator.h"

ConfigurationSetIterator::ConfigurationSetIterator(std::shared_ptr<ConfigurationSet> _set)
    : set(_set),
      current(0)
{}

std::vector<int> ConfigurationSetIterator::GetNext()
{
    return set->elementAt(current ++);
}

bool ConfigurationSetIterator::SomeNext()
{
    return current < set->size();
}

void ConfigurationSetIterator::Reset()
{
    current = 0;
}
