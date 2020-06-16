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
\033[0m   關閉所有屬性
\033[1m   設定高亮度
\033[4m   下劃線
\033[5m   閃爍
\033[7m   反顯
\033[8m   消隱
\033[30m   —   \033[37m   設定前景色
\033[40m   —   \033[47m   設定背景色
\033[nA   游標上移n行
\033[nB   游標下移n行
\033[nC   游標右移n行
\033[nD   游標左移n行
\033[y;xH 設定游標位置
\033[2J   清屏
\033[K   清除從游標到行尾的內容
\033[s   儲存游標位置
\033[u   恢復游標位置
\033[?25l   隱藏游標
\033[?25h   顯示游標

\033[2J\033[0;0H  清屏且將游標置頂
*/