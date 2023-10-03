#ifndef GENERIC_POINT_H_
#define GENERIC_POINT_H_

template <typename Type>
class Point
{
	public:
		Type x;
		Type y;
		Point(Type x, Type y) : x(x), y(y){}
};

#endif
