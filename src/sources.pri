DOMAIN_SOURCES  =   $$APP_ROOT_DIR/src/domain/factories/ResponseFactory.cpp

DOMAIN_HEADERS  =   $$APP_ROOT_DIR/src/domain/ICookie.hpp \
                    $$APP_ROOT_DIR/src/domain/IHeader.hpp \
                    $$APP_ROOT_DIR/src/domain/IResponse.hpp \
                    $$APP_ROOT_DIR/src/domain/Request.hpp \
                    $$APP_ROOT_DIR/src/domain/factories/ResponseFactory.hpp \
                    $$APP_ROOT_DIR/src/domain/factories/IResponseFactory.hpp \
                    $$APP_ROOT_DIR/src/domain/exceptions/ResponseNotSupportedException.hpp

SOURCES += \
    $$PWD/domain/exceptions/ResponseNotSupportedException.cpp
