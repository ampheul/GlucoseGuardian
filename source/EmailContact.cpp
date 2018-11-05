public class EmailContact {
private:
	string email;

public:
	void notify() {
		printf("Emergency Contact! This is an email saying your patient requires your help!");
	}

	string getEmail() {
		return email;
	}

	void setEmail(string givenEmail) {
		email = givenEmail;
	}
};