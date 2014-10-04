#include <iostream>
#include <torch/uriparser.hpp>

int main (int argc, char ** argv) {
	const char * a[] = {
		"http://google.ro",
		"http://localhost:50/index.php?da=1&no=hello world",
		"://admin:lol@nasa.gov/index.php?no=32131231"
	};
	
	for(int i = 0; i < 3; i++) {
		std::cout << "URL is " << a[i] << std::endl;
		Torch::URI* Parsed = new Torch::URI(a[i]);
		std::cout << "The port is: " << Parsed->port << std::endl;
		std::cout << "The hostname is: " << Parsed->host << std::endl;
		std::cout << "The username is: " << Parsed->username << std::endl;
		std::cout << "The password is: " << Parsed->password << std::endl;
		std::cout << "The path is: " << Parsed->path << std::endl;
		std::cout << "The value of 'no' is:" << Parsed->get("no") << std::endl << std::endl;
		delete Parsed;
	}

	return 0;
}
