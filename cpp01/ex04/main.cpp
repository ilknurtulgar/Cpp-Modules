/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itulgar <itulgar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 18:56:21 by itulgar           #+#    #+#             */
/*   Updated: 2025/02/25 15:20:52 by itulgar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

bool is_s1(std::string filename,std::string s1)
{
	std::ifstream file(filename.c_str());
	std::string line;
	while(std::getline(file,line))
	{
		size_t found = line.find(s1);
		if(found != std::string::npos)
			return file.close(),true;
	}
	file.close();
	return std::cout << "s1 not found in file! 🦭" << std::endl,false;
}

int replace_std(std::string filename, std::string s1, std::string s2)
{
	if(is_s1(filename,s1))
	{
		std::string repStr = filename + ".replace";
		std::ofstream fileReplace(repStr.c_str());
		std::ifstream file(filename.c_str());
		std::string line;

		while(std::getline(file,line))
		{
			size_t found = line.find(s1);
			
			while(found != std::string::npos)
			{
				
				std::string before = line.substr(0,found);
				std::string after = line.substr(found + s1.length());
				line = before + s2 + after;
				found = line.find(s1,found+s2.length());
			}
			fileReplace << line << std::endl;
		}
		fileReplace.close();
		file.close();
		return 1;
	}
	else	
		return 0;
}

int file_check(std::string filename)
{
	if(filename[0] == '.')
		return std::cout << "Hidden file error! 🦭" << std::endl,0;
	std::ifstream file(filename.c_str());
	if(file.is_open())
	{
		std::string line;
	
		if(!std::getline(file,line))
			return std::cout << "File is empty! 🦭" << std::endl,0;
		return file.close(),1;
	}
	return std::cout << "File error! 🦭" << std::endl,0;
}

int main(int argc,char **argv)
{
	if(argc != 4)
		std::cout << "Invalid argument! 🦭" << std::endl;
	else
	{
		std::string filename = argv[1];
		if(!file_check(filename))
			return 0;
 		std::string s1 = argv[2];
		std::string s2 = argv[3];
		if(filename.empty() || s1.empty() || s2.empty())
			return std::cout << "Any argument cannot be empty! 🦭" << std::endl,0;
		if(!replace_std(filename,s1,s2))
			return 0;
	}
}