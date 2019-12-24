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
    return "multipart/formdata; boundary=\"" + this->boundary + "\"";
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
    return this->boundary + 
            "\r\n" + 
            "Content-Disposition: form-data; name=" +
            "\"" + key + "\"" +
            "\r\n\r\n" +
            value;
}

std::string FormdataRequestBody::buildContentDataFile(std::string key, std::string fileName, std::string contents)
{
    return this->boundary + 
            "\r\n" + 
            "Content-Disposition: form-data; name=" +
            "\"" + key + "\"; filename=" +
            "\"" + fileName + "\"" +
            "\r\n\r\n" +
            contents;
}