#ifndef HALL_H
#define HALL_H

#pragma once
class Hall
{
public:
	Hall(int _id = 0 , int _rows = 0, int _SeatsOnRow = 0);
	Hall(const Hall& other);
	Hall& operator=(const Hall& other);

	int getId() const { return id; }
	int getRows() const { return rows; }
	int getSeatsOnRow() const { return SeatsOnRow ; }
	int getAllSeats() const { return rows * SeatsOnRow - rows - SeatsOnRow + 1; }
	
	void setId(int _id) { id = _id; };
	

private:

	void copy(const Hall& other);

	int id;
	int rows;
	int SeatsOnRow;
	
};

#endif