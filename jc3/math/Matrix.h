#pragma once

namespace jc3
{
	struct Vector3f
	{
		float x, y, z;
	};
	
	template<typename T>
	class matrix
	{
	public:
		union {
			struct {
				T _11, _12, _13, _14;
				T _21, _22, _23, _24;
				T _31, _32, _33, _34;
				T _41, _42, _43, _44;
			};
			T m[4][4];
		};
	public:
		matrix()
		{
			Identity();
		}
		matrix(T m11, T m12, T m13, T m14,
			T m21, T m22, T m23, T m24,
			T m31, T m32, T m33, T m34,
			T m41, T m42, T m43, T m44)
		{
			_11 = m11; _12 = m12; _13 = m13; _14 = m14;
			_21 = m21; _22 = m22; _23 = m23; _24 = m24;
			_31 = m31; _32 = m32; _33 = m33; _34 = m34;
			_41 = m41; _42 = m42; _43 = m43; _44 = m44;
		}
		matrix operator* (const matrix& other)
		{
			matrix result;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					result.m[i][j] = m[i][0] * other.m[0][j] + m[i][1] * other.m[1][j] + m[i][2] * other.m[2][j] + m[i][3] * other.m[3][j];
				}
			}
			return result;
		}
		void Identity()
		{
			_11 = 1.0f;	_12 = 0.0f;	_13 = 0.0f; _14 = 0.0f;
			_21 = 0.0f;	_22 = 1.0f;	_23 = 0.0f; _14 = 0.0f;
			_31 = 0.0f;	_32 = 0.0f;	_33 = 1.0f; _14 = 0.0f;
			_41 = 0.0f;	_42 = 0.0f;	_43 = 0.0f; _14 = 1.0f;
		}
		Vector3f Right() { return Vector3f(_11, _12, _13); }
		Vector3f Forward() { return Vector3f(_21, _22, _23); }
		Vector3f Up() { return Vector3f(_31, _32, _33); }
		Vector3f Position() { return Vector3f(_41, _42, _43); }

		void SetRight(const Vector3f &vec)
		{
			_11 = vec.x();
			_12 = vec.y();
			_13 = vec.z();
			_14 = 0.0f;
		}
		void SetForward(const Vector3f &vec)
		{
			_21 = vec.x();
			_22 = vec.y();
			_23 = vec.z();
			_24 = 0.0f;
		}
		void SetUp(const Vector3f &vec)
		{
			_31 = vec.x();
			_32 = vec.y();
			_33 = vec.z();
			_34 = 0.0f;
		}
		void SetPosition(const Vector3f &vec)
		{
			_41 = vec.x();
			_42 = vec.y();
			_43 = vec.z();
			_44 = 1.0f;
		}

		const static matrix identity;
	};
	template<typename T>
	const matrix<T> matrix<T>::identity;
	using Matrix = matrix<float>;
}