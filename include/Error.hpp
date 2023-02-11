#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>
#include <exception>

class Error : public std::exception {
    private:
        std::string _msg;
    public:
        Error(std::string const &message) : _msg(message){};
        const char *what() const noexcept override { return _msg.c_str(); };
};

class FatalError : public Error {
    public:
        FatalError(std::string const &message) : Error(message) {};
};

class ConnectionError : public FatalError
{
    public:
        ConnectionError(std::string const &message) : FatalError(message) {};
};

class ArgError : public FatalError
{
    public:
        ArgError(std::string const &message) : FatalError(message) {};
};

class GraphicalError : public FatalError
{
    public:
        GraphicalError(std::string const &message) : FatalError(message) {};
};

#endif /* !ERROR_HPP_ */
