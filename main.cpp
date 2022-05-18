#include <iostream>

#include <boost/multiprecision/gmp.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>
#include <boost/multiprecision/float128.hpp>
#include <func.h>
#include <chrono>
#include <cmath>
#include <quadmath.h>

using boost::multiprecision::cpp_dec_float_50;
using boost::multiprecision::cpp_dec_float_100;
using boost::multiprecision::cpp_bin_float_quad;
using boost::multiprecision::mpf_float_50;
using boost::multiprecision::mpf_float_100;
using boost::multiprecision::mpf_float_1000;
using boost::multiprecision::float128;


const int REPS {10000};

int main(int, char**)
{
   float r_f(float(123) / 100);
   double r_d(double(123) / 100);
   cpp_dec_float_50 r_mp(cpp_dec_float_50(123) / 100);
   cpp_dec_float_100 r_quad(cpp_dec_float_100(123) / 100);
   cpp_bin_float_quad r_fquad(cpp_bin_float_quad(123) / 100);

   mpf_float_50 r_mpf50(mpf_float_50(123) / 100);
   mpf_float_100 r_mpf100(mpf_float_100(123) / 100);
   mpf_float_1000 r_mpf1000(mpf_float_1000(123) / 100);
   float128 r_float128(float128(123) / 100);

   float a_f;
   double a_d;
   cpp_dec_float_50 a_mp;
   cpp_dec_float_100 a_quad;
   cpp_bin_float_quad a_fquad;
   mpf_float_50 a_mpf50;
   mpf_float_100 a_mpf100;
   mpf_float_1000 a_mpf1000;
   float128 a_float128;

   auto inizio = std::chrono::high_resolution_clock::now();
   for (int i=0; i<REPS; i++) {
     a_f += log(area_of_a_circle(r_f));
     // r_f += (a_f / 100);
   }

   auto fine = std::chrono::high_resolution_clock::now();
   auto tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fine - inizio).count();

   std::cout
       << std::setprecision(std::numeric_limits<float>::digits10)
       << "[float] Durata " << REPS << " ops: "<< tempo << "ms.\nRes = "
       << a_f << std::endl;
   std::cout.flush();

   // Double
   inizio = std::chrono::high_resolution_clock::now();
   for (int i=0; i<REPS; i++) {
     a_d += log(area_of_a_circle(r_d));
     //r_d += (a_d / 100);
    }

   fine = std::chrono::high_resolution_clock::now();
   tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fine - inizio).count();

   std::cout
       << std::setprecision(std::numeric_limits<double>::digits10)
       << "[double]  sizeof [" << sizeof(a_d)
       << "] Durata " << REPS << " ops: "<< tempo << "ms.\nRes = "
       << a_d << std::endl;
   std::cout.flush();

   // dec_50
   inizio = std::chrono::high_resolution_clock::now();
   for (int i=0; i<REPS; i++) {
     a_mp += log(area_of_a_circle(r_mp));
     //r_mp += (a_mp / 100);
   }

   fine = std::chrono::high_resolution_clock::now();
   tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fine - inizio).count();

   std::cout
       << std::setprecision(std::numeric_limits<cpp_dec_float_50>::digits10)
       << "[dec_float_50]  sizeof [" << sizeof(a_mp)
       << "] Durata " << REPS << " ops: " << tempo << "ms.\nRes = "
       << a_mp << std::endl;
   std::cout.flush();

   // dec_100
   inizio = std::chrono::high_resolution_clock::now();
   for (int i=0; i<REPS; i++) {
     a_quad += log(area_of_a_circle(r_quad));
     // r_quad += (a_quad / 100);
   }

   fine = std::chrono::high_resolution_clock::now();
   tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fine - inizio).count();

   std::cout
        << std::setprecision(std::numeric_limits<cpp_dec_float_100>::digits10)
        << "[dec_float_100] Durata " << REPS << " ops: " << tempo << "ms.\nRes = "
        << a_quad << std::endl;
   std::cout.flush();

   // dec_100
   inizio = std::chrono::high_resolution_clock::now();
   for (int i=0; i<REPS; i++) {
     a_fquad += log(area_of_a_circle(r_fquad));
     // r_quad += (a_quad / 100);
   }

   fine = std::chrono::high_resolution_clock::now();
   tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fine - inizio).count();

   std::cout
        << std::setprecision(std::numeric_limits<cpp_bin_float_quad>::digits10)
        << "[bin_float_quad] sizeof [" << sizeof(a_fquad)
        << "] Durata " << REPS << " ops: " << tempo << "ms.\nRes = "
        << a_fquad << std::endl;
   std::cout.flush();

   // mpf50
   inizio = std::chrono::high_resolution_clock::now();
   for (int i=0; i<REPS; i++) {
     a_mpf50 += log(area_of_a_circle(r_mpf50));
     // r_quad += (a_quad / 100);
   }

   fine = std::chrono::high_resolution_clock::now();
   tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fine - inizio).count();

   std::cout
        << std::setprecision(std::numeric_limits<mpf_float_50>::digits10)
        << "[mpf50]  sizeof [" << sizeof(a_mpf50)
        << "] Durata " << REPS << " mpf50: "<< tempo << "ms.\nRes = "
        << a_quad << std::endl;
   std::cout.flush();

   // mpf100
   inizio = std::chrono::high_resolution_clock::now();
   for (int i=0; i<REPS; i++) {
     a_mpf100 += log(area_of_a_circle(r_mpf100));
     // r_quad += (a_quad / 100);
   }

   fine = std::chrono::high_resolution_clock::now();
   tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fine - inizio).count();

   std::cout
        << std::setprecision(std::numeric_limits<mpf_float_100>::digits10)
        << "[mpf100] Durata " << REPS << " mpf100: "<< tempo << "ms.\nRes = "
        << a_quad << std::endl;
   std::cout.flush();

   // mpf1000
   inizio = std::chrono::high_resolution_clock::now();
   for (int i=0; i<REPS; i++) {
     a_mpf1000 += log(area_of_a_circle(r_mpf1000));
     // r_quad += (a_quad / 100);
   }

   fine = std::chrono::high_resolution_clock::now();
   tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fine - inizio).count();

   std::cout
        << std::setprecision(std::numeric_limits<mpf_float_1000>::digits10)
        << "[mpf1000] Durata " << REPS << " mpf1000: "<< tempo << "ms.\nRes = "
        << a_quad << std::endl;
   std::cout.flush();

   // float128
   inizio = std::chrono::high_resolution_clock::now();
   for (int i=0; i<REPS; i++) {
     a_float128 += log(area_of_a_circle(r_float128));
     // r_quad += (a_quad / 100);
   }

   fine = std::chrono::high_resolution_clock::now();
   tempo = std::chrono::duration_cast<std::chrono::milliseconds>(fine - inizio).count();

   std::cout
        << std::setprecision(std::numeric_limits<float128>::digits10)
        << "[float128]  sizeof [" << sizeof(a_float128)
        << "] Durata " << REPS << " ops: "<< tempo << "ms.\nRes = "
        << a_float128 << std::endl;
   std::cout.flush();

}
