add_library(HeeModandGeoMagPuls
    SHARED
        coordinate_spec.cpp
)

target_include_directories(HeeModandGeoMagPuls
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)