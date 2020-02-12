#include "repository/FileRepository.hpp"

using namespace getit::repository;

FileRepository::FileRepository(std::string filePath):
    filePath(filePath)
{

}

FileRepository::~FileRepository()
{

}

void FileRepository::save(getit::domain::Request* request)
{

}

getit::domain::Request* FileRepository::open(std::string filePath)
{
    this->filePath = filePath;
}