#pragma once
class Hall
{
public:
	Hall(int _id = 0 , int _rows = 0, int _SeatsOnRow = 0);
	Hall(const Hall& other);
	Hall& operator=(const Hall& other);
	bool operator==(const Hall& other)const;

	int getId() const { return id; }
	int getRows() const { return rows; }
	int getSeatsOnRow() const { return SeatsOnRow ; }
	int getAllSeats() const { return rows * SeatsOnRow; }
	
	void setId(int _id) { id = _id; };
	

private:

	void copy(const Hall& other);

	int id;
	int rows;
	int SeatsOnRow;
	
};

