#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <memory>
#include "SubtitleParserFactory.h"

SubtitleParserFactory::SubtitleParserFactory(std::string fileName)
{
	_fileName = fileName;
	_subFormat = checkSubtitleFormat(fileName);
}

SubtitleFormat SubtitleParserFactory::checkSubtitleFormat(std::string fileName)
{
	if(fileName.size()<5) return UndefinedType;
	
	std::string format = fileName.substr(fileName.size()-4,fileName.size());

	if(format == ".srt")
	{
		return SubRip;
	}
	else if(format == ".sub")
	{
		return MicroDvd;
	}
	else if(format == ".vtt")
	{
		return WebVtt;
	}
	else if (format == ".ass")
	{
		return Ass;
	}
    else
    {
        return UndefinedType;
    }
}

std::unique_ptr<SubtitleParser> SubtitleParserFactory::getParser()
{
	switch(_subFormat)
	{
		case SubRip:
		{
			return std::make_unique<SubRipParser>(_fileName);
		}
		break;
		case Ass:
		{
			return std::make_unique<SubAssParser>(_fileName);
		}
		default:
		{
			std::cout<<"Error: Undefined subtitle format!";
                        throw std::exception();
		}
	}
    throw std::exception();
}

SubtitleParserFactory::~SubtitleParserFactory(void)
{
}
