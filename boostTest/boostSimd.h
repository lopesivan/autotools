
#ifndef __BOOST_SIMD_TEST__
#define __BOOST_SIMD_TEST__

#include <vector>
#include <boost/simd/memory/allocator.hpp>

typedef float t_dataType;
typedef std::vector<t_dataType, boost::simd::allocator<t_dataType> > t_dataVector;

void setupMatrix( t_dataVector& matrix );
void printMatrix( const std::string& name, const t_dataVector& matrix, size_t width, size_t height );

void simpleTransform( t_dataVector& matrix, t_dataVector& factor );
void openMPTransform( t_dataVector& matrix, t_dataVector& factor );
void unrolledTransform( t_dataVector& matrix, t_dataVector& factor );
void unrolledOpenMPTransform( t_dataVector& matrix, t_dataVector& factor );

void simdTransform( t_dataVector& matrix, t_dataVector& factor );
void simdOpenMPTransform( t_dataVector& matrix, t_dataVector& factor );
void unrolledSimdTransform( t_dataVector& matrix, t_dataVector& factor );
void unrolledSimdOpenMPTransform( t_dataVector& matrix, t_dataVector& factor );


#endif // __BOOST_SIMD_TEST__
