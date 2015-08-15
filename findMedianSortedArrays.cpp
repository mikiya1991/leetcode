#include "stdafx.h"
#include <math.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	
	int *p1head, *p1end;
	int *p2head, *p2end;
	int length1, length2;
	double med1, med2;
	int med1i1, med1i2;
	int med2i1, med2i2;
	//let p1 is longer
	if (nums1Size > nums2Size)
	{
		p1head = nums1;
		p2head = nums2;
		p1end = nums1 + nums1Size - 1;
		p2end = nums2 + nums2Size - 1;
		length1 = nums1Size;
		length2 = nums2Size;
	}
	else
	{
		p2head = nums1;
		p1head = nums2;
		p2end = nums1 + nums1Size - 1;
		p1end = nums2 + nums2Size - 1;
		length2 = nums1Size;
		length1 = nums2Size;
	}
	while (1)
	{
		length1 = p1end - p1head + 1;
		length2 = p2end - p2head + 1;
		med1i1 = floor((length1+1) / 2.0);
		med1i2 = ceil((length1 + 1) / 2.0);
		med2i1 = floor((length2 + 1) / 2.0);
		med2i2 = ceil((length2 + 1) / 2.0);
		med1 = (*(p1head + med1i1 - 1) + *(p1head + med1i2 - 1)) / 2.0;
		med2 = (*(p2head + med2i1 - 1) + *(p2head + med2i2 - 1)) / 2.0;

		if (length2 == 0) return med1;
		if (length1 == 1 && length2 == 1)
		{
			return (*p1head + *p2head) / 2.0;
		}
		if (length2 == 1)
		{

			if (med1i1 != med1i2)
			{
				int a1 = *(p1head + med1i1 - 1), a2 = *(p1head + med1i2 - 1);
				int b = *p2head;
				if (a1 <= b && b <= a2) return b;
				if (b <= a1) return a1;
				if (b >= a2) return a2;
			}
			else
			{
				int a1 = *(p1head + med1i1 - 2), a2 = *(p1head + med1i1 - 1), a3 = *(p1head + med1i1);
				int b = *p2head;
				if (b >= a1 && b <= a3) return (b + a2) / 2.0;
				if (b <= a1) return (a1 + a2) / 2.0;
				else return (a2 + a3) / 2.0;

			}
		}
		if (length2 == 2)
		{
			if (med1i1 != med1i2)
			{
				int a1 = *p2head, a2 = *(p2head + 1);
				int b1 = *(p1head + med1i1 - 1), b2 = *(p1head + med1i2 - 1);
				if (a1 >= b1 && a2 <= b2) return (a1 + a2) / 2.0;
				if (a1<=b1 && a2>=b2) return (b1 + b2) / 2.0;
				if (b1 <= a2 && a2 <= b2) return (b1 + a2) / 2.0;
				if (a1 >= b1 && a1 <= b2) return (a1 + b2) / 2.0;
				if (a2 < b1)
				{
					p2head++;
					p1end--;
				}
				if (a1 > b2)
				{
					p2end--;
					p1head++;
				}
				continue;
			}
			else
			{
				int a1 = *p2head, a2 = *(p2head + 1);
				int b1 = *(p1head + med1i1 - 1);
				if (a1 <= b1 && b1 <= a2) return b1;
				if (a2 < b1)
				{
					p2head++;
					p1end--;
				}
				if (a1 > b1)
				{
					p2end--;
					p1head++;
				}
				continue;
			}
		}

		if (med1 == med2) return med1;
		if (med1 <= med2)
		{
				int t = med2i1-1;
				p1head += t;
				p2end -= t;
		}
		else
		{
				int t = med2i1-1;
				p2head += t;
				p1end -= t;
		}

	}

}
int main()
{
	int a[] = {1,1};
	int b[] = {1,2};
	int c;
	cout << findMedianSortedArrays(a, 2, b, 2);
	cin >> c;
}