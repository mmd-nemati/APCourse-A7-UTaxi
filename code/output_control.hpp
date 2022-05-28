#ifndef __OUTPUT_CONTROL_H__
#define __OUTPUT_CONTROL_H__

#include <vector>
#include <string>
#include <stdexcept>
#include "trip.hpp"
#include "../defines.hpp"

class OutputControl
{
    public:
        OutputControl() {;}
        void trips_list(std::vector<Trip*> trips);
        void error(std::runtime_error& error);
        void done();
        void trip_id(int _id);
        void trip_data(Trip* trip);
        void cost(double _cost);
};

#endif /* __OUTPUT_CONTROL_H__ */