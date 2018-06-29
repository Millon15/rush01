#include <main.hpp>

std::string		saveExec( const char *cmd )
{
	std::string		result = "";

	try {
		result = exec(cmd);
	}
	catch(...) {
		result = "ERROR";
	}
	return result;
}

std::string		exec( const char *cmd )
{
	char			buffer[BUFF_SIZE];
	std::string		result = "";
	FILE*			pipe = popen(cmd, "r");

	if ( !pipe ) throw std::runtime_error("popen() failed!");
	try {
		while (!feof(pipe)) {
			if (fgets(buffer, BUFF_SIZE, pipe) != NULL)
				result += buffer;
		}
	}
	catch (...) {
		pclose(pipe);
		throw;
	}
	pclose(pipe);
	return result;
}
