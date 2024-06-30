#include "stories.h"

class storiesData : public QSharedData
{
public:
};

stories::stories()
    : data(new storiesData)
{}

stories::stories(const stories &rhs)
    : data{rhs.data}
{}

stories &stories::operator=(const stories &rhs)
{
    if (this != &rhs)
        data.operator=(rhs.data);
    return *this;
}

stories::~stories() {}
