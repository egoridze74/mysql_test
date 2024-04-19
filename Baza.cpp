#include <iostream>
#include <string>
#include<mysql.h>

void print_table(MYSQL* conn) {
	MYSQL_RES* res;
	MYSQL_ROW row = NULL;
	std::string query = "SELECT * FROM test";
	const char* q = query.c_str();
	int qstate = mysql_query(conn, q);
	if (!qstate)
	{
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			std::cout << "ID: " << row[0] << std::endl << "Name: " << row[1] << std::endl << "Number: " << row[2] << std::endl << "Email: " << row[3] << std::endl;
		}
	}
}


class Teacher
{
private:
	std::string name;
	long long number = 89772585877;
	std::string email;
public:
	Teacher() {
		name = "-";
		number = 0;
		email = "-";
	};

	Teacher(std::string new_name, long long new_number, std::string new_email) {
		name = new_name;
		number = new_number;
		email = new_email;
	}
};

int main() 
{
	MYSQL* conn;
	conn = mysql_init(NULL);
	if (conn == NULL)
	{
		// Если дескриптор не получен – выводим сообщение об ошибке
		fprintf(stderr, "Error: can'tcreate MySQL-descriptor\n");
	}

	conn = mysql_real_connect(conn, "localhost", "root", "Rjhyttyrj2005", "test", 3306, NULL, 0);

	if (conn) 
	{
		std::cout << "Successful connetion to database!" << std::endl;
		print_table(conn);
	}
	else
	{
		std::cout << "Connection to databse failed." << std::endl;
	}
	return 0;
}