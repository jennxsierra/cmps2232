cmake_minimum_required(VERSION 3.30)
project(cmps2232)

set(CMAKE_CXX_STANDARD 20)

# Function to add executables for all cpp files with main functions
function(add_subdir_executables base_dir)
    # Recursively find all .cpp files in the base directory
    file(GLOB_RECURSE MAIN_SOURCES "${base_dir}/**/*.cpp")
    foreach(SOURCE_FILE ${MAIN_SOURCES})
        # Check if the file contains the main function
        file(STRINGS ${SOURCE_FILE} CONTAINS_MAIN REGEX "^int main")
        if(CONTAINS_MAIN)
            # Generate a unique name based on the file path
            file(RELATIVE_PATH REL_PATH ${CMAKE_SOURCE_DIR} ${SOURCE_FILE})
            string(REPLACE "/" "_" TARGET_NAME ${REL_PATH})
            string(REPLACE ".cpp" "" TARGET_NAME ${TARGET_NAME})

            # Add an executable target for the main file
            add_executable(${TARGET_NAME} ${SOURCE_FILE})

            # Add all additional .cpp files from the src folder within the subdirectory (if it exists)
            get_filename_component(SOURCE_DIR ${SOURCE_FILE} DIRECTORY)

            # Include all .cpp files from src folder if exists
            file(GLOB ADDITIONAL_SOURCES "${SOURCE_DIR}/src/*.cpp")
            foreach(ADDITIONAL_SOURCE ${ADDITIONAL_SOURCES})
                file(STRINGS ${ADDITIONAL_SOURCE} OTHER_CONTAINS_MAIN REGEX "^int main")
                if(NOT OTHER_CONTAINS_MAIN)
                    target_sources(${TARGET_NAME} PRIVATE ${ADDITIONAL_SOURCE})
                endif()
            endforeach()

            # Also include other .cpp files in the same directory, excluding files with main functions
            file(GLOB ADDITIONAL_SOURCES_SAME_DIR "${SOURCE_DIR}/*.cpp")
            foreach(ADDITIONAL_SOURCE_SAME_DIR ${ADDITIONAL_SOURCES_SAME_DIR})
                file(STRINGS ${ADDITIONAL_SOURCE_SAME_DIR} OTHER_CONTAINS_MAIN REGEX "^int main")
                if(NOT OTHER_CONTAINS_MAIN)
                    target_sources(${TARGET_NAME} PRIVATE ${ADDITIONAL_SOURCE_SAME_DIR})
                endif()
            endforeach()

            # Add the directory to include directories for this target
            target_include_directories(${TARGET_NAME} PRIVATE ${SOURCE_DIR})
        endif()
    endforeach()
endfunction()

# Add all executables in top-level directories
add_subdir_executables(${CMAKE_SOURCE_DIR}/textbook)
add_subdir_executables(${CMAKE_SOURCE_DIR}/classwork)