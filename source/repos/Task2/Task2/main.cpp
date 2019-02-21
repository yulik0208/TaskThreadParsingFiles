#include"UniqueVar.h"

int main()
{

	UniqueVar v = 100.1;
	try {
		int a = v.ToInt();
	}
	catch (BadType& obj)
	{
		std::cout << obj.what() << std::endl;
	}
	//v.Print();
	system("pause");
	return 0;

}