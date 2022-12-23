/*
 * Vulkan hardware capability viewer command line version
 *
 * Copyright (C) 2022 by Sascha Willems (www.saschawillems.de)
 *
 * This code is free software, you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License version 3 as published by the Free Software Foundation.
 *
 * Please review the following information to ensure the GNU Lesser
 * General Public License version 3 requirements will be met:
 * http://opensource.org/licenses/lgpl-3.0.html
 *
 * The code is distributed WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU LGPL 3.0 for more details.
 *
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>
#include <assert.h>

class CommandLineParser
{
public:
	struct CommandLineOption {
		std::vector<std::string> commands;
		std::string value;
		bool hasValue = false;
		std::string help;
		bool set = false;
	};
	std::unordered_map<std::string, CommandLineOption> options;
	
	void add(std::string name, std::vector<std::string> commands, bool hasValue, std::string help) {
		options[name].commands = commands;
		options[name].help = help;
		options[name].set = false;
		options[name].hasValue = hasValue;
		options[name].value = "";
	}
	
	void printHelp() {
		std::cout << "Available command line options:\n";
		for (auto option : options) {
			std::cout << " ";
			for (size_t i = 0; i < option.second.commands.size(); i++) {
				std::cout << option.second.commands[i];
				if (i < option.second.commands.size() - 1) {
					std::cout << ", ";
				}
			}
			std::cout << ": " << option.second.help << "\n";
		}
		std::cout << "Press any key to close...";
	}

	void parse(int argc, char* argv[]) {
		bool printHelp = false;
		// Known arguments
		for (auto& option : options) {
			for (auto& command : option.second.commands) {
				for (int i = 0; i < argc; i++) {
					if (strcmp(argv[i], command.c_str()) == 0) {
						option.second.set = true;
						// Get value
						if (option.second.hasValue) {
							if (argc > i + 1) {
								option.second.value = argv[i + 1];
							}
							if (option.second.value == "") {
								printHelp = true;
								break;
							}
						}
					}
				}
			}
		}
	}

	bool isSet(std::string name) {
		return ((options.find(name) != options.end()) && options[name].set);
	}

	std::string getValueAsString(std::string name, std::string defaultValue) {
		assert(options.find(name) != options.end());
		std::string value = options[name].value;
		return (value != "") ? value : defaultValue;
	}

	int32_t getValueAsInt(std::string name, int32_t defaultValue) {
		assert(options.find(name) != options.end());
		std::string value = options[name].value;
		if (value != "") {
			char* numConvPtr;
			int32_t intVal = strtol(value.c_str(), &numConvPtr, 10);
			return (intVal > 0) ? intVal : defaultValue;
		}
		else {
			return defaultValue;
		}
		return int32_t();
	}

};