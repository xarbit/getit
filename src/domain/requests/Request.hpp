#pragma once

#include <list>
#include <string>
#include <QObject>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkCookie>
#include <QtNetwork/QNetworkCookieJar>

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

                void send(std::string httpMethod, std::string uri, std::function<void(Responses::Response*, std::string)> func);

                void addCookie(std::string name, std::string value);
                void addHeader(std::string name, std::string value);
                void setBody(IRequestBody* body);

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
