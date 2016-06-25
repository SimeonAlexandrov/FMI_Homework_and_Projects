#include "Algae.h"
void Algae::BeingRainedOn()
{
	int newCapacity = GetCapacity() / 2;
	SetCapacity(newCapacity);
}

/*bool Algae::CheckIfInWater()
{
if(CheckIfPointIsInWater(m_coords) == true)
{
return true;
}
else
{
return false;
}
}
*/
