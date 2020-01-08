cmake_minimum_required(VERSION 3.16 FATAL_ERROR)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(cpprestsdk REQUIRED)
find_package(Boost COMPONENTS thread system chrono REQUIRED)

set(SOURCEFILES
    main.cpp
    domain/CppRestRequest.cpp
    domain/FormdataRequestBody.cpp
    domain/Request.cpp
    domain/RawRequestBody.cpp
    gui/MainWindow/MainWindow.cpp
    gui/RequestBody/RawRequestBody/RawRequestBodyWidget.cpp
)

set(HEADERFILES
    domain/CppRestRequest.hpp
    domain/FormdataRequestBody.hpp
    domain/RawRequestBody.hpp
    domain/Request.hpp
    domain/RequestBody.hpp
    domain/Response.hpp
    gui/MainWindow/MainWindow.hpp
    gui/RequestBody/RawRequestBody/RawRequestBodyWidget.hpp
    gui/RequestBody/BodyWidget.hpp
)

set(UIFILES
    gui/MainWindow/MainWindow.ui
    gui/RequestBody/RawRequestBody/RawRequestBodyWidget.ui
)

add_executable(getit
    ${HEADERFILES}
    ${SOURCEFILES}
    ${UIFILES}
)

# Libraries
target_link_libraries(getit Qt5::Widgets)
target_link_libraries(getit cpprestsdk::cpprest)
target_link_libraries(getit Boost::thread Boost::system Boost::chrono)
