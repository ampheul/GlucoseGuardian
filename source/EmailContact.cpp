#include <string>
#include <io>

class EmailContact {
private:
	std::string email;

public:
	void notify() {
		std::cout << "Emergency Contact! This is an email saying your patient requires your help!";
	}

	std::string getEmail() {
		return email;
	}

	void setEmail(std::string givenEmail) {
		email = givenEmail;
	}
};