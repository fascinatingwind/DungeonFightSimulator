#pragma once
#ifndef EXAMPLE_PARSER_H
#define EXAMPLE_PARSER_H

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

struct example_sheet
{
	int age;
	std::string name;
};

struct example_vec
{
	std::vector<int> some_data;
};

void parse(example_sheet& sheet, std::string_view file_name)
{
	//std::fstream stream(file_name.data(), std::ios::in);
	std::cout << "read example sheet" << std::endl;

}

void parse(example_vec& vec, std::string_view file_name)
{
	std::cout << "read example vec" << std::endl;
}

template<typename T>
T makeParse(std::string_view file_name)
{
	T data;
	::parse(data, file_name);
	return data;
}
#endif