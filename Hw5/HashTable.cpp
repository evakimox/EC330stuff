#include "HashTable.h"

//declare functions used in SpellCheck
bool findstring(string inputword);
bool findbyreplace(string inputword);
bool findbyswap(string inputword);
bool findbyinsert(string inputword);
bool findbydelete(string inputword);

void SpellCheck(string inputword)
{
  cout<<"Spell checking . . . \n";
  bool flagfound = 1;
  if(findstring(inputword))
  {
    flagnotfound = 0;
    cout<<inputword;
    return;
  }
  else
  {
    flagfound = (findbyreplace(inputword)
		     ||findbyswap(inputword)
		     ||findbyinsert(inputword)
		     ||findbydelete(inputword)
		     );

    if(!flagfound)
    {
      cout<<"no matches found!\n";
    }
  }
}
