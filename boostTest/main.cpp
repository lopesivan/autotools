
#include "boostSimd.h"
#include <iostream>
#include <iomanip>
#include <boost/timer/timer.hpp>

int main()
{
    size_t width = 500; // Coloque sempre n�meros m�ltiplos de 4
    size_t height = width; // Testei somente com matrizes quadradas

    size_t loopCount = 50;

    struct Executions
    {
        std::string name_;
        void (*transform_)( t_dataVector& matrix, t_dataVector& factor );
    };

    Executions exec[] = {
    { "Base",                       &simpleTransform },
    { "Unrolled",                   &unrolledTransform },
    { "OpenMP",                     &openMPTransform },
    { "OpenMP unrolled",            &unrolledOpenMPTransform },
    { "Boost.SIMD",                 &simdTransform },
    { "Boost.SIMD unrolled",        &unrolledSimdTransform },
    { "Boost.SIMD OpenMP",          &simdOpenMPTransform },
    { "Boost.SIMD OpenMP unrolled", &unrolledSimdOpenMPTransform },
    { "", NULL } };

    t_dataVector baseMatrix( width * height );
    t_dataVector baseFactor( width );

    boost::timer::cpu_timer timer;

    srand( time(NULL) ); // Para depurar � melhor colocar uma constante aqui, vai ser sempre a mesma matriz
    setupMatrix( baseMatrix );
    setupMatrix( baseFactor );

    printMatrix( "Matriz", baseMatrix, width, height );
    printMatrix( "Fatores", baseFactor, width, 1 );

    size_t index = 0;
    while( exec[index].transform_ )
    {
        t_dataVector matrix( baseMatrix );
        t_dataVector factor( baseFactor );

        // Warmup (arruma o cache, carrega OpenMP, etc).
        exec[index].transform_( matrix, factor );

        timer.start();
        for(size_t i = 0; i < loopCount; ++i )
        {
            exec[index].transform_( matrix, factor );
        }
        timer.stop();
        printMatrix( "Matriz", matrix, width, height );
        printMatrix( "Fatores", factor, width, 1 );

        double seconds = static_cast<double>(timer.elapsed().wall) / 1000000000.0;
        double timePerMatrix = seconds / loopCount;
        double kflops = static_cast<double>(width*(width + 2) + 2 * width)/ 1000.0 / seconds ;

        std::cout << exec[index].name_ << " time: " << timer.format( boost::timer::default_places, "%ws wall, %us user + %ss system = %ts CPU (%p%)" )
                  << " - Time per Matrix: " << std::fixed << std::setprecision(6) << timePerMatrix << "s"
                  << " - " << std::fixed << std::setprecision(2) << kflops << " kflops"
                  << std::endl << std::endl;

        ++index;
    }
    return 0;
}
