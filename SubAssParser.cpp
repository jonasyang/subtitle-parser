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
#include "libass/ass_render.h"

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

    auto ass_renderer = ass_renderer_init(_library.get());
    if (!ass_renderer) {
        printf("ass_renderer_init failed!\n");
        exit(1);
    }

    ass_set_frame_size(ass_renderer, 1280, 768);

    int cnt = 0;
    for (int i = 0; i < _track->n_events; i++) {
        ASS_Event* event = _track->events + i;
        if (ass_render_event(ass_renderer, event, nullptr)) {
                cnt++;
        }
    }
}

SubAssParser::~SubAssParser(void)
{
}
