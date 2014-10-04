#ifndef __TORCH_URI_PARSER__
#define __TORCH_URI_PARSER__

#include <iostream>
#include <string>
#include <map>

namespace Torch {
	class URI { 
		protected: 
			std::map <std::string, std::string> Params;
		public:
			std::string protocol, username, password, host, path;
			int port;

			// Helper functions
			int toInt(std::string);
			std::string toLowerCase(std::string);

			std::string get(std::string);
			int getNumber(std::string);
			bool getBool(std::string);

			Torch::URI* parseQuery(std::string);
			std::pair<std::string, std::string> parsePair(std::string);
			void parseHostLine(std::string);

			URI();
			URI(std::string);
	};
}


#endif
