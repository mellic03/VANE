#include <vane/util/cfgparser.hpp>
#include <vane/util/file.hpp>
#include <vane/core/log.hpp>
#include <fstream>

using namespace vane;


void CfgParser::skip( char )
{
    char ch = mBuf[mIdx];

    while (mIdx < mBuf.size() && ch && (ch==' '))
    {
        ch = mBuf[mIdx++];
    }

    if (mIdx >= mBuf.size() - 1)
    {
        mIdx = mBuf.size() - 1;
    }
}


char CfgParser::peek()
{
    skip(' ');

    if (mIdx >= mBuf.size() - 1)
    {
        mIdx = mBuf.size() - 1;
        return '\0';
    }
    return mBuf[mIdx];
}


char CfgParser::advance()
{
    char ch = peek();
    if (!ch) return ch;

    mIdx += 1;
    mCol += 1;

    if (ch == '\n')
    {
        mLine += 1;
        mCol = 1;
    }

    return ch;
}


char CfgParser::retreat()
{
    mIdx -= 1;
    return peek();
}


char CfgParser::match( char ch )
{
    if (peek() == ch)
        return advance();
    return '\0';    
}



std::string CfgParser::_readLabel()
{
    std::string str = "";

    while (char ch = advance())
    {
        if (ch=='=')
            break;
        if (!isalnum(ch) && ch!='_' && ch!='-' && ch!='.')
            break;
        str.push_back(ch);
    }

    return str;
}


std::string CfgParser::_readTo( char stop )
{
    std::string str = "";
    while (char ch = advance())
    {
        if (ch==stop) break;
        str.push_back(ch);
    }
    return str;
}


CfgParser::CfgParser( const std::string &path )
:   mIdx(0), mLine(0), mCol(0)
{
    for (char ch: vane::loadRaw(path))
    {
        if (ch != ' ')
        {
            mBuf.push_back(ch);
        }
    }

    mIdx  = 0;
    mLine = 1;
    mCol  = 1;

    std::string section = "GLOBAL";
    bool is_comment = false;

    while (char ch = peek())
    {
        if (ch=='\n')
        {
            is_comment = false;
            advance();
        }

        else if (is_comment)
        {
            advance();
        }

        else if (match('#'))
        {
            is_comment = true;
        }

        else if (match('['))
        {
            section = _readTo(']');
        }
    
        else if (isalpha(ch))
        {
            std::string key = _readLabel();

            if (match('\"'))
                mData[section][key] = _readTo('\"');
            else
                mData[section][key] = _readTo('\n');
        }
    }
}



void CfgParser::print()
{
    for (auto &[section, keyval]: mData)
    {
        syslog log("Section %s", section.c_str());

        for (auto &[key, value]: keyval)
        {
            log("%s = \"%s\"", key.c_str(), value.c_str());
        }
    }
}

