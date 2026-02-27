#pragma once
namespace E0
{
	class Vector
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
			Vector normalize(); 
			float magnitude(); 
			float getX(); 
			float getY(); 

			void operator=(const Vector& rhs); 
			Vector operator+(const Vector& rhs); 
			Vector operator-(const Vector& rhs); 
			bool  operator>(const Vector& rhs); 
			bool  operator<(const Vector& rhs); 
			bool  operator==(const Vector& rhs); 
			bool  operator>=(const Vector& rhs); 
			bool  operator<=(const Vector& rhs); 
	}; 
} 
