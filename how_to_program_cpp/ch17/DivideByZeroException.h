// Fig. 17.1: DivideByZeroException.h
// Class DivideByZeroException definition
#include <stdexcept>

// DivideByZeroException objects should be thrown by functions
// upon detecting division-by-zero exceptions
class DivideByZeroException : public std::runtime_error {
  public:
    // constructor specifies default error message
    DivideByZeroException()
        : std::runtime_error("attempted to divide by zero") {}
};
