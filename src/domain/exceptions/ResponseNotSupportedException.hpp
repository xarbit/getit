#pragma once

#include <exception>
#include <string>

namespace Domain
{
    namespace Exceptions
    {
        class ResponseNotSupportedException: public std::exception
        {

            public:
                explicit ResponseNotSupportedException(std::string responseType);

                virtual const char* what() const noexcept;

            private:
                std::string responseType;
        };
    }
}
