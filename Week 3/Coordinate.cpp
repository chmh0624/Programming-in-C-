class Coordinate
{
	
	public:
		Coordinate()
		{
			x = 0;
			y = 0;
		}
		Coordinate(int _x, int _y)
		{
			x = _x;
			y = _y;
		}
  		Coordinate(const Coordinate &obj)
        {
          	x = obj.x;
            y = obj.y;
        }
	  	int getX(){
	  		return x;
	  	}
	  	int getY(){
	  		return y;
	  	}
	  	void setX(int _x){
	  		x = _x;
	  	}
	  	void setY(int _y){
	  		y = _y;
	  	}
	  	void showCoordInfo()
	  	{
	  		std::cout << "(" << x << ", " << y << ")\n"; 
	  	}
	private:
	  	int x, y;
};
