cmake_minimum_required (VERSION 2.6)
project (gslmuparser)

find_package(GSL REQUIRED)
include_directories(${GSL_INCLUDE_DIRS})
set(LIBS ${LIBS} ${GSL_LIBRARIES})

find_package(MuParser REQUIRED)
include_directories(${MUPARSER_INCLUDE_DIRS})
set(LIBS ${LIBS} ${MUPARSER_LIBRARIES})

add_library(gslmuparser mu.cpp mu_sf.cpp mu_math.cpp)
# target_link_libraries(gslmuparser ${LIBS})
install(TARGETS gslmuparser DESTINATION lib)
install(FILES gsl_mu.h DESTINATION include)
