
include(CheckCXXSourceCompiles)
include(CheckCXXCompilerFlag)
include_directories(.)

add_executable (parser 
    subparser.cpp
    SubRipParser.cpp
    SubtitleItem.cpp
    SubtitleParser.cpp
    SubtitleParserFactory.cpp
    SubtitleWord.cpp
    SubtitleParser/SubtitleParser/main.cpp)

set_property(TARGET parser PROPERTY CXX_STANDARD 14)