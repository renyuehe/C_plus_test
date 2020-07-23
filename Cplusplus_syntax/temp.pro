TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

# 添加编译标志开关
# -fno-elide-constructors:不要优化，产生临时对象
QMAKE_CXXFLAGS += -fno-elide-constructors
