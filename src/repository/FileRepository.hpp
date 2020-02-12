#pragma once

#include "repository/Repository.hpp"

namespace getit::repository
{
    class FileRepository: public Repository
    {
        public:
            FileRepository(std::string filePath);
            ~FileRepository();

            void save(getit::domain::Request* request) override;
            getit::domain::Request* open(std::string filePath) override;

        private:
            std::string filePath;
    };
}