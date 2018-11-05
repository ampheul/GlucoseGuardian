public class Contact {
private:
	string name;
	vector<ContactType> contactOptions;

public:
	Person(string name) {
		this.name = name;
	}

	string getName() {
		return name;
	}

	void setName(string name) {
		this.name = name;
	}
};