#pragma once
#include "libass/ass.h"
#include <memory>

class SubAssParser:
	public SubtitleParser
{
private:
	struct TrackDeleter
	{
		void operator()(ASS_Track* p) const
		{
			ass_free_track(p);
		};
	};

	struct LibraryDeleter
	{
		void operator()(ASS_Library* p) const
		{
			ass_library_done(p);
		};
	};

	void parse(std::string fileName);
	std::unique_ptr<ASS_Track, TrackDeleter> _track;
	std::unique_ptr<ASS_Library, LibraryDeleter> _library;
public:
	SubAssParser(void);
	SubAssParser(std::string fileName);
	~SubAssParser(void);

};

