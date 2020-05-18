#include <sstream>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <regex>
#include <deque>
#include "SubtitleParser.h"
#include "SubAssParser.h"
#include "libass/ass.h"

void SubAssParser::parse(std::string fileName)
{
}

SubAssParser::SubAssParser(void): _track(nullptr), _library(nullptr)
{
    _library.reset(ass_library_init());
}

SubAssParser::SubAssParser(std::string fileName)
{
    _library.reset(ass_library_init());
    _track.reset(ass_read_file(_library.get(), (char *)fileName.c_str(), nullptr));
}

SubAssParser::~SubAssParser(void)
{
}
