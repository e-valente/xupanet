#Emanuel Valente - emanuelvalente@gmail.com
cmake_minimum_required(VERSION 2.8.11)

project(testproject)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed.
set(CMAKE_AUTOMOC ON)

# Find the QtWidgets library
find_package(Qt5Widgets)
find_package(Qt5Network)
find_package(Qt5WebKitWidgets)
find_package(Qt5WebKit)

QT5_WRAP_UI(UIS_HDRS
    xupanet.ui
    proxylist.ui
)

# Tell CMake to create the helloworld executable
add_executable(xupanet main.cpp xupanet.cpp proxylist.cpp youtubeurlhandler.cpp ${UIS_HDRS})

# Use the Widgets module from Qt 5.
target_link_libraries(xupanet Qt5::Widgets Qt5::WebKitWidgets)