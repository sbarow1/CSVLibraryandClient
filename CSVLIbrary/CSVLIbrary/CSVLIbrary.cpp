// CSVLibrary.cpp : Defines the exported functions for the DLL application.
//
#include "stdafx.h"
#include "CSVLibrary.h"

namespace CSVLibrary
{
	void CSVRow::readNextRow(std::istream& str)
	{
		std::string line;
		std::getline(str, line);
		char ch;

		std::stringstream lineStream(line);
		std::string cell;

		m_data.clear();
		while (lineStream.good())
		{
			if (lineStream.peek() == '"') {
				lineStream.get(ch);
				std::getline(lineStream, cell, '"');
				lineStream.get(ch);
				cell.insert(cell.begin(), '"');
				cell.push_back('"');
				m_data.push_back(cell);
			}
			else {
				std::getline(lineStream, cell, ',');
				m_data.push_back(cell);
			}
		}
		//while (std::getline(lineStream, cell, ','))
		//{
		//	m_data.push_back(cell);
		//}
		// THis checks for a trailing comma with no data after it
		if (!lineStream && cell.empty())
		{
			// if there was a trailing comma then add an empty element
			m_data.push_back("");
		}
	}

	std::istream& operator>>(std::istream &str, CSVRow& data)
	{
		data.readNextRow(str);
		return str;
	}

	std::ostream& operator<<(std::ostream & os, CSVRow & data)
	{
		for (int i = 0; i < data.size(); i++)
		{
			os << data[i] << ',';
		}
		os << std::endl;
		return os;
	}
}


