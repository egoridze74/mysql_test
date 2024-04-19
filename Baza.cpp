#include <iostream>
#include <string>
#include<mysql.h>

void print_table(MYSQL* conn) {
	MYSQL_RES* res;
	MYSQL_ROW row = NULL;
	std::string query = "SELECT * FROM test";
	int qstate = mysql_query(conn, query.c_str());
	if (!qstate)
	{
		res = mysql_store_result(conn);
		while (row = mysql_fetch_row(res))
		{
			std::cout << "ID: " << row[0] << std::endl << "Name: " << row[1] << std::endl << "Number: " << row[2] << std::endl << "Email: " << row[3] << std::endl;
		}
	}
}


int main() 
{
	MYSQL* conn;
	conn = mysql_init(NULL);
	if (conn == NULL)
	{
		// Если дескриптор не получен – выводим сообщение об ошибке
		fprintf(stderr, "Error: can't create MySQL-descriptor\n");
	}

	conn = mysql_real_connect(conn, "localhost", "root", "Rjhyttyrj2005", "test", 3306, NULL, 0);

	if (conn) 
	{
		std::cout << "Successful connetion to database!" << std::endl << std::endl;
		std::cout << "Table before:" << std::endl;
		print_table(conn);

		/*std::string name, email;
		long long number;
		int id;
		std::cin >> id >> name >> number >> email;*/
		std::string query = "INSERT INTO test (id, name, number, email) VALUES (2, \"Nester\", 777, \"legenda@mail.ru\")";
		int qstate = mysql_query(conn, query.c_str());
		if (qstate)
		{
			std::cout << mysql_error(conn) << std::endl;
		}
		else
		{
			std::cout << "Data inserted." << std::endl << std::endl;
		}

		std::cout << "Table after:" << std::endl;
		print_table(conn);
	}
	else
	{
		std::cout << "Connection to databse failed." << std::endl;
	}
	mysql_close(conn);
	return 0;
}