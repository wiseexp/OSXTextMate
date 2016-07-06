#ifndef FILE_ENCODING_H_CM7CPD1M
#define FILE_ENCODING_H_CM7CPD1M

#include "bytes.h"
#include <oak/oak.h>

PUBLIC extern std::string const kCharsetNoEncoding;
PUBLIC extern std::string const kCharsetASCII;
PUBLIC extern std::string const kCharsetUTF8;
PUBLIC extern std::string const kCharsetUTF16BE;
PUBLIC extern std::string const kCharsetUTF16LE;
PUBLIC extern std::string const kCharsetUTF32BE;
PUBLIC extern std::string const kCharsetUTF32LE;
PUBLIC extern std::string const kCharsetUnknown;

namespace encoding
{
	template <typename _InputIter>
	std::string charset_from_bom (_InputIter const& first, _InputIter const& last)
	{
		static struct UTFBOMTests { std::string bom; std::string encoding; } const BOMTests[] =
		{
			{ std::string("\x00\x00\xFE\xFF", 4), kCharsetUTF32BE },
			{ std::string("\xFE\xFF",         2), kCharsetUTF16BE },
			{ std::string("\xFF\xFE\x00\x00", 4), kCharsetUTF32LE },
			{ std::string("\xFF\xFE",         2), kCharsetUTF16LE },
			{ std::string("\uFEFF",           3), kCharsetUTF8    }
		};

		for(auto const& test : BOMTests)
		{
			if(oak::has_prefix(first, last, test.bom.begin(), test.bom.end()))
				return test.encoding + "//BOM";
		}
		return kCharsetNoEncoding;
	}

	PUBLIC io::bytes_ptr convert (io::bytes_ptr content, std::string const& from, std::string const& to);

	struct PUBLIC type
	{
		type () { }
		type (std::string const& newlines, std::string const& charset) : _newlines(newlines), _charset(charset) { }

		std::string const& newlines () const { return _newlines; }
		std::string const& charset () const  { return _charset; }

		void set_newlines (std::string const& newlines) { _newlines = newlines; }
		void set_charset (std::string const& charset)   { _charset = charset; }

	private:
		std::string _newlines = NULL_STR;
		std::string _charset  = kCharsetNoEncoding;
	};

} /* encoding */

#endif /* end of include guard: FILE_ENCODING_H_CM7CPD1M */
