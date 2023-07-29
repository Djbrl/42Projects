#ifndef Utils_HPP
# define Utils_HPP

# include <string>
# include "_defines.hpp"
// # include "Channel.hpp"

//UTILS CLASS______________________________________________________________________________________________________
//Utils is a static class that provides general-purpose functions

class Utils
{
    public:
		static std::string	getLocalTime();
		static bool			isPrintableStr(const std::string& message);

		//TEMPLATES__________________________________________________________________________________________________
        template <typename T, typename P>
        static void         printMap(std::map<T, P> &map)
        {
            typename std::map<T, P>::iterator it;
            for (it = map.begin(); it != map.end(); ++it)
            {
                std::cout << it->first << " : " << it->second << std::endl;
            }
        }
};

#endif
