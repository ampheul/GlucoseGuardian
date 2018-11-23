/*!
	@author Veronica Witzig
	Purpose: Responsible for displaying the UI menu
*/

#include "Menu.h"

using namespace std;

/*!
	Name: Menu
	Description: constructor
*/
Menu::Menu()
{
};

/*!
	Name: ~Menu
	Description: destructor
*/
Menu::~Menu() {};

Menu::Menu(const std::string &name, const std::string &prompt,
          const std::vector<std::pair<std::string, std::string> > &choices)
: _name(name)
  ,_prompt(prompt)
  , _choices(choices)
{
}

bool Menu::operator==(const std::string &name) const
{
  return name == _name;
}

const std::string& Menu::takeChoice() const
{
  if (_choices.size() == 0)
  {
    std::cout << _prompt;
    return "END";
  }
  unsigned int choice;
  int i;
  do
  {
    std::cout << _prompt;
    i = 1;
    for (auto ch : _choices)
    {
      std::cout << i++ << ": " << ch.first << "\n";
    }
    std::cin >> choice;
    choice--;
  }
  while(choice >= _choices.size());
  return _choices[choice].second;
}

/*!
	Name: getMenuItems
	Description: gets the menu items for the user based on their account type
	@param string senderEmail - sender's email address
	@param string recipientEmail - password for the email account
	@param string emailPassword - recpient's email address
*/
void Menu::getMenuItems(string senderEmail, string recipientEmail, string emailPassword)
{
	cout << "Sending email to: " << recpientEmail << endl;
	string command = "curl --url \'smtps://smtp.gmail.com:465\' --ssl-reqd --mail-from \'" + senderEmail + "\' --mail-rcpt \'" + recipientEmail + "\' --upload-file email.txt --user \'" + senderEmail + ":" + emailPassword + "\'";
	sys(command);	
};
