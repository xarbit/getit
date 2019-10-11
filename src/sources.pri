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
FACTORY_HEADERS     =

FACTORY_SOURCES     =

# --------------
# Requests
REQUESTS_HEADERS    =   $$DOMAIN_DIR/requests/bodies/FormdataRequestBody.hpp \
                        $$DOMAIN_DIR/requests/bodies/JsonRequestBody.hpp \
                        $$DOMAIN_DIR/requests/bodies/RawRequestBody.hpp \
                        $$DOMAIN_DIR/requests/IRequestBody.hpp \
                        $$DOMAIN_DIR/requests/Request.hpp

REQUESTS_SOURCES    =   $$DOMAIN_DIR/requests/bodies/FormdataRequestBody.cpp \
                        $$DOMAIN_DIR/requests/bodies/JsonRequestBody.cpp \
                        $$DOMAIN_DIR/requests/bodies/RawRequestBody.cpp \
                        $$DOMAIN_DIR/requests/Request.cpp

# --------------
# Responses
RESPONSES_HEADERS   =   $$DOMAIN_DIR/responses/Response.hpp

RESPONSES_SOURCES   =   $$DOMAIN_DIR/responses/Response.cpp

# ----------------------------------------

DOMAIN_SOURCES      =   $$EXCEPTION_SOURCES \
                        $$FACTORY_SOURCES \
                        $$REQUESTS_SOURCES \
                        $$RESPONSES_SOURCES

DOMAIN_HEADERS      =   $$EXCEPTION_HEADERS \
                        $$FACTORY_HEADERS \
                        $$REQUESTS_HEADERS \
                        $$RESPONSES_HEADERS
