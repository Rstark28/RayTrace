#include "vec3.h"
#include <cmath>

/* vec3::vec3
 *
 * Constructs a vec3 object with the default components.
 *
 * Parameters:
 *      None
 *
 * Return:
 *      None
 */
vec3::vec3()
{
        e[0] = 0;
        e[1] = 0;
        e[2] = 0;
}

/* vec3::vec3
 *
 * Constructs a vec3 object with the given components.
 *
 * Parameters:
 *      e0 - The x component of the vector.
 *      e1 - The y component of the vector.
 *      e2 - The z component of the vector.
 *
 * Return:
 *      None
 */
vec3::vec3(double e0, double e1, double e2)
{
        e[0] = e0;
        e[1] = e1;
        e[2] = e2;
}

/* vec3::x
 *
 * Returns the x component of the vector.
 *
 * Parameters:
 *      None
 *
 * Return:
 *      The x component of the vector.
 */
double vec3::x() const
{
        return e[0];
}

/* vec3::y
 *
 * Returns the y component of the vector.
 *
 * Parameters:
 *      None
 *
 * Return:
 *      The y component of the vector.
 */
double vec3::y() const
{
        return e[1];
}

/* vec3::z
 *
 * Returns the z component of the vector.
 *
 * Parameters:
 *      None
 *
 * Return:
 *      The z component of the vector.
 */
double vec3::z() const
{
        return e[2];
}

/* vec3::operator[]
 *
 * Returns the value of the vector at the given index.
 *
 * Parameters:
 *      i - The index of the value to return.
 *
 * Return:
 *      The value of the vector at the given index.
 */
double vec3::operator[](int i) const
{
        return e[i];
}

/* vec3::operator[]
 *
 * Returns a reference to the value of the vector at the given index.
 *
 * Parameters:
 *      i - The index of the value to return.
 *
 * Return:
 *      A reference to the value of the vector at the given index.
 */
double &vec3::operator[](int i)
{
        return e[i];
}

/* vec3::operator-()
 *
 * Returns the negation of the vector.
 *
 * Parameters:
 *      None
 *
 * Return:
 *      The negation of the vector.
 */
vec3 vec3::operator-() const
{
        return vec3(-e[0], -e[1], -e[2]);
}

/* vec3::operator+=
 *
 * Adds the given vector to this vector.
 *
 * Parameters:
 *      v - The vector to add to this vector.
 *
 * Return:
 *      A reference to this vector.
 */
vec3 &vec3::operator+=(const vec3 &v)
{
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];

        return *this;
}

/* vec3::operator*=
 *
 * Multiplies this vector by the given scalar.
 *
 * Parameters:
 *      t - The scalar to multiply this vector by.
 *
 * Return:
 *      A reference to this vector.
 */
vec3 &vec3::operator*=(double t)
{
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;

        return *this;
}

/* vec3::operator/=
 *
 * Divides this vector by the given scalar.
 *
 * Parameters:
 *      t - The scalar to divide this vector by.
 *
 * Return:
 *      A reference to this vector.
 */
vec3 &vec3::operator/=(double t)
{
        return *this *= 1 / t;
}

/* vec3::length
 *
 * Returns the length of the vector.
 *
 * Parameters:
 *      None
 *
 * Return:
 *      The length of the vector.
 */
double vec3::length() const
{
        return std::sqrt(length_squared());
}

/* vec3::length_squared
 *
 * Returns the squared length of the vector.
 *
 * Parameters:
 *      None
 *
 * Return:
 *      The squared length of the vector.
 */
double vec3::length_squared() const
{
        return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

/* operator<<
 *
 * Writes the vector to the given output stream.
 *
 * Parameters:
 *      out - The output stream to write the vector to.
 *      v - The vector to write to the output stream.
 *
 * Return:
 *      The output stream.
 */
std::ostream &operator<<(std::ostream &out, const vec3 &v)
{
        return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

/* operator+
 *
 * Adds the two given vectors.
 *
 * Parameters:
 *      u - The first vector to add.
 *      v - The second vector to add.
 *
 * Return:
 *      The sum of the two vectors.
 */
vec3 operator+(const vec3 &u, const vec3 &v)
{
        return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

/* operator-
 *
 * Subtracts the second vector from the first vector.
 *
 * Parameters:
 *      u - The vector to subtract from.
 *      v - The vector to subtract.
 *
 * Return:
 *      The difference of the two vectors.
 */
vec3 operator-(const vec3 &u, const vec3 &v)
{
        return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

/* operator*
 *
 * Multiplies the two given vectors component-wise.
 *
 * Parameters:
 *      u - The first vector to multiply.
 *      v - The second vector to multiply.
 *
 * Return:
 *      The component-wise product of the two vectors.
 */
vec3 operator*(const vec3 &u, const vec3 &v)
{
        return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

/* operator*
 *
 * Multiplies the given vector by the given scalar.
 *
 * Parameters:
 *      t - The scalar to multiply the vector by.
 *      v - The vector to multiply.
 *
 * Return:
 *      The product of the vector and the scalar.
 */
vec3 operator*(double t, const vec3 &v)
{
        return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

/* operator*
 *
 * Multiplies the given vector by the given scalar.
 *
 * Parameters:
 *      v - The vector to multiply.
 *      t - The scalar to multiply the vector by.
 *
 * Return:
 *      The product of the vector and the scalar.
 */
vec3 operator*(const vec3 &v, double t)
{
        return t * v;
}

/* operator/
 *
 * Divides the given vector by the given scalar.
 *
 * Parameters:
 *      v - The vector to divide.
 *      t - The scalar to divide the vector by.
 *
 * Return:
 *      The quotient of the vector and the scalar.
 */
vec3 operator/(const vec3 &v, double t)
{
        return (1 / t) * v;
}

/* dot
 *
 * Returns the dot product of the two given vectors.
 *
 * Parameters:
 *      u - The first vector.
 *      v - The second vector.
 *
 * Return:
 *      The dot product of the two vectors.
 */
double dot(const vec3 &u, const vec3 &v)
{
        return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

/* cross
 *
 * Returns the cross product of the two given vectors.
 *
 * Parameters:
 *      u - The first vector.
 *      v - The second vector.
 *
 * Return:
 *      The cross product of the two vectors.
 */
vec3 cross(const vec3 &u, const vec3 &v)
{
        return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                    u.e[2] * v.e[0] - u.e[0] * v.e[2],
                    u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

/* unit_vector
 *
 * Returns the unit vector in the direction of the given vector.
 *
 * Parameters:
 *      v - The vector to normalize.
 *
 * Return:
 *      The unit vector in the direction of the given vector.
 */
vec3 unit_vector(const vec3 &v)
{
        return v / v.length();
}