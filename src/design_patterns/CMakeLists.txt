# Sources and Headers
set(DESIGN_PATTERNS_LIBRARY_SOURCES
"${CMAKE_CURRENT_SOURCE_DIR}/BuilderPattern/BuilderFacets/Facets.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/BuilderPattern/BuilderFacets/Person.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/BuilderPattern/BuilderFacets/PersonBuilder.cpp"
)
set(DESIGN_PATTERNS_LIBRARY_HEADERS
    "${CMAKE_CURRENT_SOURCE_DIR}/SOLID/SingleResponsibilityPrinciple/FollowingSRP.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SOLID/OpenClosedPrinciple/FollowingOCP.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SOLID/LiskovSubstitutionPrinciple/FollowingLSP.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SOLID/InterfaceSegregationPrinciple/FollowingISP.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/SOLID/DependencyInversionPrinciple/FollowingDIP.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/BuilderPattern/FluentBuilder.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/BuilderPattern/BuilderFacets/Person.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/BuilderPattern/BuilderFacets/PersonBuilder.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/BuilderPattern/BuilderFacets/PersonJobBuilder.hpp"
    "${CMAKE_CURRENT_SOURCE_DIR}/BuilderPattern/BuilderFacets/PersonAddressBuilder.hpp"
)
set(DESIGN_PATTERNS_LIBRARY_INCLUDES "./" "${CMAKE_BINARY_DIR}/configured_files/include")

# MyLib Library
add_library(${DESIGN_PATTERNS_LIBRARY_NAME} STATIC ${DESIGN_PATTERNS_LIBRARY_SOURCES} ${DESIGN_PATTERNS_LIBRARY_HEADERS})
target_include_directories(${DESIGN_PATTERNS_LIBRARY_NAME} PUBLIC ${DESIGN_PATTERNS_LIBRARY_INCLUDES})
target_link_libraries(
    ${DESIGN_PATTERNS_LIBRARY_NAME}
    PRIVATE nlohmann_json::nlohmann_json
            fmt::fmt
            spdlog::spdlog
            cxxopts::cxxopts)

if(${ENABLE_WARNINGS})
    target_set_warnings(
        TARGET
        ${DESIGN_PATTERNS_LIBRARY_NAME}
        ENABLE
        ${ENABLE_WARNINGS}
        AS_ERRORS
        ${ENABLE_WARNINGS_AS_ERRORS})
endif()

if(${ENABLE_LTO})
    target_enable_lto(
        TARGET
        ${DESIGN_PATTERNS_LIBRARY_NAME}
        ENABLE
        ON)
endif()

if(${ENABLE_CLANG_TIDY})
    add_clang_tidy_to_target(${DESIGN_PATTERNS_LIBRARY_NAME})
endif()
