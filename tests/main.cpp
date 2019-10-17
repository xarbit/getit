#include <QTest>

#include "domain/requests/tst_Request.hpp"
#include "domain/requests/bodies/tst_FormdataRequestBody.hpp"
#include "domain/requests/bodies/tst_JsonRequestBody.hpp"
#include "domain/requests/bodies/tst_RawRequestBody.hpp"

int main(int argc, char** argv)
{
    int status = 0;
    status |= QTest::qExec(new tst_FormdataRequestBody(), argc, argv);
    status |= QTest::qExec(new tst_JsonRequestBody(), argc, argv);
    status |= QTest::qExec(new tst_RawRequestBody(), argc, argv);
    status |= QTest::qExec(new tst_Request(), argc, argv);

//    auto req = new Domain::Requests::Request(new QNetworkAccessManager());
//    QObject::connect(req, &Domain::Requests::Request::requestSent, nullptr, [](Domain::Responses::Response* response) {

//    });

    return status;
}
