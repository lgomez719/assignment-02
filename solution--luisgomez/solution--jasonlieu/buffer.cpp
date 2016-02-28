/* ----------------------------------------------------------------------------
* Copyright &copy; 2016 Jason Lieu <jasonlieu@csu.fullerton.edu>
* Copyright &copy; 2016 Luis Gomez <lgomez420@csu.fullerton.edu>
* Released under the [MIT License] (http://opensource.org/licenses/MIT)
* ------------------------------------------------------------------------- */

/**
* Implements `buffer.h`.
*/

// TODO: `#include`s for system headers, if necessary

#include <iostream>
using std::cout;
using std::endl;
// TODO: `#include`s for other local headers, if necessary

// ----------------------------------------------------------------------------

// TODO: implementations for all functions in `class Buffer`

// ----------------------------------------------------------------------------
#include "Buffer.h"
#include <string>

// ----------------------------------------------------------------------------


Buffer::Buffer(unsigned int size_x, unsigned int size_y) : size_x(size_x), size_y(size_y)
{
	data_ = new char[size_x * size_y];
	for (unsigned int i = 0; i < size_x * size_y; i++)
	{
		data_[i] = ' ';
	}
}

Buffer::~Buffer()
{
	delete[] data_;
}
char Buffer::get(unsigned int x, unsigned int y) const
{

	if (x > size_x - 1 || y > size_y - 1)
	{
		cout << "ERROR: 'Buffer::get': index out of bounds" << endl;
		exit(1);
	}

	return data_[y * size_x + x];
}
void Buffer::set(unsigned int x, unsigned int y, char c)
{
	data_[y * size_x + x] = c;

	if (x > size_x - 1 || y > size_y - 1)
	{
		cout << "ERROR: 'Buffer::get': index out of bounds" << endl;
		system("pause");
	}
}
void Buffer::set(unsigned int pos_x, unsigned int pos_y, std::string s)
{
	for (unsigned int i = 0, x = pos_x, y = pos_y; i < s.length(); i++) {
		if (s[i] == '\n') {
			y++;
			x = pos_x;
		}
		else {
			set(x++, y, s[i]);
		}
	}
}
void Buffer::draw() const
{
	for (unsigned int i = 0; i < size_x * size_y; i++)
	{
		cout << data_[i];
	}

}
void Buffer::clear()
{
	for (unsigned int i = 0; i < size_x * size_y; i++)
	{
		data_[i] = ' ';
	}
}

