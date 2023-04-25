class contact
{
private:
    char    fname[10];
    char    lname[10];
    char    nick[10];
    char    num[10];
    char    secret[10];
    /* data */
public:
    contact(/* args */);
    ~contact();
};

class phonebook
{
private:
    contact contactlist[7];
    int     index;
    /* data */
public:
    phonebook(/* args */);
    ~phonebook();
    void    add(contact);
    void    search(char *name);
    void    exit();
};
