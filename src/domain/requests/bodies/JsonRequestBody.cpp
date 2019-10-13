#include "domain/requests/bodies/JsonRequestBody.hpp"

using namespace Domain::Requests;

JsonRequestBody::JsonRequestBody(std::map<std::string, std::string> jsonKeys):
    jsonKeys(jsonKeys)
{

}

JsonRequestBody::~JsonRequestBody()
{

}

std::string JsonRequestBody::getBody()
{
    std::string jsonTemplate;
    std::string data;

    for (auto const& iterator: this->jsonKeys) {
        data = data
                .append("\"")
                .append(iterator.first)
                .append("\"")
                .append(":")
                .append("\"")
                .append(iterator.second)
                .append("\"")
                .append(",");
    }

    // Remove last comma
    data.pop_back();

    return jsonTemplate
            .append("{")
            .append(data)
            .append("}");
}
