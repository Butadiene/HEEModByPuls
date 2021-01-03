add_library(HeeModandGeoMagPuls
    SHARED
        coordinate_spec.cpp
        heembp_param.cpp
)

target_include_directories(HeeModandGeoMagPuls
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)