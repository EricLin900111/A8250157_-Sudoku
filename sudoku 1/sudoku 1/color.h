#ifndef SUDOKU_COLOR_H
#define SUDOKU_COLOR_H

#include <iostream>

namespace Color
{
	enum Code
	{
		Bold = 1,
		Reset = 0,
		BG_Default = 49,		
		BG_RED = 41,
		BG_Green = 42,
		BG_Blue = 44,
		FG_Black = 30,
		FG_Blue = 34,
		FG_Cyan = 36,
		FG_Dark_Gray = 90,
		FG_Default = 39,
		FG_Green = 32,
		FG_Light_Blue = 94,
		FG_Light_Cyan = 96,
		FG_Light_Gray = 37,
		FG_Light_Green = 92,
		FG_Light_Magenta = 95,
		FG_Light_Red = 91,
		FG_Light_Yellow = 93,
		FG_Magenta = 35,
		FG_Red = 31,
		FG_White = 97,
		FG_Yellow = 33,
	};

	class Modifier
	{
		Code code;

	public:
		Modifier(Code pcode) {};
		friend std::ostream &
			operator<<(std::ostream &os, const Modifier &mod)
		{
			return os << "\033[" << mod.code << "m";
		}
	};
} // namespace Color

#endif
/*
\033[0m   �����Ҧ��ݩ�
\033[1m   �]�w���G��
\033[4m   �U���u
\033[5m   �{�{
\033[7m   ����
\033[8m   ����
\033[30m   �X   \033[37m   �]�w�e����
\033[40m   �X   \033[47m   �]�w�I����
\033[nA   ��ФW��n��
\033[nB   ��ФU��n��
\033[nC   ��Хk��n��
\033[nD   ��Х���n��
\033[y;xH �]�w��Ц�m
\033[2J   �M��
\033[K   �M���q��Ш��������e
\033[s   �x�s��Ц�m
\033[u   ��_��Ц�m
\033[?25l   ���ô��
\033[?25h   ��ܴ��

\033[2J\033[0;0H  �M�̥B�N��иm��
*/