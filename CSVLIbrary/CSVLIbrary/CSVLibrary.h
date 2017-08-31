#pragma once

#ifdef CSVLIBRARY_EXPORTS  
#define CSVLIBRARY_API __declspec(dllexport)   
#else  
#define CSVLIBRARY_API __declspec(dllimport)   
#endif 

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

template class CSVLIBRARY_API std::basic_string<char, std::char_traits<char>, std::allocator<char>>;
template class CSVLIBRARY_API std::vector<std::string>;

namespace CSVLibrary
{
	class CSVLIBRARY_API CSVRow
	{
	private:
		std::vector<std::string> m_data;
	public:
		std::string const& operator[](std::size_t index)
		{
			return m_data[index];
		}
		std::size_t size()
		{
			return m_data.size();
		}
		void readNextRow(std::istream& str);
		__declspec(dllexport) friend std::istream& operator>>(std::istream& str, CSVRow& data);
		__declspec(dllexport) friend std::ostream& operator<<(std::ostream& os, CSVRow& data);
	};
}

