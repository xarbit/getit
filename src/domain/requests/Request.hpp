#pragma once

#include <future>
#include <list>
#include <string>
#include <QObject>
#include <QUrl>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkCookie>
#include <QNetworkCookieJar>

#include "domain/requests/IRequestBody.hpp"
#include "domain/responses/Response.hpp"

namespace Domain
{
    namespace Requests
    {
        class Request: public QObject
        {
                Q_OBJECT

            public:
                Request(QNetworkAccessManager* networkManager, bool followRedirects = true);
                ~Request();

                void send(std::string httpMethod, std::string uri);

                void addCookie(std::string name, std::string value);
                void addHeader(std::string name, std::string value);
                void setBody(IRequestBody* body);

            signals:
                void requestError(std::string errorMessage);
                void requestSent(Responses::Response* response);

            protected:
                std::list<std::pair<std::string, std::string>> cookies;
                std::list<std::pair<std::string, std::string>> headers;
                IRequestBody* requestBody;

            private:
                void addHeadersToRequest(QNetworkRequest request);
                void addCookiesToRequest();

                QNetworkCookieJar* cookieJar;
                QNetworkAccessManager* networkManager;
                bool followRedirects = false;
        };
    }
}
