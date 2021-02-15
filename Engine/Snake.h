#pragma once
#include "Board.h"


class Snake {
private: 
	class Segment 
	{
	public: 
		void initHead(const Location& in_loc);
		void initBody();
		void follow(const Segment& next);
		void draw(Board& brd) const;
		void moveBy(const Location& deltaLoc);
	private: 
		Location loc;
		Color c;
	};

public:
	Snake(const Location& loc);
	void moveBy(const Location& deltaLoc);
	void grow();
	void draw(Board& brd) const;

private: 
	static constexpr Color headColor = Colors::Blue;
	static constexpr Color bodyColor = Colors::Cyan;
	static constexpr int segmentMax = 100;
	Segment seg[segmentMax];
	int nSegments = 1;


};