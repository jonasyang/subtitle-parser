
include(CheckCXXSourceCompiles)
include(CheckCXXCompilerFlag)
include_directories(.)

add_executable (parser 
    libass/ass.c
    libass/ass_bitmap.c
    libass/ass_blur.c
    libass/ass_cache.c
    libass/ass_library.c
    libass/ass_parse.c
    libass/ass_rasterizer.c
    libass/ass_rasterizer_c.c
    libass/ass_render.c
    libass/ass_render_api.c
    libass/ass_shaper.c
    libass/ass_string.c
    libass/ass_strtod.c
    libass/ass_utils.c
    main.cpp
    SubAssParser.cpp
    subparser.cpp
    SubRipParser.cpp
    SubtitleItem.cpp
    SubtitleParser.cpp
    SubtitleParserFactory.cpp
    SubtitleWord.cpp)

set_property(TARGET parser PROPERTY CXX_STANDARD 14)