#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

class Solution
{
public:
	int numUniqueEmails(std::vector<std::string>& emails)
	{
		std::unordered_set<std::string> uniqueEmails;

		for (auto& e : emails)
		{
			std::string email;
			email.reserve(e.size());

			int i = 0;
			while (i < e.size())
			{
				if (e[i] == '@') break;
				if (e[i] == '+')
				{
					while (i < e.size() && e[i] != '@') i++;
					break;
				}
				else if (e[i] != '.')
					email += e[i];
				i++;
			}
			email += e.substr(i);
			uniqueEmails.insert(std::move(email));
		}
		return uniqueEmails.size();
	}
};

void printEmails(const std::vector<std::string>& emails)
{
	std::cout << "{";
	for (int i = 0; i < emails.size(); i++)
	{
		std::cout << emails[i];
		if (i < emails.size() - 1)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	std::vector<std::vector<std::string>> tests = {
			{"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"},
			{"a@leetcode.com","b@leetcode.com","c@leetcode.com"},
		};

	for (auto& emails : tests)
	{
		std::cout << "---\nemails: ";
		printEmails(emails);
		std::cout << "\nNumUniqueEmails: " << Solution().numUniqueEmails(emails);
		std::cout << std::endl;
	}
	return 0;
}
