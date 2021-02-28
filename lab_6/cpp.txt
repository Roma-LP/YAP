#include <iostream>
#include <conio.h>

typedef unsigned char  day;   // день
typedef unsigned char  month; // мес€ц
typedef unsigned short year;  // год

#define str 20

struct Date //дата
{
	day dd;
	month mm;
	year yyyy;
}; 

bool operator < (Date x, Date y)
{
	return (x.yyyy < y.yyyy || (x.yyyy == y.yyyy && x.mm < y.mm) || (x.yyyy == y.yyyy && x.mm == y.mm && x.dd < y.dd));
}

bool operator > (Date x, Date y)
{
	return (x.yyyy > y.yyyy || (x.yyyy == y.yyyy && x.mm > y.mm) || (x.yyyy == y.yyyy && x.mm == y.mm && x.dd > y.dd));
}

bool operator == (Date x, Date y)
{
	return (x.yyyy == y.yyyy  && x.mm == y.mm && x.dd == y.dd);
}

//--------------------------------------------------------------------------------------------------------------------


struct variable
{
	char type[str]; // тип
	char ind[str];  // идентификатор
	int value; // значение
};

variable operator ++ (variable x)
{
	x.value++;
	return (x);
}

variable operator -- (variable x)
{
	x.value--;
	return (x);
}

int main()
{
	setlocale(LC_ALL, "rus");

	Date date1 = {7,1,1980};
	Date date2 = {7,2,1993};
	Date date3 = {7,1,1980};

	if (date1 < date2) std::cout << "истина" << std::endl;
	else std::cout << "ложь" << std::endl;

	if (date1 > date2) std::cout << "истина" << std::endl;
	else std::cout << "ложь" << std::endl;

	if (date1 == date2) std::cout << "истина" << std::endl;
	else std::cout << "ложь" << std::endl;

	if (date1 == date3) std::cout << "истина" << std::endl;
	else std::cout << "ложь" << std::endl;

	//----------------------------------------------------------------------------------------

	variable var1 = { "int","v1", 3 };
	variable var2 = { "int","v2", 4 };
	variable var3 = { "int","v3", 5 };

	std::cout << "\nvar1.value = " << var1.value <<" ++"<< std::endl;
	var1.value++;
	std::cout << "var1.value = " << var1.value << std::endl<<std::endl;

	std::cout << "var2.value = " << var2.value  << " ++" << std::endl;
	var2.value++;
	std::cout << "var2.value = " << var2.value << std::endl << std::endl;

	std::cout << "var3.value = " << var3.value  << " --" << std::endl;
	var3.value--;
	std::cout << "var3.value = " << var3.value << std::endl << std::endl;

	_getch();

}

