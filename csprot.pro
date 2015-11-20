
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXX = g++-5
QMAKE_CXXFLAGS += \
	-std=c++14

SOURCES += \
	main.cpp

HEADERS += \
	csprot.hpp
