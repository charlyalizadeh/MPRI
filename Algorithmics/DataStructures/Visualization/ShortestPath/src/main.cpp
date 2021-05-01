#define OLC_PGE_APPLICATION
#include "../inc/Engine.hpp"

int main()
{
	Engine demo({20, 20});
	if(demo.Construct(600, 600, 2, 2))
		demo.Start();
	return 0;
}
