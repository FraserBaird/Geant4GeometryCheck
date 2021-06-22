# set the project info
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(GeometryCheckTest)
# visualisation and ui control ------------
# this should activate all available UI and visualisation drivers
option(WITH_GEANT4_UIVIS "Build example with Geant4 UI and Vis drivers" ON)
if(WITH_GEANT4_UIVIS)
    find_package(Geant4 REQUIRED ui_all vis_all)
else()
    find_package(Geant4 REQUIRED)
endif()
# set up include directories and compiler definitions
include(${Geant4_USE_FILE})
include_directories(${PROJECT_SOURCE_DIR}/include)

# identify the sources and headers to be included
file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hh)
# sort out executable

set(GeometryCheck_GEOMS
        geometry/PhysNeutronSource.gdml
        )

set(GeometryCheck_MODULES
        geometry/gdml_modules/X2Source.gdml
        geometry/gdml_modules/NeutronTank.gdml
        geometry/gdml_modules/ModeratedDetector.gdml
        geometry/gdml_modules/N20Source.gdml
        geometry/gdml_modules/X2CandleStick.gdml
        geometry/gdml_modules/N20CandleStick.gdml
        )

set(GeometryCheck_SCRIPTS
        macros/init_vis.mac
        macros/vis.mac
        macros/init_gps.mac
        macros/experiment.mac
        )

foreach(_geom ${GeometryCheck_GEOMS})
    configure_file(
            ${PROJECT_SOURCE_DIR}/${_geom}
            ${PROJECT_BINARY_DIR}/${_geom}
            COPYONLY
    )
endforeach()

foreach(_module ${GeometryCheck_MODULES})
    configure_file(
            ${PROJECT_SOURCE_DIR}/${_module}
            ${PROJECT_BINARY_DIR}/${_module}
            COPYONLY
    )
endforeach()

foreach(_script ${GeometryCheck_SCRIPTS})
    configure_file(
            ${PROJECT_SOURCE_DIR}/${_script}
            ${PROJECT_BINARY_DIR}/${_script}
            COPYONLY
    )
endforeach()

add_executable(GeometryCheck GeometryCheck.cc ${sources} ${headers})
# link to geant4 libs
target_link_libraries(GeometryCheck ${Geant4_LIBRARIES})

# copy over the





#----------------------------------------------------------------------------
# For internal Geant4 use - but has no effect if you build this
# example standalone
#
add_custom_target(GeometryCheckTest DEPENDS GeometryCheck)




#----------------------------------------------------------------------------
# Install the executable to 'bin' directory under CMAKE_INSTALL_PREFIX
#
install(TARGETS GeometryCheck DESTINATION bin)
