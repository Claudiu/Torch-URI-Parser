#include <uriparser.hpp>

int Torch::URI::toInt(std::string what) {
	int rez = 0; bool negative = false;

	if(!(what.length() > 0))
		return -1;

	short maxsize = 10;
	
	if(what[0] == '-')
		maxsize++;
	
	if(what.length() > maxsize)
		return -1;

	for(int poz = 0; poz < what.length(); poz++) {
		if(what.at(poz) == '-' && poz == 0) { 
			negative = true;
			continue;
		}

		if(what.at(poz) >= '0' && what.at(poz) <= '9')
			rez = rez * 10 + (what.at(poz) - '0');
		else {
			return -1;
		}
	}

	return negative ? (rez * -1) : rez;
}

std::string Torch::URI::toLowerCase(std::string what) {
	std::string temp = ""; 
	for(std::string::size_type i=0; i < what.length(); i++)
		temp += std::tolower(what[i]);

	return temp;
}

std::string Torch::URI::get(std::string what) {
	return this->Params[what];
}

int Torch::URI::getNumber(std::string what) {
	return toInt(this->get(what));
}

bool Torch::URI::getBool(std::string what) {
	if(this->Params[what] == "1" || toLowerCase(this->Params[what]) == "true") {
		return true;
	} else { 
		return false;
	}
}

std::pair<std::string, std::string> Torch::URI::parsePair(std::string query) {
	std::string b = query.substr(query.find("=") + 1);

	#ifndef PARSER_CASE_SENSITIVE
		std::string a = toLowerCase(query.substr(0, query.find("=")));
	#else
		std::string a = query.substr(0, query.find("="));
	#endif

	if(b == a)
		b = "";

	return std::pair<std::string, std::string>(a, b);	
}

Torch::URI* Torch::URI::parseQuery(std::string query) {
		path = query.substr(0, query.find("?"));

		if(query.find("?") != std::string::npos)
			query.erase(0, query.find("?") + 1);


		size_t n = 0;
		std::string token;
		while((n = query.find("&")) != std::string::npos) {
			Params.insert(this->parsePair(query.substr(0, n)));
			query.erase(0, n + 1);
		}

		if(query.length() > 0)
			Params.insert(this->parsePair(query));

		return this;
}

Torch::URI::URI() : port(80), protocol("http") {}

Torch::URI::URI(std::string input) : port(80), protocol("http") {
	size_t i = 0; size_t pos = 0; std::string temp;
	while(i < input.length()) {
		if(i == 0) {
			if(input.at(0) != '/') {
				pos = input.find_first_of("://");
				protocol = input.substr(i, pos);
				i += pos + 3;
			} else {
				protocol = "N/A";
				i += pos + 2;
			}

		} else {
			pos = input.find("/", i);
			std::string hostline = input.substr(i, pos - i);

			temp = "";
			if(hostline.find("@") != std::string::npos) {
				temp = hostline.substr(0, hostline.find("@"));
				
				if(temp.find(":") != std::string::npos) {
					username = temp.substr(0, temp.find(":"));
					password = temp.substr(temp.find(":") + 1);
				} else {
					username = temp.substr(0, temp.find(":"));
					password = "";
				}
			
				host = hostline.substr(temp.length() + 1);
				
				if(host.find(":") != std::string::npos) {
					port = toInt(host.substr(host.find(":") + 1));
					host = host.substr(0, host.find(":"));
				}

				this->parseQuery(input.substr(pos + 1));
			} else {

				host = hostline;				
				if(host.find(":") != std::string::npos) {
					port = this->toInt(host.substr(host.find(":") + 1));
					host = host.substr(0, host.find(":"));
				}
				
				//TODO: Implement RFC3986 Fragments
				this->parseQuery(input.substr(pos + 1));
			}
								
			break;
		}
	}
}

