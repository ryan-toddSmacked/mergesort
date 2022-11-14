cmake_minimum_required(VERSION 3.1)

project(MSORT_ADT)


include(CheckSymbolExists)
check_symbol_exists(malloc "stdlib.h" HAVE_MALLOC)
check_symbol_exists(free "stdlib.h" HAVE_FREE)
check_symbol_exists(memcpy "string.h" HAVE_MEMCPY)


include(CheckCCompilerFlag)
check_c_compiler_flag(-std=c89 HAVE_C89)
check_c_compiler_flag(-std=c99 HAVE_C99)
check_c_compiler_flag(-std=c11 HAVE_C11)
check_c_compiler_flag(-O3 HAVE_OPT_LEVEL_3)


if (HAVE_C99)
    set(C_STD -std=c99)
elseif(HAVE_C11)
    set(C_STD -std=c11)
elseif(HAVE_C89)
    set(C_STD -std=c89)
else()
    message(FATAL_ERROR " Could not find working C-standard")
endif()


add_library(msort SHARED msort.c)

if (HAVE_OPT_LEVEL_3)
    target_compile_options(msort PUBLIC ${C_STD} -O3)
else()
    target_compile_options(msort PUBLIC ${C_STD})
endif()


