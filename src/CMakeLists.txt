cmake_minimum_required( VERSION 3.10 )
project( mapred_reduce VERSION 0.1.1 )
add_executable( mapper mapper.cpp )
add_executable( avg_reducer avg_reducer.cpp )
add_executable( disp_reducer disp_reducer.cpp )

file( COPY ../input/AB_NYC_2019.csv DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )
file( COPY test_avg.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )
file( COPY test_disp.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )
file( COPY test_mapper.sh DESTINATION ${CMAKE_CURRENT_BINARY_DIR} )

# package part which enales
# run: cmake --build . --target package
install(TARGETS mapper avg_reducer disp_reducer RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PATCH_VERSION}")
set(CPACK_PACKAGE_CONTACT berrendej@gmail.com)
include(CPack)
