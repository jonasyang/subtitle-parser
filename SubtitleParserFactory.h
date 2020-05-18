#pragma once
#include "SubtitleParser.h"
#include "SubRipParser.h"
#include "SubAssParser.h"

enum SubtitleFormat
{
	UndefinedType = -1,
	SubRip,
	MicroDvd,
	WebVtt,
	Ass
};
class SubtitleParser;

class SubtitleParserFactory
{
private:
	SubtitleFormat _subFormat;
	std::string _fileName;
public:
	std::unique_ptr<SubtitleParser> getParser();
        SubtitleParserFactory(std::string fileName);
	SubtitleFormat checkSubtitleFormat(std::string fileName);
	~SubtitleParserFactory(void);
};

