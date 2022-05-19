// Unknown resource class definition

#include "../lib/UnknownResource.hpp"
using namespace std::string_literals;


UnknownResource::UnknownResource(const std::string& path): errorMessage("Error, cannot find resource: " + path) {}

const char* UnknownResource::what() const noexcept {
    return errorMessage.c_str();
}
