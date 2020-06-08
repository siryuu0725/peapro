#ifndef VEC_H_
#define VEC_H_

struct Vec2
{
	/** Constructor */
	Vec2()
	{
		X = 0.0f;
		Y = 0.0f;
	}

	/**
	* @brief Constructor
	* @param[in] x ����
	* @param[in] y �c��
	*/
	Vec2(float x, float y)
	{
		X = x;
		Y = y;
	}



	float X;	//!< X�l
	float Y;	//!< Y�l
};



struct Vec3
{
	/** Constructor */
	Vec3()
	{
		X = 0.0f;
		Y = 0.0f;
		Z = 0.0f;
	}

	/**
	* @brief Constructor
	* @param[in] x ����
	* @param[in] y �c��
	*/
	Vec3(float x, float y, float z)
	{
		X = x;
		Y = y;
		Z = z;
	}



	float X;	//!< X�l
	float Y;	//!< Y�l
	float Z;	//!< Z�l
};


#endif


