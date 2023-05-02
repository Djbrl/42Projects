class contactProfile
{
private:
	std::string	fname;
	std::string	lname;
	std::string	nick;
	std::string	num;
	std::string	secret;

public:
	contactProfile();
	~contactProfile();
	void		set_contact();
	std::string get_fname();
	std::string get_lname();
	std::string get_nick();
	std::string get_num();
	std::string get_secret();
};

class phoneBook
{
private:
	contactProfile entry[8];
	int     index;

public:
	phoneBook();
	~phoneBook();
	void    add();
	void    search(std::string name);
};

std::string nosignal_getline();