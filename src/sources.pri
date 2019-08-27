# --------------------------------------------------------------------------------
# --------------------------------------------------------------------------------
# DOMAIN LAYER
# --------------------------------------------------------------------------------
# --------------------------------------------------------------------------------
DOMAIN_DIR          = $$APP_ROOT_DIR/src/domain

# --------------
# Exceptions
EXCEPTION_HEADERS   =   $$DOMAIN_DIR/exceptions/ResponseNotSupportedException.hpp

EXCEPTION_SOURCES   =   $$DOMAIN_DIR/exceptions/ResponseNotSupportedException.cpp

# --------------
# Factories
FACTORY_HEADERS     =   $$DOMAIN_DIR/factories/IResponseFactory.hpp \
                        $$DOMAIN_DIR/factories/ResponseFactory.hpp

FACTORY_SOURCES     =   $$DOMAIN_DIR/factories/ResponseFactory.cpp

# --------------
# Requests
REQUESTS_HEADERS    =   $$DOMAIN_DIR/requests/

REQUESTS_SOURCES    =   $$DOMAIN_DIR/requests/

# --------------
# Responses
RESPONSES_HEADERS   =   $$DOMAIN_DIR/responses/IResponse.hpp \
                        $$DOMAIN_DIR/responses/JsonResponse.hpp \
                        $$DOMAIN_DIR/responses/RawResponse.hpp \
                        $$DOMAIN_DIR/responses/XmlResponse.hpp

RESPONSES_SOURCES   =   $$DOMAIN_DIR/responses/JsonResponse.cpp \
                        $$DOMAIN_DIR/responses/RawResponse.cpp \
                        $$DOMAIN_DIR/responses/XmlResponse.cpp

# ----------------------------------------

DOMAIN_SOURCES      =   $$EXCEPTION_SOURCES \
                        $$FACTORY_SOURCES \
#                        $$REQUESTS_SOURCES \
                        $$RESPONSES_SOURCES

DOMAIN_HEADERS      =   $$APP_ROOT_DIR/src/domain/ICookie.hpp \
                        $$APP_ROOT_DIR/src/domain/IHeader.hpp \
                        $$APP_ROOT_DIR/src/domain/Request.hpp \
                        $$EXCEPTION_HEADERS \
                        $$FACTORY_HEADERS \
#                        $$REQUESTS_HEADERS \
                        $$RESPONSES_HEADERS

