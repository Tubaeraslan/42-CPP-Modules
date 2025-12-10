/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teraslan <teraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:34:08 by teraslan          #+#    #+#             */
/*   Updated: 2025/09/27 17:34:09 by teraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

static int open_file(std::string name_input,std::string name_output,
    std::ifstream *input_file,std::ofstream *output_file)
    {
        (*input_file).open(name_input.std::string::c_str(),std::fstream::in);
		if (!(*input_file))
		{
			(*input_file).close();
			return -1;
		}
        (*output_file).open(name_output.std::string::c_str(),std::fstream::out);
        if (!(*output_file))
        {
            (*output_file).close();
            return -1;
        }
        return 0;
    }

static void replace_function(char **argv,std::ifstream *input_file,std::ofstream *output_file)
{
    std::string content;
	std::string line;
	while (std::getline(*input_file,line))
	{
		content = content + line;
		content = content + '\n';
	}
	
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	size_t pos = 0;

	while ((pos = content.std::string::find(s1,pos)) != std::string::npos)
	{
		content.std::string::erase(pos,s1.std::string::length());
		content.std::string::insert(pos,s2);
		pos = pos + s2.std::string::length();
	}
	
	*output_file << content;
}

int main(int argc, char **argv)
{
    std::string name_input;
    std::string name_output;;
    std::ifstream input_file;
    std::ofstream output_file;

	if (argc != 4)
    {
        std::cout << "Wrong number of arguments" << std::endl;
        return 1;
    }
	if (std::string(argv[2]).empty() || std::string(argv[3]).empty())
	{
    	std::cout << "S1 or S2 cannot be empty" << std::endl;
    	return 1;
	}
    name_input = argv[1];
    name_output = std::string(argv[1]) + ".replace";
    if (open_file(name_input,name_output,&input_file,&output_file) == -1)
    {
        std::cout << "Error open file" << std::endl;
        return 1;
    }
    replace_function(argv,&input_file,&output_file);
    input_file.close();
    output_file.close();
    return 0;
}
