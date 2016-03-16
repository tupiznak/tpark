#include <fstream>

int main()
{
int a = 2;
std::ofstream out;
out.open("1to100000.txt");
out << 100000 << " ";
out << 100001 << " ";
for (int i = 99999; i > 0; --i){
	a++;
	out << i << " ";
}
printf("%u",a);
out.close();
}
