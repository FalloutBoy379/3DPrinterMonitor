#define CV_CPU_SIMD_FILENAME "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x/modules/core/test/test_intrin256.simd.hpp"
#define CV_CPU_DISPATCH_MODE AVX2
#include "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"

#define CV_CPU_DISPATCH_MODE AVX512_SKX
#include "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"

#define CV_CPU_DISPATCH_MODE LASX
#include "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"

#define CV_CPU_DISPATCH_MODES_ALL LASX, AVX512_SKX, AVX2, BASELINE

#undef CV_CPU_SIMD_FILENAME