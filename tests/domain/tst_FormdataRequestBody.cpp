#include <catch2/catch.hpp>
#include <string>

#include "domain/FormdataRequestBody.hpp"

#include <iostream>

SCENARIO("Newly constructed FormdataRequestBody", "[domain]")
{
    std::string boundary = "--abc";

    WHEN("The contentType is requested")
    {
        auto requestBody = new getit::domain::FormdataRequestBody(boundary);

        THEN("the contentType with the given boundary is returned")
        {
            std::string contentType = "multipart/formdata; boundary=\"" + boundary + "\"";
            std::string result = requestBody->getContentType();

            REQUIRE(result == contentType);
        }
    }

    WHEN("A value is added to the body")
    {
        auto requestBody = new getit::domain::FormdataRequestBody(boundary);
        std::string key = "MyBodyKey";
        std::string value = "This&is=My+Body@";
        std::string expectedOutput = boundary + "\r\nContent-Disposition: form-data; name=\"" + key + "\"\r\n\r\n" + value;

        requestBody->addElement(key, value);

        THEN("the body should include the value")
        {
            std::string result = requestBody->getBody();

            REQUIRE(result == expectedOutput);
        }
    }

    WHEN("A non-existing file is added to the body")
    {
        auto requestBody = new getit::domain::FormdataRequestBody(boundary);
        std::string key = "MyFile";
        std::string filePath = "../non-existing-file.non_existing_ext";
        std::string expectedOutput = boundary + "\r\nContent-Disposition: form-data; name=\"" + key + "\"; filename=\"" + filePath + "\"\r\n\r\n";

        requestBody->addFile(key, filePath);

        THEN("the body should include the file without any data")
        {
            std::string result = requestBody->getBody();

            REQUIRE(result == expectedOutput);
        }

        THEN("the size of the body should be the same as the size of the expected body")
        {
            size_t result = requestBody->getSize();

            REQUIRE(result == expectedOutput.size());
        }
    }

    WHEN("An existing file is added to the body")
    {
        auto requestBody = new getit::domain::FormdataRequestBody(boundary);
        std::string key = "MyFile";
        std::string filePath = "./tst_file.txt";
        std::string expectedOutput = boundary + "\r\nContent-Disposition: form-data; name=\"" + key + "\"; filename=\"" + filePath + "\"\r\n\r\ncontent";

        requestBody->addFile(key, filePath);

        THEN("the body should include the file with it's contents")
        {
            std::string result = requestBody->getBody();

            REQUIRE(result == expectedOutput);
        }

        THEN("the size of the body should be the same as the size of the expected body")
        {
            size_t result = requestBody->getSize();

            REQUIRE(result == expectedOutput.size());
        }
    }

    WHEN("An existing file and an element are added to the body")
    {
        auto requestBody = new getit::domain::FormdataRequestBody(boundary);

        std::string elementKey = "MyBodyKey";
        std::string elementValue = "This&is=My+Body@";
        std::string expectedElementOutput = boundary + "\r\nContent-Disposition: form-data; name=\"" + elementKey + "\"\r\n\r\n" + elementValue;
        std::string fileKey = "MyFile";
        std::string filePath = "./tst_file.txt";
        std::string expectedFileOutput = boundary + "\r\nContent-Disposition: form-data; name=\"" + fileKey + "\"; filename=\"" + filePath + "\"\r\n\r\ncontent";

        requestBody->addFile(fileKey, filePath);
        requestBody->addElement(elementKey, elementValue);

        THEN("the body should include both the file and value")
        {
            std::string result = requestBody->getBody();

            REQUIRE(result == (expectedFileOutput + expectedElementOutput));
        }

        THEN("the size of the body should be the sizes of the expected outputs combined")
        {
            size_t result = requestBody->getSize();

            REQUIRE(result == (expectedFileOutput.size() + expectedElementOutput.size()));
        }
    }
}