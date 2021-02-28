//X= 9 + n, Y= 10 + n, Z= 11 + n, S= 1.0 + n, где n(8) - порядковый номер студента по списку. 

#include <iostream>
#include <conio.h>

void example_function();

int main()
{
	double D;
	double DD;
	bool _false_ = false;
	bool _true_ = 45454536413412;
	char R= 'R';  //ASCII
	char O = 'О'; //руская буква ASCII (win 1251)
	wchar_t L= L'Л'; // UNICOD(UTF-16)
	wchar_t E = L'Q'; //UNICOD (UTF-16)

	short X=17, _X=-17;   //X=9+8=17(10) 11(16)    -X=-17(10) 0xffef(16)
	short short_MAX16 = 0x7FFF;              //2 байта  32767(10)
	short short_MIN16 = 0x8000;              //	       -32768(10)
	unsigned short short_UMAX16 = 0xFFFF;    //        65 535(10)
	unsigned short short_UMIN16 = 0x0;       //        0(0)

	int Y=18, _Y=-18;      //Y=10+8=18(10) 12(16)    -Y=-18(10) 0xffffffee(16)   
	int int_MAX16 = 0x7FFFFFFF;           //4 байта   2 147 483 647(10)
	int int_MIN16 = 80000000;            //         -2 147 483 648(10)
	unsigned int int_UMAX16 = 0xFFFFFFFF; //          4 294 967 295(10)
	unsigned int int_UMIN16 = 0;          //                       0(0)

	long Z=19, _Z=-19;      //Z=11+8=19(10) 13(16)    -Y=-19(10) 0xffffffed(16) 
	long long_MAX16 = 0x7FFFFFFFFFFFFFFF;           //4 байта   9 223 372 036 854 775 807(10)
	long long_MIN16 = 0x8000000000000000;           //         -9 223 372 036 854 775 808(10)
	unsigned long long_UMAX16 = 0xFFFFFFFFFFFFFFFF; //         18 446 744 073 709 551 615(10)
	unsigned long long_UMIN16 = 0x0;                //                                   0(0)

	float S=9, _S=-9;    //S=1.0+8=9.000(10) 41100000(16)    -S=-9.000(10)  C1100000(16) 

	char *Pchar =  &R;
	wchar_t *Pwchar_t = &L;
	short *Pshort = &X;
	int *Pint = &Y;
	float *Pfloat = &S;
	double *Pdouble = &D;

	char &Lchar =O;
	wchar_t &Lwchar_t = E;
	short &Lshort = _X;
	int &Lint = _Y;
	float &Lfloat = _S;
	double &Ldouble = DD;
	

	float f1 = 23.625f;
	float f2 = -23.625f;
	float f3 = f1 / 0;        //1.#INF
	float f4 = f2 / 0;        //-1.#INF
	float f5 = sqrt(-2.0f);   //-1.#IND

	std::cout << "sizeof(int) \t\t" << sizeof(int) << std::endl;
	std::cout << "sizeof(short) \t\t"<<sizeof(short)<<std::endl;
	std::cout << "sizeof(short int) \t"<<sizeof(short int)<<std::endl;
	std::cout << "sizeof(long) \t\t"<<sizeof(long)<<std::endl;
	std::cout << "sizeof(long int) \t"<<sizeof(long int)<<std::endl;
	std::cout << "sizeof(long long) \t" << sizeof(long long) << std::endl;
	std::cout << "sizeof(long long int) \t" << sizeof(long long int) << std::endl;
	std::cout << "sizeof(long double) \t" << sizeof(long double) << std::endl;
	std::cout << "sizeof(double) \t\t" << sizeof( double) << std::endl;
	std::cout << "sizeof(long float) \t" << sizeof(long float) << std::endl;
	std::cout << "sizeof(float) \t\t" << sizeof(float) << std::endl;
	std::cout << "bool \t\t" << _false_ << std::endl;
	std::cout << "bool \t\t" << _true_ << std::endl;
	std::cout << "sizeof(bool) \t\t" << sizeof(bool) << std::endl;
	std::cout << "sizeod(Pchar) \t\t"<<	sizeof(Pchar)<<std::endl;
	std::cout << "sizeod(Pwchar_t) \t"<<sizeof(Pwchar_t)<<std::endl;
	std::cout << "sizeod(Pshort) \t\t"<<	sizeof(Pshort)<<std::endl;
	std::cout << "sizeod(Pint) \t\t" <<	sizeof(Pint)<<std::endl;
	std::cout << "sizeod(Pfloat) \t\t" <<	sizeof(Pfloat)<<std::endl;
	std::cout << "sizeod(Pdouble) \t" <<sizeof(Pdouble)<<std::endl;
	std::cout << "sizeod(Lchar) \t\t" << sizeof(Lchar) << std::endl;
	std::cout << "sizeod(Lwchar_t) \t" << sizeof(Lwchar_t) << std::endl;
	std::cout << "sizeod(Lshort) \t\t" << sizeof(Lshort) << std::endl;
	std::cout << "sizeod(Lint) \t\t" << sizeof(Lint) << std::endl;
	std::cout << "sizeod(Lfloat) \t\t" << sizeof(Lfloat) << std::endl;
	std::cout << "sizeod(Ldouble) \t" << sizeof(Ldouble) << std::endl;

	void(*pointer)();
	pointer = example_function;
	pointer();
	
	_getch();
}

void example_function()
{
	std::cout << "feffef" << std::endl;
}