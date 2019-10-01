#include <vector>
#include <iterator>
#include <iostream>
#include <iomanip>
#include <random>
#include <algorithm>
#include <functional>
#include <limits>

using namespace std;

template <typename T>
class Matrix
{
private:
   size_t mRows, mColumns, mSize;
public:
   vector<T> mData;
   Matrix()
       : mRows(0), mColumns(0), mSize(0)
   {
   }

   Matrix(const size_t &rows, const size_t &columns)
       : mRows(rows), mColumns(columns), mSize(columns * rows)
   {
      mData.reserve(mSize);
   }

   Matrix(const size_t &rows, const size_t &columns, const vector<T> &Data)
       : mRows(rows), mColumns(columns), mSize(columns * rows), mData(Data)
   {
   }

   Matrix(const Matrix &m)
   {
      // *this = m;
      mRows = m.rows();
      mColumns = m.columns();
      mSize = mRows * mColumns;
      mData = m.mData;
   }

   Matrix(Matrix &&m) noexcept
       : mRows(m.rows()),
         mColumns(m.columns())
   {
      mSize = mRows * mColumns;
      mData = m.getData();
   }

   ~Matrix() noexcept
   {
      mRows = 0;
      mColumns = 0;
      mSize = 0;
      mData.clear();
      mData.shrink_to_fit();
   }

   void randomize()
   {
      random_device r;
      seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()};
      mt19937_64 e2(seed2);
      if (is_same<T, int>::value)
      {
         uniform_int_distribution<> dist(0, 1);
         for (int i = 0; i < mSize; i++)
         {
            mData.push_back(dist(e2));
         }
      }
      else
      {
         uniform_real_distribution<double> dist(0, 1);
         for (int i = 0; i < mSize; i++)
         {
            mData.push_back(dist(e2));
         }
      }
   }

   void zeros()
   {
      for (int i = 0; i < mSize; i++)
      {
         mData.push_back(0);
      }
   }

   void insert(const T &val)
   {
      mData.push_back(val);
   }

   void resize(const size_t &s)
   {
      mData.resize(s);
   }

   void add(const T &val)
   {
      for (auto &x : mData)
      {
         x += val;
      }
   }

   void add(const Matrix &m)
   {
      transform(mData.begin(), mData.end(), m.mData.begin(), mData.begin(), plus<T>());
   }

   void subtrack(const Matrix &m)
   {
      transform(mData.begin(), mData.end(), m.mData.begin(), mData.begin(), minus<T>());
   }

   Matrix<T> subtrack(Matrix &a, Matrix &b)
   {
      Matrix<T> result(a.mRows, a.mColumns);
      result.resize(a.mRows * a.mColumns);
      transform(a.mData.begin(), a.mData.end(), b.mData.begin(), result.mData.begin(), minus<T>());
      return result;
   }
   T trace()
   {
      T tr = 0;
      if (mColumns == mRows)
      {
         for (int i = 0; i < mColumns; i++)
         {
            tr += ((*this)(i, i));
         }
         return tr;
      }
      else
      {
         return numeric_limits<T>::quiet_NaN();
         ;
      }
   }
   void transpose()
   {
      vector<T> tempv;
      for (int i = 0; i < mColumns; i++)
      {
         for (int j = 0; j < mRows; j++)
         {
            tempv.push_back((*this)(j, i));
         }
      }
      swap(mColumns, mRows);
      mData.clear();
      mData = tempv;
   }

   Matrix transpose(const Matrix &m)
   {
      Matrix<T> temp(m);
      temp.transpose();
      return temp;
   }

   void map(function<T(T &)> &f)
   {
      for (auto &data : mData)
      {
         data = f(data);
      }
   }

   Matrix map(const Matrix &m, function<T(T &)> &f)
   {
      Matrix<T> result(m.rows(), m.columns());
      result.resize(m.rows() * m.columns());
      result = m;
      result.map(f);
      return result;
   }

   Matrix copy()
   {
      return *this;
   }

   void copy(const Matrix &m)
   {
      mRows = m.mRows;
      mColumns = m.mColumns;
      mSize = m.mSize;
      mData.clear();
      mData = m.mData;
   }

   void multiply(const T &val)
   {
      for (auto &x : mData)
      {
         x *= val;
      }
   }

   Matrix multiply(const Matrix &a, const Matrix &b)
   {

      Matrix<T> result(a.mRows, b.mColumns);
      result.resize(a.mRows * b.mColumns);
      for (int i = 0; i < a.rows(); i++)
      {
         for (int j = 0; j < b.columns(); j++)
         {
            for (int k = 0; k < a.columns(); k++)
            {
               result(i, j) += a(i, k) * b(k, j);
            }
         }
      }
      return result;
   }

   Matrix multiply(Matrix b)
   {
      Matrix<T> result(this->rows(), b.columns());
      result.resize(this->rows() * b.columns());
      for (int i = 0; i < this->rows(); i++)
      {
         for (int j = 0; j < b.columns(); j++)
         {
            for (int k = 0; k < this->columns(); k++)
            {
               result(i, j) += (*this)(i, k) * b(k, j);
            }
         }
      }
      return result;
   }

   void fromVector(vector<T> &vec)
   {
      mRows = vec.size();
      mColumns = 1;
      mSize = mRows;
      mData = vec;
   }

   vector<T> getData()
   {
      return mData;
   }

   void print() const
   {
      for (int i = 0; i < mRows; i++)
      {
         for (int j = 0; j < mColumns; j++)
         {
            cout << setw(11) << (*this)(i, j) << setw(11);
         }
         cout << "\n";
      }
      cout << "------------------------------------------------------------------------------ \n";
   }

   size_t rows() const
   {
      return mRows;
   }

   size_t columns() const
   {
      return mColumns;
   }
   size_t getSize() const
   {
      return mData.size();
   }

   T operator[](size_t i) const
   {
      return mData.at(i);
   }

   T &operator()(size_t i, size_t j)
   {
      return mData.at(j + i * mColumns);
   }

   const T &operator()(size_t i, size_t j) const
   {
      return mData.at(j + i * mColumns);
   }

   void operator=(Matrix<T> &&other)
   {
      mData = move(other.mData);
   }

   Matrix operator=(const Matrix &x)
   {
      if (this == &x)
      {
         return *this;
      }

      mData.resize(x.mSize);
      mData = x.mData;

      Matrix<T> result(mRows, mColumns);
      result.mData = this->mData;
      return result;
   }

   Matrix &operator+=(Matrix &x)
   {

      transform(mData.begin(), mData.end(), x.mData.begin(), mData.begin(), plus<T>());

      return *this;
   }

   Matrix &operator+(const Matrix &x)
   {
      if (mSize != x.getSize())
      {
         cout << "Wrong Matrix size!"
              << "\n";
         return *this;
      }
      transform(mData.begin(), mData.end(), x.mData.begin(), mData.begin(), plus<T>());

      return Matrix<T>(mRows, mColumns, mData);
   }
};

int main()
{
   Matrix<int> matrix(4, 4);
   // matrix.zeros();
   matrix.randomize(); // randomize not working for all types
   matrix.print();
   cout << "Trace :" << matrix.trace() << '\n';

   return 0;
}
