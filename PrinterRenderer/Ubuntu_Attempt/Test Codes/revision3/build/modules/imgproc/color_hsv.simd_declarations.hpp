#define CV_CPU_SIMD_FILENAME "/home/ansh/Desktop/EC535/3DPrinterMonitor/PrinterRenderer/Ubuntu_Attempt/Test Codes/revision3/opencv-4.x/modules/imgproc/src/color_hsv.simd.hpp"
#define CV_CPU_DISPATCH_MODE SSE4_1
#include "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"

#define CV_CPU_DISPATCH_MODE AVX2
#include "opencv2/core/private/cv_cpu_include_simd_declarations.hpp"

#define CV_CPU_DISPATCH_MODES_ALL AVX2, SSE4_1, BASELINE

#undef CV_CPU_SIMD_FILENAME