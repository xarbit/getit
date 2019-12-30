#include "domain/FormdataRequestBody.hpp"

using namespace getit::domain;

FormdataRequestBody::FormdataRequestBody(std::string boundary):
    boundary(boundary)
{

}

FormdataRequestBody::~FormdataRequestBody()
{

}

void FormdataRequestBody::addElement(std::string key, std::string value)
{
    this->body.push_back(
        this->buildContentData(key, value)
    );
}

void FormdataRequestBody::addFile(std::string key, std::string filePath)
{
    std::ifstream inputFileStream(filePath);
    std::string value(
        (std::istreambuf_iterator<char>(inputFileStream)),
        (std::istreambuf_iterator<char>())
    );
    
    this->body.push_back(
        this->buildContentDataFile(key, filePath, value)
    );
}

std::string FormdataRequestBody::getContentType()
{
    boost::format frmt = boost::format(
        "multipart/formdata; boundary=\"%1%\""
    ) % this->boundary;

    return frmt.str();
}

std::string FormdataRequestBody::getBody()
{
    std::string body;

    for (auto const& value: this->body) {
        body += value;
    }

    return body;
}

size_t FormdataRequestBody::getSize()
{
    return this->getBody().size();
}

std::string FormdataRequestBody::buildContentData(std::string key, std::string value)
{
    boost::format frmt = boost::format(
        "%1%\r\nContent-Disposition: form-data; name=\"%2%\"\r\n\r\n%3%"
    ) % this->boundary % key % value;

    return frmt.str();
}

std::string FormdataRequestBody::buildContentDataFile(std::string key, std::string fileName, std::string contents)
{
    boost::format frmt = boost::format(
        "%1%\r\nContent-Disposition: form-data; name=\"%2%\"; filename=\"%3%\"\r\n\r\n%4%"
    ) % this->boundary % key % fileName % contents;

    return frmt.str();
}