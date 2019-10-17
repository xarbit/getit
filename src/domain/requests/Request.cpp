#include "domain/requests/Request.hpp"

using namespace Domain::Requests;
using namespace Domain::Responses;

Request::Request(QNetworkAccessManager* networkManager, bool followRedirects):
    networkManager(networkManager),
    followRedirects(followRedirects)
{
    cookieJar = new QNetworkCookieJar(this);
}

Request::~Request()
{
    delete networkManager;
    delete cookieJar;
    delete requestBody;

    cookies.clear();
    headers.clear();
}

void Request::send(std::string httpMethod, std::string uri)
{
    QNetworkRequest request;
    auto url = QUrl(uri.c_str());

    QObject::connect(networkManager, &QNetworkAccessManager::finished,
                this, [=](QNetworkReply* reply) {
                    if (reply->error()) {
                        emit requestError(reply->errorString().toStdString());
                        return;
                    }

                    std::list<std::pair<std::string, std::string>> headers;

                    auto rawHeaders = reply->rawHeaderPairs();
                    auto body = reply->readAll().toStdString();

                    for (auto const& item : headers) {
                        headers.push_back(std::pair(item.first, item.second));
                    }

                    auto response = new Response(body, headers);
                    emit requestSent(response);
                }
            );

    request.setUrl(url);
    request.setAttribute(QNetworkRequest::Attribute::FollowRedirectsAttribute, followRedirects);
    addHeadersToRequest(request);
    addCookiesToRequest();

    networkManager->sendCustomRequest(request, httpMethod.c_str());
}

void Request::addCookie(std::string name, std::string value)
{
    auto cookie = std::pair(name, value);
    this->cookies.push_back(cookie);
}

void Request::addHeader(std::string name, std::string value)
{
    auto header = std::pair(name, value);
    this->headers.push_back(header);
}

void Request::setBody(IRequestBody* body)
{
    this->requestBody = body;
}

void Request::addHeadersToRequest(QNetworkRequest request)
{
    for (auto const& header : headers) {
        request.setRawHeader(header.first.c_str(), header.second.c_str());
    }
}

void Request::addCookiesToRequest()
{
    for (auto const& rawCookie : cookies) {
        QByteArray name = rawCookie.first.c_str();
        QByteArray value = rawCookie.second.c_str();
        QNetworkCookie cookie(name, value);

        cookieJar->insertCookie(cookie);
    }

    networkManager->setCookieJar(cookieJar);
}
