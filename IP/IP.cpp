#include <iostream>
#include <string>

using namespace std;



class IP_packet
{
public:
	IP_packet(string source,string appointment) : source(source), appointment(appointment) {
		int first = 0, second = 0;
		try
		{
			check(source, appointment);
			cout << "\nIP packet:\n" << "from->\n";
			for (size_t i = 0; i < 4; i++)
			{
				second = source.find(".", first);
				s_seg[i] = stoi(source.substr(first));
				cout << s_seg[i] << " ";
				first = second + 1;
			}
			cout << "\nto->\n";
			for (size_t i = 0; i < 4; i++)
			{
				second = appointment.find(".", first);
				a_seg[i] = stoi(appointment.substr(first));
				cout << a_seg[i] << " ";
				first = second + 1;
			}
			cout << endl << "is successfully created!\n\n";
		}
		catch (const std::exception& ex)
		{
			cout << ex.what();
		}

	}
	
	void static check(string source, string appointment) {
		int s_seg[4];
		int a_seg[4];
		int first = 0, second = 0;
		bool flag = false;

		if (count(source.begin(), source.end(), '.') != 3)
		{
			throw exception("\nINVALID SOURCE IP FORMAT!\n");
		}

		if (count(appointment.begin(), appointment.end(), '.') != 3)
		{
			throw exception("\nINVALID APPOINTMENT IP FORMAT!\n");
		}

		for (size_t i = 0; i < 4; i++)
		{
			second = source.find(".", first);
			s_seg[i] = stoi(source.substr(first));
			first = second + 1;
		}
		for (size_t i = 0; i < 4; i++)
		{
			second = appointment.find(".", first);
			a_seg[i] = stoi(appointment.substr(first));
			first = second + 1;
		}

		for (size_t i = 0; i < 4; i++)
		{
			if (a_seg[i] > 255) {
				throw out_of_range("\nAPPOINTMENT IP BIT POSITION, OUT OF RANGE!\n");
			}
			if (s_seg[i] > 255) {
				throw out_of_range("\nSOURCE IP BIT POSITION, OUT OF RANGE!\n");
			}
		}
	}

	string source, appointment;
	int s_seg[4];
	int a_seg[4];
};


int main()
{
	IP_packet a("192.164.14.61","192.164.1.2");
	IP_packet b("192164.14.61", "192.164.1.2");
	IP_packet c("192.164.14.61", "192.1164.1.2");

}