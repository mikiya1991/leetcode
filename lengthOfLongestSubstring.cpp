#include <string.h>
#include "stdafx.h"

int FindLongestSub(char* phead, char*pend)
{
	if ((phead+1) == pend) return 1;
	//more than 2 chars
	char tmp;
	tmp = *pend;
	*pend = '\0';
	char* p = phead;
	for (; p < pend-1; p++)
	{
		char* prep = strchr(p + 1, *p);
		if (prep != NULL)
		{
			int t1, t2;
			t1 = FindLongestSub(phead, prep);
			t2 = FindLongestSub(p+1, pend);
			*pend = tmp;
			return t1 > t2 ? t1 : t2;
		}
	}
	*pend = tmp;
	return (pend - phead);
}
int lengthOfLongestSubstring(char* s) {
	return FindLongestSub(s, s + strlen(s));
}

//int main()
//{
//	char test[] = "abcdefghijka";
//	cout << lengthOfLongestSubstring(test);
//	int b;
//	cin >> b;
//}