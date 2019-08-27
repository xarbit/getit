#include "ResponseNotSupportedException.hpp"

using namespace Domain::Exceptions;

ResponseNotSupportedException::ResponseNotSupportedException(std::string responseType):
    responseType(responseType)
{

}

const char* ResponseNotSupportedException::what() const noexcept
{
    std::string errorMessage = "Cannot find response '" + responseType + "'";
    return errorMessage.c_str();
}
