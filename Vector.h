namespace E0
{
	struct Vector
	{
		private:
			float pos_x {};
			float pos_y {}; 

		public:
			Vector(); 
			Vector(float new_pos_x, float new_pos_y); 
			~Vector() = default; 
			void setXY(float new_pos_x, float new_pos_y); 
			void setX(float new_pos_x); 
			void setY(float new_pos_y); 
			float getX(); 
			float getY(); 
	}; 
} 
