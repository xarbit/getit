#pragma once

#include <string>

#include "ICookie.hpp"
#include "IHeader.hpp"



/*#pragma once

#include <std>

#include "ICookie.h"
#include "IHeader.h"
#include "IResponse.h"
#include "IResponseFactory.h"

namespace Domain {

    class Request {
        virtual ~Request(){} = default;

        virtual IResponse send() = default;

        void addCookie(ICookie* cookie);
        void addHeader(IHeader* header);

        protected:
            virtual std::string getHTTPMethod() = default;

        private:
            IResponseFactory* responseFactory;
            std::list<ICookie*> cookies;
            std::list<IHeader*> headers;
    }
}

*/
