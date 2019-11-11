#pragma once

#include <cpr/cpr.h>
#include "domain/Request.hpp"

namespace getit
{
    class CprRequest: public Request<cpr::Session>
    {

    };
}