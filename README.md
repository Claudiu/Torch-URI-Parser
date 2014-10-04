[![Build Status](https://travis-ci.org/Claudiu/Torch-URI-Parser.svg?branch=master)](https://travis-ci.org/Claudiu/Torch-URI-Parser)

This URI parser was created for the Torch HTTP Framework, but it can be used as a single entity for your own projects.

! How do I use it?
Here is a simple example on how to use this library. It should simply extract the filepath from a given URL.
```cpp
Torch::URI* Parsed = new Torch::URI("your_url_string_goes_here");
std::cout << Parsed -> path;
delete Parsed;
```

!! Extracting Params
You can extract a GET Request param using one of the following commands:
```cpp
Parsed -> get("name of the field");
```
