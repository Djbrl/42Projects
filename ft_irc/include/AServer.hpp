#ifndef __ASERVER_HPP__
# define __ASERVER_HPP__

# include "_defines.hpp"
# include "Utils.hpp"

//ASERVER CLASS____________________________________________________________________________________________________
//AServer is a pure abstract class that carries all the exceptions needed for our IRC Server

class AServer
{
    public:
                                    AServer();
                                    virtual ~AServer();
        virtual void				run() = 0;

        //EXCEPTIONS_______________________________________________________________________________________________
        
        class InvalidPortException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Exception: Invalid or occupied port number provided.";
            }
        };

        class SocketCreationException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Exception: Socket creation failed.";
            }
        };

        class BindException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Exception: Bind() failed.";
            }
        };

        class ListenException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Exception: Listen() failed.";
            }
        };

        class AcceptException : public std::exception {
        public:
            virtual const char* what() const throw() {
                return "Exception: Accept() failed.";
            }
        };
};

#endif
